#include "game.h"

Game::Game() 
{
    window = nullptr;
    renderer = nullptr;
    screenWidth = 1024;
    screenHeight = 600;
    isFullScreen = false;
    gameState = GameState::PLAY;
}

Game::~Game() {}

void Game::run() 
{
    init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    gameLoop();
}

void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags) 
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void Game::gameLoop() 
{
    while (gameState != GameState::EXIT) 
    {
        handleEvents();
    }
}

void Game::handleEvents() 
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