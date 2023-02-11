#include <muffin/muffin.hpp>

int main(int argc, char * argv[]) {
    muffin::init("muffin | 3 - Images", 800, 800, MUFFIN_FLAGS_VSYNC);
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
