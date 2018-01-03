#include "Quad.h"
#include <vector>

std::vector<GLfloat> vertexPositions =
{
     0.5,   0.5,    0,
     -0.5,  0.5,    0,
     -0.5,  -0.5,   0,
     0.5,   -0.5,   0,
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

Quad::Quad()
: m_model  (vertexPositions,textureCoordinates,indices)
{

}

const Model& Quad::getModel() const
{
    return m_model;
}
