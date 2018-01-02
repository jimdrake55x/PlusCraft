#include "Playing_State.h"
#include <iostream>
#include "../Shader/Simple_Shader.h"

namespace State
{
    Playing::Playing(Application& application)
    :  Game_State(application)
    ,  m_model  ({0.5,0.5,
                 -0.5,0.5,
                 -0.5,-0.5,
                 -0.5,-0.5,
                 0.5,-0.5,
                 0.5,0.5})
    {

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

        glDrawArrays(GL_TRIANGLES,0,6);

        m_model.unbind();
        m_shader.unbind();
    }
}
