#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "Game_State.h"
#include "../Model.h"
#include "../Shader/Simple_Shader.h"
#include "../Texture/Texture.h"

class Application;

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input  () override;
            void update () override;
            void draw   (Renderer::Master& renderer) override;

        private:
            Model m_model;

            Shader::Simple_Shader m_shader;
            Texture::Basic_Texture m_texture;

    };
}
#endif // PLAYING_STATE_H_INCLUDED
