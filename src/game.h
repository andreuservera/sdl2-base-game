#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Bitmap.h"
#include "rocket.h"

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
        void PhysicsLoop();

        SDL_Window* window;
        SDL_Renderer* renderer;

        int screenWidth;
        int screenHeight;
        bool isFullScreen;

        GameState gameState;

        void ToggleFullScreen();
        void RenderGame();
        void LoadResources();

        std::unique_ptr<Bitmap> sprite;
        std::vector<Rocket> rockets;
};
