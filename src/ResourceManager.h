#pragma once

// https://www.youtube.com/watch?v=_DGIRmHUtwQ

#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ResourceManager
{
  private:
    ResourceManager();
    ResourceManager(ResourceManager const&);
    ResourceManager operator=(ResourceManager const&);

    std::unordered_map<std::string, SDL_Surface*> m_surfacesMap;

  public:
    static ResourceManager& GetInstance();

    SDL_Surface* GetSurface(std::string filepath);


};
