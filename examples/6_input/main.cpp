#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

int main(int argc, char * argv[]) {
    muffin::init("muffin | 6 - Input (arrow keys or WSAD to move the red square)", 800, 800);
    muffin::graphics::setscale(4);

    int x = 0, y = 0;

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();
        
        muffin::graphics::setcolor(255, 0, 0, 255);
        muffin::graphics::drawfillrect(x, y, 16, 16);

        if (muffin::input::keyboard(MUFFIN_KEY_W) or muffin::input::keyboard(MUFFIN_KEY_UP))    y--;
        if (muffin::input::keyboard(MUFFIN_KEY_S) or muffin::input::keyboard(MUFFIN_KEY_DOWN))  y++;
        if (muffin::input::keyboard(MUFFIN_KEY_A) or muffin::input::keyboard(MUFFIN_KEY_LEFT))  x--;
        if (muffin::input::keyboard(MUFFIN_KEY_D) or muffin::input::keyboard(MUFFIN_KEY_RIGHT)) x++;

        muffin::graphics::setcolor(255, 255, 0, 255);
        muffin::graphics::drawfillrect(muffin::input::mousex() / 4, muffin::input::mousey() / 4, 16, 16);

        muffin::update();
    }

    muffin::close();
    
    return 0;
}