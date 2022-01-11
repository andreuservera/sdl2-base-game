#include "game.h"

Game::Game() 
{
    window = nullptr;
    renderer = nullptr;
    screenWidth = 1024;
    screenHeight = 600;
    isFullScreen = false;
    gameState = GameState::PLAY;

    sprite = NULL;
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
    
    renderer = SDL_CreateRenderer(window, -1, 0);
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
//    SDL_DisplayMode dm;
//    if(SDL_GetDesktopDisplayMode(0, &dm) != 0)
//    {
//        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
//        return 1;
//    }
//    
//    if()
    if(isFullScreen)
    {
        SDL_SetWindowFullscreen(window, 0);
        SDL_SetWindowSize(window, screenWidth, screenHeight);
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
    else
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN); 
    }

    isFullScreen = !isFullScreen;
}

SDL_Texture* Game::LoadTexture(std::string path)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return NULL;
    }
    
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(newTexture == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(loadedSurface);

    return newTexture;
}

void Game::LoadResources()
{
    sprite = LoadTexture("..resources/sprite.png");
    if(sprite == NULL)
    {
        printf("Failed to load image!\n");
        return;
    }
}

void Game::RenderGame()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, sprite, NULL, NULL);
    SDL_RenderPresent(renderer);
}