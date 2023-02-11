#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

int main(int argc, char * argv[]) {
    muffin::init("muffin | 4 - Music", 800, 800);
    muffin::graphics::setscale(4);

    unsigned int music = muffin::audio::loadmusic("maxwellcat-theme.mp3");
    muffin::audio::playmusic(music, true);

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();

        muffin::update();
    }

    muffin::close();
    
    return 0;
}