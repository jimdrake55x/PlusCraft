#include "Shader_Loader.h"

#include <GL/glew.h>
#include <string>

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Shader
{

    GLuint compileShader(const GLchar* source, GLenum type)
    {
        //Creating a shader of type that is passed in
        auto id = glCreateShader(type);

        //Setting the shader source to get it ready to compile
        glShaderSource(id,1,&source,nullptr);

        //Compile the shader
        glCompileShader(id);

        //Set up holders to ensure it was successful
        GLint isSuccess;
        GLchar errorLog[512];

        //Get the information
        glGetShaderiv(id,GL_COMPILE_STATUS, &isSuccess);

        //If it was not successful throw an error
        if(!isSuccess)
        {
            glGetShaderInfoLog(id,512,nullptr,errorLog);
            throw std::runtime_error ("[ERROR] Error compiling shader: " + std::string(errorLog));
        }

        return id;
    }
    std::string getSource(const std::string sourceFile)
    {
        std::fstream inFile ("Data/Shaders/" + sourceFile + ".glsl");
        std::string source;
        std::stringstream stringStream;

        if(!inFile.is_open())
        {
            throw std::runtime_error("[ERROR] Could not open file: " + sourceFile);
        }

        stringStream << inFile.rdbuf();
        source = stringStream.str();

        return source;
    }

    GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
    {
        auto id = glCreateProgram();

        glAttachShader(id,vertexShaderID);
        glAttachShader(id,fragmentShaderID);

        glLinkProgram(id);

        return id;
    }

    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        //Load the shader source files into a string
        auto vertexSource = getSource(vertexShaderFile);
        auto fragmentSource = getSource(fragmentShaderFile);

        //Compile the shader files.
        auto vertexShaderID = compileShader(vertexSource.c_str(),GL_VERTEX_SHADER);
        auto fragmentShaderID = compileShader(fragmentSource.c_str(),GL_FRAGMENT_SHADER);

        auto programID = createProgram(vertexShaderID,fragmentShaderID);

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return programID;
    }
}
