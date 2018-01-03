#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

namespace Display
{
    constexpr static int WIDTH = 1280;
    constexpr static int HEIGHT = 720;

    void init();
    void close();
    void clear();
    void update();

    void checkForClose();
    bool isOpen();
}

#endif // DISPLAY_H_INCLUDED
