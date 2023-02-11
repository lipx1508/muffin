#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

int main(int argc, char * argv[]) {
    muffin::init("muffin | 1 - Hello world!", 800, 800);
    muffin::graphics::setscale(4);

    unsigned int font = muffin::graphics::loadfont("mini.ttf", 16);

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();

        muffin::graphics::setcolor(0, 0, 0, 255);
        muffin::graphics::drawtext(font, "Hello world!", 5, 5, 1);
        muffin::graphics::drawtext(font, "Thank you for using muffin!", 5, 15, 1);
        muffin::graphics::drawtext(font, "-lipx :D", 5, 25, 1);

        muffin::update();
    }

    muffin::close();
    
    return 0;
}