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
    while(Display::isOpen())
    {
        m_renderer.clear();

        m_states.top()->input();
        m_states.top()->update();
        m_states.top()->draw(m_renderer);

        m_renderer.update();
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
