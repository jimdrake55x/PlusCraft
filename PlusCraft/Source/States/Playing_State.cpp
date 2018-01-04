#include "Playing_State.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include "../Renderer/Master.h"

#include "../Camera.h"

namespace State
{
    sf::Clock clock;
    Playing::Playing(Application& application)
    :  Game_State(application)
    {
        m_texture.load("grass");
        m_texture.bind();

        m_quad.position.z = -3;
        //m_quad.rotation.x = 90;

    }

    void Playing::input(Camera& camera)
    {

    }

    void Playing::update(Camera& camera, float deltaTime)
    {
        camera.input(deltaTime);
       // m_quad.position.x = sin(clock.getElapsedTime().asSeconds());
       // m_quad.position.y = sin(clock.getElapsedTime().asSeconds());
        //camera.position.z -= 0.01;
    }

    void Playing::draw(Renderer::Master& renderer)
    {

        renderer.draw(m_quad);
    }
}
