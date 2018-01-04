#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

class Application;

namespace Renderer
{
    class Master;
}

class Camera;

namespace State
{
    //Base state class that all states will implement.
    class Game_State
    {
        public:
            //Forward declare the application, just so implementing classes don't have
            // to worry about it being there.
            Game_State(Application& application);

            virtual void input  (Camera& camera) = 0;
            virtual void update (Camera& camera, float deltaTime) = 0;
            virtual void draw   (Renderer::Master& renderer) = 0;

        protected:
            Application* m_application;
    };
}

#endif // GAME_STATE_H_INCLUDED
