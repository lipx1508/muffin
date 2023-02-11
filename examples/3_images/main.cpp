#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

int main(int argc, char * argv[]) {
    muffin::init("muffin | 3 - Images", 800, 800);
    muffin::graphics::setscale(4);

    unsigned int sprite = muffin::graphics::loadimage("hi.png");

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();
        
        muffin::graphics::drawimage(sprite, 0, 0, 64, 64);

        muffin::update();
    }

    muffin::close();
    
    return 0;
}