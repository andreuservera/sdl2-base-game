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
        
    private:
        int m_pos_x;
        int m_pos_y;

        int m_vel_x;
        int m_vel_y;

        int m_accel_x;
        int m_accel_y;

        uint32_t mLastUpdate;

        std::string filepath = "../resource/sprite.png";
        std::unique_ptr<Bitmap> sprite;
};
