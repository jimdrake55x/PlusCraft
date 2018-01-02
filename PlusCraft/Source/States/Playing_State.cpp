#include "Playing_State.h"
#include <iostream>
#include "../Shader/Simple_Shader.h"

std::vector<GLfloat> vertexPositions =
{
     0.5,0.5,
     -0.5,0.5,
     -0.5,-0.5,
     -0.5,-0.5,
     0.5,-0.5,
     0.5,0.5
};

std::vector<GLfloat> textureCoordinates =
{
    1.0,1.0,
    0.0,1.0,
    0.0,0.0,
    0.0,0.0,
    1.0,0.0,
    1.0,1.0
};

namespace State
{
    Playing::Playing(Application& application)
    :  Game_State(application)
    ,  m_model  (vertexPositions,textureCoordinates)
    {
        m_texture.load("grass");
    }

    void Playing::input()
    {

    }

    void Playing::update()
    {

    }

    void Playing::draw()
    {
        m_shader.bind();
        m_model.bind();
        m_texture.bind();

        glDrawArrays(GL_TRIANGLES,0,6);

        m_texture.unbind();
        m_model.unbind();
        m_shader.unbind();
    }
}
