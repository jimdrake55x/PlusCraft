#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include <vector>
#include <SFML/System/Clock.hpp>

#include "../Shader/Simple_Shader.h"
#include "../Entity.h"

class Quad;
class Camera;

namespace Renderer
{
    class Simple
    {
        public:
            void update(const Camera& camera);
            void draw(const Quad& quad);

        private:
            void prepare(const Quad& quad);

            std::vector<const Quad*> m_quads;
            Shader::Simple_Shader m_shader;
            sf::Clock m_clock;

    };
}

#endif // SIMPLE_H_INCLUDED
