#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "Game_State.h"

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


    };
}
#endif // PLAYING_STATE_H_INCLUDED
