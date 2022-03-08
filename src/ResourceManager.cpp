#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::ResourceManager(ResourceManager const&)
{
  
}

ResourceManager ResourceManager::operator=(ResourceManager const&)
{
    //TODO: although we do not need this for a singleton
    return *this;
}

ResourceManager& ResourceManager::GetInstance()
{
    static ResourceManager* s_instance = new ResourceManager;

    return *s_instance;
}

SDL_Surface* ResourceManager::GetSurface(std::string filepath)
{
    // We will look through our m_surfacesMap, which is 'unordered_map'
    // and see if a file exists. If it exists then return the 
    // associated surface. If it doesn't exist we load it.

    auto search = m_surfacesMap.find(filepath);

    if(search != m_surfacesMap.end())
    {
        return m_surfacesMap[filepath];
    }
    else
    {
        SDL_Surface* surface = IMG_Load(filepath.c_str());
        return surface;
    }   
    
    return nullptr;
}
