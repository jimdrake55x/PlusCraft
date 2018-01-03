#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <GL/glew.h>
#include <vector>
class Model
{
    public:
        Model(const std::vector<GLfloat>& vertexPositions,
              const std::vector<GLfloat>& textureCoordinates,
              const std::vector<GLuint>& indices);
        ~Model();
        void bind();
        void unbind();

        GLuint getIndicesCount() const;
    private:
        //dim = dimensions per vertex
        void addVBO(int dim, const std::vector<GLfloat>& data); //This method will add to our Vertex Array Object
        void addEBO(const std::vector<GLuint>& indicies);

        //Our VAO of VBO's. Or Vertex array object containing Vertex Buffer objects.
        std::vector<GLuint> m_buffers;
        GLuint m_vao = 0;

        //Helper Variable to keep track of VBO's in our VAO.
        GLuint m_vboCount = 0;
        GLuint m_indicesCount = 0;
};

#endif // MODEL_H_INCLUDED
