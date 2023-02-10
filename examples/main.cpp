#include <muffin/muffin.hpp>

#include <math.h>

int main(int argc, char * argv[]) {
    muffin::init(MUFFIN_BACKEND_SDL2, "muffin example", 800, 800);
    muffin::graphics::setscale(4);

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();

        muffin::graphics::setcolor(255, 0, 0, 255);
        muffin::graphics::drawline(100, 100, 100 + sin(muffin::ticksms() * (3.14 / 180)) * 25, 100 + cos(muffin::ticksms() * (3.14 / 180)) * 25);

        muffin::update();
    }
    
    return 0;
}
