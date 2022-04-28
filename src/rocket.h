#pragma once

#include <memory>
#include "ResourceManager.h"
#include "Bitmap.h"

class Rocket
{
    public:
        Rocket(SDL_Renderer* renderer, int pos_x, int pos_y);
        ~Rocket();

        void Update();
        void HandleEvents();
        void Render(SDL_Renderer* renderer);

        void SetPosition(int x, int y);
        
    private:
        int m_pos_x;
        int m_pos_y;

        float m_vel_x;
        float m_vel_y;

        float m_accel_x;
        float m_accel_y;

        uint32_t mLastUpdate;

        #ifdef __linux__
        std::string filepath = "../resources/sprite.png";
        #elif _WIN32
        std::string filepath = "resources\\sprite.png";
        #endif

        std::shared_ptr<Bitmap> sprite;
};
