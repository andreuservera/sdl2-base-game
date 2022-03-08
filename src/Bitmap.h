#pragma once

#include "SDL2/SDL.h"
#include "string"

class Bitmap
{
    public:
        Bitmap(std::string filepath, SDL_Renderer* renderer);
        ~Bitmap();
        
        SDL_Texture* GetTexture();

        void SetPosition(int x, int y);
        void SetDimensions(int w, int h);
        void SetSourcePosition(int x, int y);
        void SetSourceDimensions(int w, int h);

        SDL_Rect GetRect();
    private:
        SDL_Texture* m_texture;

        SDL_Rect m_srcRect;
        SDL_Rect m_destRect;

        SDL_Texture* LoadTexture(std::string filepath, SDL_Renderer* renderer);
};
