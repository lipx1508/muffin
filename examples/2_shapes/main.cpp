#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

#include <math.h>

int main(int argc, char * argv[]) {
    muffin::init("muffin | 2 - Shapes", 800, 800);
    muffin::graphics::setscale(4);

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();

        muffin::graphics::setcolor(0, 255, 0, 255);
        muffin::graphics::drawrect(100, 40, sin((muffin::ticksms() / 5) * (3.14 / 180)) * 25, 
                                            sin((muffin::ticksms() / 5) * (3.14 / 180)) * 25);

        muffin::graphics::setcolor(255, 0, 0, 255);
        muffin::graphics::drawline(100, 100, 100 + sin(muffin::ticksms() * (3.14 / 180)) * 25, 
                                             100 + cos(muffin::ticksms() * (3.14 / 180)) * 25);

        muffin::update();
    }

    muffin::close();
    
    return 0;
}