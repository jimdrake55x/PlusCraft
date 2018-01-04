#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "Game_State.h"
#include "../Model.h"
#include "../Shader/Simple_Shader.h"
#include "../Texture/Texture.h"

#include "../Temp/Quad.h"


class Application;
class Camera;

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input  (Camera& camera) override;
            void update (Camera& camera, float deltaTime) override;
            void draw   (Renderer::Master& renderer) override;

        private:
            Shader::Simple_Shader m_shader;
            Texture::Basic_Texture m_texture;

            Quad m_quad;

    };
}
#endif // PLAYING_STATE_H_INCLUDED
