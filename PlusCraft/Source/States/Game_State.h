#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

class Application;

namespace State
{
    //Base state class that all states will implement.
    class Game_State
    {
        public:
            //Forward declare the application, just so implementing classes don't have
            // to worry about it being there.
            Game_State(Application& application);

            virtual void input  () = 0;
            virtual void update () = 0;
            virtual void draw   () = 0;

        protected:
            Application* m_application;
    };
}

#endif // GAME_STATE_H_INCLUDED
