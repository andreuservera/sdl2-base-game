#include "Bitmap.h"
#include "ResourceManager.h"

Bitmap::Bitmap(std::string filepath, SDL_Renderer* renderer)
{
    m_texture = LoadTexture(filepath, renderer);
    
    // Set original size to m_srcRect
    SDL_QueryTexture(m_texture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);

    m_srcRect.x = 0;
    m_srcRect.y = 0;

    m_destRect = m_srcRect;
}

Bitmap::~Bitmap()
{

}

SDL_Texture* Bitmap::LoadTexture(std::string filepath, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = ResourceManager::GetInstance().GetSurface(filepath);
    
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(newTexture == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(loadedSurface);


    return newTexture;
}

SDL_Texture* Bitmap::GetTexture()
{
    return m_texture;
}

void Bitmap::SetPosition(int x, int y)
{
    m_destRect.x = x;
    m_destRect.y = y;
}

void Bitmap::SetDimensions(int w, int h)
{
    m_destRect.w = w;
    m_destRect.h = h;
}

void Bitmap::SetSourcePosition(int x, int y)
{
    m_srcRect.x = x;
    m_srcRect.y = y;
}

void Bitmap::SetSourceDimensions(int w, int h)
{
    m_srcRect.w = w;
    m_srcRect.h = h;
}

SDL_Rect Bitmap::GetRect()
{
    return m_destRect;
}
