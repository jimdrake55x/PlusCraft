#include "Playing_State.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include "../Renderer/Master.h"


namespace State
{
    sf::Clock clock;
    Playing::Playing(Application& application)
    :  Game_State(application)
    {
        m_texture.load("grass");
        m_texture.bind();

        auto si = 50;
        for(int j = -si; j < si ;j++)
        {
            for(int i = 0; i > -si; i--)
            {
                Quad* quad = new Quad();
                quad->rotation.x = 90;
                quad->position = {i,-1,j};
                m_quads.push_back(*quad);
            }
        }
        for(int i = 0; i > -si; i--)
        {

        }
        //m_quad.position.z = -3;
        //m_quad.rotation.x = 90;

    }

    void Playing::input(Entity& camera)
    {

    }

    void Playing::update(Entity& camera)
    {
        //m_quad.position.x = sin(clock.getElapsedTime().asSeconds());
        //m_quad.position.y = sin(clock.getElapsedTime().asSeconds());
        camera.position.z -= 0.1;
    }

    void Playing::draw(Renderer::Master& renderer)
    {
        for(auto& quad : m_quads)
        {
            renderer.draw(quad);
        }
        //renderer.draw(m_quad);
    }
}
