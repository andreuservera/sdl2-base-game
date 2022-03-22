#include "rocket.h"

Rocket::Rocket(SDL_Renderer* renderer, int pos_x, int pos_y) :
    m_pos_x{pos_x},
    m_pos_y{pos_y}
{
    mLastUpdate = SDL_GetTicks();

    sprite.reset(new Bitmap(filepath, renderer));
    sprite->SetDimensions(50, 50);
}

Rocket::~Rocket()
{
}

void Rocket::Update()
{
    uint32_t time = SDL_GetTicks();
    float dT = (time - mLastUpdate) / 1000.0f;

    m_pos_x += m_vel_x * dT;
    m_pos_y += m_vel_y * dT;
}

void Rocket::HandleEvents()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if(keystate[SDL_SCANCODE_LEFT])
    {
        m_vel_x -= m_accel_x;
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
        m_vel_x += m_accel_x;
    }
    if(keystate[SDL_SCANCODE_UP])
    {
        m_vel_y -= m_accel_y;
    }
    if(keystate[SDL_SCANCODE_DOWN])
    {
        m_vel_y += m_accel_y;
    }
}

void Rocket::Render(SDL_Renderer* renderer)
{
    SDL_Rect dstrect = sprite->GetRect();

    sprite->SetPosition(m_pos_x, m_pos_y);

    SDL_RenderCopy(renderer, sprite->GetTexture(), NULL, &dstrect);
}
