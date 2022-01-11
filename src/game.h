#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum class GameState {PLAY, EXIT};

class Game {
    public:
        Game();
        ~Game();

        void Run();

    private:
        bool Init(const char* title, int x, int y, int w, int h, Uint32 flags);
        void GameLoop();
        void HandleEvents();

        SDL_Window* window;
        SDL_Renderer* renderer;

        int screenWidth;
        int screenHeight;
        bool isFullScreen;

        GameState gameState;

        void ToggleFullScreen();
        void RenderGame();
        void LoadResources();

        SDL_Texture* LoadTexture(std::string path);

        SDL_Texture* sprite;
};