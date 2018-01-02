#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "Game_State.h"
#include "../Model.h"
#include "../Shader/Simple_Shader.h"

class Application;

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input  () override;
            void update () override;
            void draw   () override;

        private:
            Model m_model;

            Shader::Simple_Shader m_shader;

    };
}
#endif // PLAYING_STATE_H_INCLUDED
