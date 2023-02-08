#include "muffin.hpp"

// Libraries
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// C++ STL
#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace muffin {
    namespace runtime {
        SDL_Window   * window;
        SDL_Renderer * renderer;
        unsigned char backend;

        vector<SDL_Texture  *> textures;
        vector<SDL_Joystick *> joysticks(8);
        vector<TTF_Font     *> fonts;
        vector<Mix_Chunk    *> chunks;
        vector<Mix_Music    *> musics;

        set<SDL_Keycode>       keyevents;
        set<unsigned int>      joystickevents;
    };
};

// Main
void muffin::init(unsigned char backend) {
    // Initializes everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw SDL_GetError();
    if (TTF_Init()                    != 0) throw TTF_GetError();

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) throw Mix_GetError();

    runtime::window = SDL_CreateWindow("muffin window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
    if (runtime::window == NULL) throw SDL_GetError();

    // Inits according to backend
    runtime::backend = backend;
    if (backend != MUFFIN_BACKEND_GL2) {
        runtime::renderer = SDL_CreateRenderer(runtime::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
        SDL_SetRenderDrawBlendMode(runtime::renderer, SDL_BLENDMODE_BLEND);
        if (runtime::renderer == NULL) throw SDL_GetError();
    }
}

void muffin::config(const char * title, unsigned int w, unsigned int h, bool fullscreen) {
    // Initializes everything
    SDL_SetWindowTitle(runtime::window, title);
    SDL_SetWindowSize(runtime::window, w, h);
    SDL_SetWindowPosition(runtime::window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_SetWindowFullscreen(runtime::window, fullscreen);

    if (runtime::backend != MUFFIN_BACKEND_GL2) {
        // Updates renderer
        SDL_RenderPresent(runtime::renderer);
    }
}

bool muffin::poll() {
    // Polls events
    bool quit = true;
    runtime::keyevents.clear();
    runtime::joystickevents.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                quit = false;
                break;
            }
            case SDL_KEYDOWN: {
                runtime::keyevents.insert(event.key.keysym.sym);
                break;
            } 
            case SDL_JOYBUTTONDOWN: {
                runtime::joystickevents.insert(event.jbutton.button);
            }
        }
    }

    return quit;
}

void muffin::update() {
    // Updates mixer
    Mix_PlayingMusic();

    if (runtime::backend != MUFFIN_BACKEND_GL2) {
        // Updates renderer
        SDL_RenderPresent(runtime::renderer);
    }
}

unsigned int muffin::ticksms() {
    return SDL_GetTicks();
}

// Input
bool muffin::input::loadjoystick(unsigned int id) {
    // Loads a joystick and returns if it's connected
    if (SDL_NumJoysticks() > (int)id) {
        runtime::joysticks[id] = SDL_JoystickOpen(id);
        if (runtime::joysticks[id] == NULL) trace::error(SDL_GetError());
    } else {
        return false;
    }

    return true;
}

bool muffin::input::joystick(unsigned int port, unsigned int id) {
    // Joysticks buttons
    return SDL_JoystickGetButton(runtime::joysticks[port], id - 1);
}

bool muffin::input::joystickevent(unsigned int id) {
    // Joystick buttons (but using events)
    return runtime::joystickevents.count(id - 1);
}

bool muffin::input::keyboard(unsigned int id) {
    // Gets keypresses
    auto k = SDL_GetKeyboardState(NULL);
    return k[id];
}

bool muffin::input::keyboardevent(unsigned int id) {
    // Gets keypresses (but using events)
    return runtime::keyevents.count(SDL_GetKeyFromScancode((SDL_Scancode)id));
}

// Graphics
unsigned int muffin::graphics::loadimage(const char * path) {
    // Loads an image and returns it's ID (kinda like OpenGL)
    SDL_Texture * texture = IMG_LoadTexture(runtime::renderer, path);
    if (texture == NULL) trace::error(SDL_GetError());

    runtime::textures.push_back(texture);

    return runtime::textures.size() - 1;
}

unsigned int muffin::graphics::loadfont(const char * path, unsigned int size) {
    // Loads an font and returns it's ID
    TTF_Font * font = TTF_OpenFont(path, size);
    runtime::fonts.push_back(font);

    return runtime::fonts.size() - 1;
}

