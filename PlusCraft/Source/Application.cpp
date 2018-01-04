#include "Application.h"
#include "Display.h"
#include <memory>

#include "States/Game_State.h"
#include "States/Playing_State.h"

Application::Application()
{
    pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{

    sf::Clock clock;
    while(Display::isOpen())
    {
        auto deltaTime = clock.restart().asSeconds();
        m_renderer.clear();

        m_states.top()->input(camera);
        m_states.top()->update(camera, deltaTime);
        m_states.top()->draw(m_renderer);

        m_renderer.update(camera);
        Display::checkForClose();
    }
}

void Application::pushState(std::unique_ptr<State::Game_State> state)
{
    m_states.push(std::move(state));
}

void Application::popState()
{
    m_states.pop();
}
