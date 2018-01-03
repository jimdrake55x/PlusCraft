#include "Playing_State.h"
#include <iostream>
#include "../Shader/Simple_Shader.h"

std::vector<GLfloat> vertexPositions =
{
     0.5,0.5,
     -0.5,0.5,
     -0.5,-0.5,
     0.5,-0.5,
};

std::vector<GLfloat> textureCoordinates =
{
    1.0,1.0,
    0.0,1.0,
    0.0,0.0,
    1.0,0.0,
};

std::vector<GLuint> indices =
{
    0,1,2,
    2,3,0
};

namespace State
{
    Playing::Playing(Application& application)
    :  Game_State(application)
    ,  m_model  (vertexPositions,textureCoordinates,indices)
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

        glDrawElements(GL_TRIANGLES,m_model.getIndicesCount(),GL_UNSIGNED_INT,nullptr);

        m_texture.unbind();
        m_model.unbind();
        m_shader.unbind();
    }
}
