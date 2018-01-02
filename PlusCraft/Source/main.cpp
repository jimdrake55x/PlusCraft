#include "Application.h"
#include "Display.h"

int main()
{
    Display::init();

    Application app;
    app.runMainGameLoop();
    return 0;
}
