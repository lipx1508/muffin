# muffin
Cross-platform, 2D graphics API for C++11.
Example of it running: https://youtu.be/R5oBCfQPgrg

## QA
### Why?
I created muffin mostly for an alternative on making graphics without the low-level scary things.\
And no, I don't made this as a replacement for any graphical API's out there. I made this for fun and as a personal utility, and then decided to share it.

### Is it hard?
Actually no! Mostly of the stuff here can be done by a newbie. For example, drawing a red rectangle literally takes 2 lines, see:
```cpp
muffin::graphics::setcolor(255, 0, 0, 255); // Sets the current color as opaque red
muffin::graphics::drawrect(5, 10, 50, 60);  // Draws a rectangle at the position x = 5, y = 10, and with the size of 50x60
```

### Does it support consoles?
No. I don't have money for a developer license or something.

### Does it support C?
Currently not, planning on porting it actually.

### How do I start?
See ["Compiling"](#Compiling).

## Dependencies
* SDL2 (plain SDL, SDL_image, SDL_ttf and SDL_mixer)
* Doxygen (optional, only used for documentation)

## Compiling
Be ensure that you have all the [dependencies](#Dependencies), and then to build it, simply run:
```sh
make all
```
And if you are in a linux based system, you can install automatically using this:
```sh
make install
```

## License
muffin is licensed by Apache 2.0, so it supports free commercial use. For more info see [the license file](LICENSE).
