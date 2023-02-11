#ifdef _WIN32
#include <muffin.hpp>
#else
#include <muffin/muffin.hpp>
#endif

#include <stdio.h>

int main(int argc, char * argv[]) {
    muffin::init("muffin | 5 - Data", 800, 800);
    muffin::graphics::setscale(4);

    FILE * f = fopen("hi.png", "rb");
    unsigned char buffer[30000];

    if (f != NULL) {
        fread(buffer, 30000, 1, f);
        fclose(f);
    } else {
        printf("Couldn't load file\n");
        return -1;
    }

    muffin::data::loaddata(buffer, 30000);
    unsigned int sprite = muffin::graphics::loadimage(NULL);

    while (muffin::poll()) {
        muffin::graphics::setcolor(255, 255, 255, 255);
        muffin::graphics::clear();

        muffin::graphics::drawimage(sprite, 0, 0, 64, 64);

        muffin::update();
    }

    muffin::close();
    
    return 0;
}