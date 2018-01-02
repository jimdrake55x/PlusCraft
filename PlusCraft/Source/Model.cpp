#include "Model.h"
#include <GL/glew.h>


Model::Model(const std::vector<GLfloat>& vertexPositions)
{
    glGenBuffers(1, &m_vertexId); // We now have the buffer id
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexId); //TODO check this out seems fishy

    glBufferData(GL_ARRAY_BUFFER,
                vertexPositions.size() * sizeof(vertexPositions[0]),
                vertexPositions.data(),
                GL_STATIC_DRAW);


    glVertexAttribPointer(0,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (GLvoid*) 0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); //TODO check this out seems fishy


}

Model::~Model()
{
    glDeleteBuffers(1,&m_vertexId);
}

void Model::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexId); //TODO check this out seems fishy
}

void Model::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0); //TODO check this out seems fishy
}
