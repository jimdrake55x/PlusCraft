#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <GL/glew.h>
#include <vector>
class Model
{
    public:
        Model(const std::vector<GLfloat>& vertexPositions);
        ~Model();
        void bind();
        void unbind();

    private:
        GLuint m_vertexId;
};

#endif // MODEL_H_INCLUDED