void muffin::graphics::setcolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    // Sets current color
    SDL_SetRenderDrawColor(runtime::renderer, r, g, b, a);
}

void muffin::graphics::setcolorhex(unsigned long hex) {
    // Sets current color
    SDL_SetRenderDrawColor(runtime::renderer, hex >> 24, hex >> 16, hex >> 8, hex);
}

void muffin::graphics::setscale(unsigned int size) {
    // Sets current color
    SDL_RenderSetScale(runtime::renderer, size, size);
}

void muffin::graphics::clear() {
    // Clears screen
    SDL_RenderClear(runtime::renderer);
}

void muffin::graphics::drawdot(int x, int y) {
    // Draws a dot
    SDL_RenderDrawPoint(runtime::renderer, x, y);
}

void muffin::graphics::drawrect(int x, int y, int w, int h) {
    // Draws an rectangle
    SDL_Rect dst = { x, y, w, h };
    SDL_RenderDrawRect(runtime::renderer, &dst);
}

void muffin::graphics::drawfillrect(int x, int y, int w, int h) {
    // Draws an rectangle
    SDL_Rect dst = { x, y, w, h };
    SDL_RenderFillRect(runtime::renderer, &dst);
}

void muffin::graphics::drawline(int x1, int y1, int x2, int y2) {
    // Draws a line
    SDL_RenderDrawLine(runtime::renderer, x1, y1, x2, y2);
}

void muffin::graphics::drawimage(unsigned int id, int x, int y, int w, int h, bool flip, int sx, int sy, int sw, int sh) {
    // Draws an image
    SDL_Rect dst = { x, y, w, h }, dst2;

    if (sw <= 0 && sh <= 0) {
        SDL_RenderCopyEx(runtime::renderer, runtime::textures[id], NULL, &dst, 0, NULL, (SDL_RendererFlip)flip);
    } else {
        dst2 = { sx, sy, sw, sh };
        SDL_RenderCopyEx(runtime::renderer, runtime::textures[id], &dst2, &dst, 0, NULL, (SDL_RendererFlip)flip);
    }
}

void muffin::graphics::drawtext(unsigned int id, const char * text, int x, int y, double size, unsigned int wrap) {
    // Draws a image on the screen
    SDL_Color color;
    SDL_GetRenderDrawColor(runtime::renderer, &color.r, &color.g, &color.b, &color.a);
    SDL_Surface * surface;
    if (wrap) surface = TTF_RenderText_Blended_Wrapped(runtime::fonts[id], text, color, wrap);
    else surface = TTF_RenderText_Blended(runtime::fonts[id], text, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(runtime::renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect dst = { x, y };
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.w *= size, dst.h *= size;

    SDL_RenderCopy(runtime::renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

// Audio
unsigned int muffin::audio::loadaudio(const char * path) {
    // Loads an audio chunk and returns it's ID
    runtime::chunks.push_back(Mix_LoadWAV(path));

    return runtime::chunks.size() - 1;
}

unsigned int muffin::audio::loadmusic(const char * path) {
    // Loads an audio chunk and returns it's ID
    runtime::musics.push_back(Mix_LoadMUS(path));

    return runtime::musics.size() - 1;
}

void muffin::audio::playaudio(unsigned int id) {
    // Plays audio
    if (Mix_PlayChannel(-1, runtime::chunks[id], 0) == -1) 
        trace::error(Mix_GetError());
}

void muffin::audio::playmusic(unsigned int id, bool loop) {
    // Plays audio
    if (Mix_PlayMusic(runtime::musics[id], loop - 1) == -1) 
        trace::error(Mix_GetError());
}

void muffin::audio::pauseaudio() {
    Mix_Pause(-1);
}

void muffin::audio::pausemusic() {
    Mix_PauseMusic();
}

void muffin::audio::resumeaudio() {
    Mix_Resume(-1);
}

void muffin::audio::resumemusic() {
    Mix_ResumeMusic();
}

void muffin::audio::volumeaudio(unsigned char volume) {
    Mix_Volume(-1, ((volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume));
}

void muffin::audio::volumemusic(unsigned char volume) {
    Mix_VolumeMusic(((volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume));
}

void muffin::trace::error(const char * what) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "muffin framework error", what, runtime::window);
    throw what;
}
