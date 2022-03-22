#include "game.h"
#include "ResourceManager.h"

const int SCREEN_WIDTH_SMALL = 1024;
const int SCREEN_HEIGHT_SMALL = 600;

Game::Game() 
{
    window = nullptr;
    renderer = nullptr;
    screenWidth = SCREEN_WIDTH_SMALL;
    screenHeight = SCREEN_HEIGHT_SMALL;
    isFullScreen = false;
    gameState = GameState::PLAY;
}

Game::~Game() {}

void Game::Run() 
{
    Init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    GameLoop();
}

bool Game::Init(const char* title, int x, int y, int w, int h, Uint32 flags) 
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    if(window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if( !(IMG_Init(imgFlags) & imgFlags) )
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    LoadResources();
    return true;
}

void Game::GameLoop() 
{
    while (gameState != GameState::EXIT) 
    {
        HandleEvents();
        RenderGame();
    }
}

void Game::HandleEvents() 
{
    SDL_Event sdl_event;
    SDL_PollEvent(&sdl_event);

    switch (sdl_event.type) 
    {
        case SDL_QUIT:
            gameState = GameState::EXIT;
            break;

        case SDL_KEYDOWN:
            switch (sdl_event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    gameState = GameState::EXIT;
                    break;
                case SDLK_F11:
                    ToggleFullScreen();
                    break;
            }
    }    
}

void Game::ToggleFullScreen()
{
    if(isFullScreen)
    {
        screenWidth = SCREEN_WIDTH_SMALL;
        screenHeight = SCREEN_HEIGHT_SMALL;

        SDL_SetWindowFullscreen(window, 0);
        SDL_SetWindowSize(window, screenWidth, screenHeight);
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
    else
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP); 
        SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    }

    isFullScreen = !isFullScreen;
}

void Game::LoadResources()
{
    std::string filepath = "../resources/sprite.png";
    sprite.reset(new Bitmap(filepath, renderer));
}

void Game::RenderGame()
{
    SDL_Rect dstrect = sprite->GetRect();

    //sprite->SetDimensions(50, 50);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, sprite->GetTexture(), NULL, &dstrect);
    SDL_RenderPresent(renderer);

    sprite->SetPosition(sprite->GetRect().x+1, 0);
}
