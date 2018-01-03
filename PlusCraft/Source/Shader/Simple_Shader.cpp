#include "Simple_Shader.h"

#include "../Maths/Matrix.h"

namespace Shader
{
    Simple_Shader::Simple_Shader()
    : Shader_Program ("Simple_Vertex","Simple_Fragment")
    {
        getUniformLocations();

        bind();
        loadMatrix4(m_locationProjectionMatrix,Maths::createProjectionMatrix());
        unbind();
    }

    void Simple_Shader::setTime(float time)
    {
        loadFloat(m_locationTime,time);
    }

    void Simple_Shader::setViewMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationViewMatrix,matrix);
    }

    void Simple_Shader::setModelMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationModelMatrix,matrix);
    }

    void Simple_Shader::setProjectionMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationProjectionMatrix,matrix);
    }


    void Simple_Shader::getUniformLocations()
    {
        m_locationTime              = glGetUniformLocation(getID(),"time");
        m_locationViewMatrix        = glGetUniformLocation(getID(),"viewMatrix");
        m_locationModelMatrix       = glGetUniformLocation(getID(),"modelMatrix");
        m_locationProjectionMatrix  = glGetUniformLocation(getID(),"projectionMatrix");
    }

}
