#include "SPlaying.h"

#include <SFML/System/Clock.hpp>

#include "../World/Block/Block_Database.h"
#include "../Renderer/RMaster.h"
#include "../Camera.h"
#include "../Application.h"

namespace State
{
    sf::Clock clock;

    Playing::Playing(Application& application)
    :   Game_State  (application)
    ,   m_world     (application.getCamera(), m_player)
    { }

    void Playing::input(Camera& camera)
    {
        m_player.addForce(camera.getVelocity());
        m_player.rotation   = camera    .rotation;
        camera  .position   = m_player  .position;

        m_world.input(camera);
        camera.input();
    }

    void Playing::update(Camera& camera, float dt)
    {
        camera.update(dt);
        m_player.update(dt);
        m_world.update(dt);
    }

    void Playing::draw(Renderer::Master& renderer)
    {
        m_world     .draw(renderer);
        m_vignette  .draw(renderer);
        m_crosshair .draw(renderer);
    }
}
