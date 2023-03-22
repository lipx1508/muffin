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
    /// \private
    namespace runtime {
        SDL_Window   * window;
        SDL_Renderer * renderer;
        SDL_RWops    * data;

        vector<SDL_Texture  *> textures;
        vector<SDL_Texture  *> buffers;
        vector<SDL_Joystick *> joysticks;
        vector<TTF_Font     *> fonts;
        vector<Mix_Chunk    *> chunks;
        vector<Mix_Music    *> musics;

        set<SDL_Keycode>       keyevents;
        set<unsigned int>      joystickevents;
        set<unsigned char>     mousebuttons;
        SDL_MouseWheelEvent    mousewheel;
        char *                 textinput;
    };
};

// Main
void muffin::init(const char * title, unsigned int w, unsigned int h, const char * icon, unsigned int flags) {
    // Basic core handling
    atexit(muffin::close);

    // Initializes everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw SDL_GetError();
    if (TTF_Init()                    != 0) throw TTF_GetError();

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) throw Mix_GetError();

    unsigned int fr = ((flags & MUFFIN_FLAGS_ACCELERATED)        ? SDL_RENDERER_ACCELERATED      : 0) | 
                      ((flags & MUFFIN_FLAGS_SOFTWARE)           ? SDL_RENDERER_SOFTWARE         : 0) |
                      ((flags & MUFFIN_FLAGS_VSYNC)              ? SDL_RENDERER_PRESENTVSYNC     : 0), 
                 fw = ((flags & MUFFIN_FLAGS_FULLSCREEN)         ? SDL_WINDOW_FULLSCREEN         : 0) |
                      ((flags & MUFFIN_FLAGS_FULLSCREEN_DESKTOP) ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0) | 
                      ((flags & MUFFIN_FLAGS_BORDERLESS)         ? SDL_WINDOW_BORDERLESS         : 0) | 
                      ((flags & MUFFIN_FLAGS_RESIZABLE)          ? SDL_WINDOW_RESIZABLE          : 0) | 
                      ((flags & MUFFIN_FLAGS_MINIMIZED)          ? SDL_WINDOW_MINIMIZED          : 0) | 
                      ((flags & MUFFIN_FLAGS_MAXIMIZED)          ? SDL_WINDOW_MAXIMIZED          : 0) | 
                      ((flags & MUFFIN_FLAGS_HIGHDPI)            ? SDL_WINDOW_ALLOW_HIGHDPI      : 0);

    runtime::window   = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, fw);
    runtime::renderer = SDL_CreateRenderer(runtime::window, -1, fr | SDL_RENDERER_TARGETTEXTURE);
    if (!runtime::renderer or !runtime::window) trace::error(SDL_GetError());

    // Configures
    SDL_SetRenderDrawBlendMode(runtime::renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderSetLogicalSize(runtime::renderer, w, h);
    if (icon) {
        SDL_Surface * surface = IMG_Load(icon);
        SDL_SetWindowIcon(runtime::window, surface);
        SDL_FreeSurface(surface);
    }
}

bool muffin::poll() {
    // Polls events
    bool quit = true;
    runtime::keyevents.clear();
    runtime::joystickevents.clear();
    runtime::mousebuttons.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                quit = false;
                break;
            }
            case SDL_MOUSEWHEEL: {
                runtime::mousewheel = event.wheel;
                break;
            }
            case SDL_JOYBUTTONDOWN: {
                runtime::joystickevents.insert(event.jbutton.button);
                break;
            }
            case SDL_KEYDOWN: {
                runtime::keyevents.insert(event.key.keysym.sym);
                break;
            }
            case SDL_MOUSEBUTTONDOWN: {
                runtime::joystickevents.insert(event.button.button);
                break;
            }
            case SDL_TEXTINPUT: {
                if (event.text.text) runtime::textinput = event.text.text;
                break;
            }
        }
    }

    return quit;
}

void muffin::update() {
    // Updates mixer
    Mix_PlayingMusic();

    // Updates renderer
    SDL_RenderPresent(runtime::renderer);
}

void muffin::delay(unsigned int time) {
    SDL_Delay(time);
}

unsigned int muffin::ticksms() {
    return SDL_GetTicks();
}

void muffin::close() {
    if (runtime::renderer != NULL) SDL_DestroyRenderer(runtime::renderer);
    if (runtime::window   != NULL) SDL_DestroyWindow(runtime::window);

    // Quits
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

// Input
bool muffin::input::loadjoystick(unsigned int id) {
    // Loads a joystick and returns if it's connected
    if (SDL_NumJoysticks() > (int)id) {
        if (runtime::joysticks.size() < id) runtime::joysticks.resize(id);
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

bool muffin::input::joystickaxis(unsigned int port, unsigned int id) {
    // Joysticks axis
    return SDL_JoystickGetAxis(runtime::joysticks[port], id - 1);
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

bool muffin::input::mouse(unsigned int id) {
    // Gets mouse input
    return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(id));
}

bool muffin::input::mouseevent(unsigned int id) {
    // Gets mouse input (but using events)
    return runtime::mousebuttons.count(SDL_BUTTON(id));
}

int muffin::input::mousex() {
    // Gets mouse position x
    int x;
    SDL_GetMouseState(&x, NULL);
    return x;
}

int muffin::input::mousewheely() {
    // Gets mouse wheel position x
    return runtime::mousewheel.y;
}

int muffin::input::mousewheelx() {
    // Gets mouse wheel position x
    return runtime::mousewheel.x;
}

int muffin::input::mousey() {
    // Gets mouse position x
    int y;
    SDL_GetMouseState(NULL, &y);
    return y;
}

void muffin::input::mousecapture(bool capture) {
    // Sets mouse capture
    if (SDL_CaptureMouse((SDL_bool)capture) == -1) trace::error(SDL_GetError());
}

void muffin::input::mousevisibility(bool toggle) {
    // Sets mouse capture
    if (SDL_ShowCursor(toggle) == -1) trace::error(SDL_GetError());
}

void muffin::input::textinput(bool toggle) {
    // Sets the text input state
    if (toggle) SDL_StartTextInput();
    else        SDL_StopTextInput();
}

bool muffin::input::textinputactive() {
    // Gets the text input state
    return SDL_IsTextInputActive();
}

const char * muffin::input::textinputtext() {
    // Gets text input
    return runtime::textinput;
}

// Graphics
unsigned int muffin::graphics::loadimage(const char * path) {
    // Loads an image and returns it's ID (kinda like OpenGL)
    if (path == NULL) runtime::textures.push_back(IMG_LoadTexture_RW(runtime::renderer, runtime::data, false));
    else              runtime::textures.push_back(IMG_LoadTexture(runtime::renderer, path));
    if (runtime::textures.back() == NULL) trace::error(SDL_GetError());

    return runtime::textures.size() - 1;
}

unsigned int muffin::graphics::loadfont(const char * path, unsigned int size) {
    // Loads an font and returns it's ID
    if (path == NULL) runtime::fonts.push_back(TTF_OpenFontRW(runtime::data, false, size));
    else              runtime::fonts.push_back(TTF_OpenFont(path, size));
    if (runtime::fonts.back() == NULL) trace::error(TTF_GetError());

    return runtime::fonts.size() - 1;
}

unsigned int muffin::graphics::loadcanvas(unsigned int w, unsigned int h) {
    // Loads a canvas and returns it's ID
    runtime::buffers.push_back(SDL_CreateTexture(runtime::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h));
    if (runtime::buffers.back() == NULL) trace::error(SDL_GetError());

    return runtime::buffers.size();
}

void muffin::graphics::setcolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    // Sets current color
    SDL_SetRenderDrawColor(runtime::renderer, r, g, b, a);
}

void muffin::graphics::setcolorhex(unsigned long hex) {
    // Sets current color
    SDL_SetRenderDrawColor(runtime::renderer, hex >> 24, hex >> 16, hex >> 8, hex);
}

void muffin::graphics::setcolormod(unsigned int id, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    // Sets current color mod
    SDL_SetTextureColorMod(runtime::textures[id], r, g, b);
    SDL_SetTextureAlphaMod(runtime::textures[id], a);
}

void muffin::graphics::setcolormodhex(unsigned int id, unsigned long hex) {
    // Sets current color mod
    SDL_SetTextureColorMod(runtime::textures[id], hex >> 24, hex >> 16, hex >> 8);
    SDL_SetTextureAlphaMod(runtime::textures[id], hex);
}

void muffin::graphics::setblend(unsigned int id, unsigned char mode) {
    // Sets current blending mode
    SDL_SetTextureBlendMode(runtime::textures[id], (SDL_BlendMode)mode);
}

void muffin::graphics::setquality(unsigned char quality) {
    // Sets current render quality
    SDL_SetHint("SDL_HINT_RENDER_SCALE_QUALITY", ((quality == MUFFIN_QUALITY_NEAREST)     ? "0" : 
                                                 ((quality == MUFFIN_QUALITY_LINEAR)      ? "1" : 
                                                 ((quality == MUFFIN_QUALITY_ANISOTROPIC) ? "2" : "0"))));
}

void muffin::graphics::setcanvas(unsigned int canvas) {
    // Sets current render scale
    SDL_SetRenderTarget(runtime::renderer, (canvas ? runtime::buffers[canvas - 1] : NULL));
}

void muffin::graphics::setscale(unsigned int size) {
    // Sets current render scale
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

void muffin::graphics::drawimage(unsigned int id, int x, int y, int w, int h, bool flip, double rotation, int sx, int sy, int sw, int sh) {
    // Draws an image
    SDL_Rect dst = { x, y, w, h }, dst2;

    if (sw <= 0 && sh <= 0) {
        SDL_RenderCopyEx(runtime::renderer, runtime::textures[id], NULL, &dst, rotation, NULL, (SDL_RendererFlip)flip);
    } else {
        dst2 = { sx, sy, sw, sh };
        SDL_RenderCopyEx(runtime::renderer, runtime::textures[id], &dst2, &dst, rotation, NULL, (SDL_RendererFlip)flip);
    }
}

void muffin::graphics::drawtext(unsigned int id, const char * text, int x, int y, double size, int cw, int ch, unsigned int wrap) {
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

    if (cw > 0) dst.x += (dst.w / 2) - (cw / 2);
    if (ch > 0) dst.y += (dst.h / 2) - (ch / 2);

    SDL_RenderCopy(runtime::renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

void muffin::graphics::drawcanvas(unsigned int id, int x, int y, int w, int h) {
    // Draws an image
    SDL_Rect dst = { x, y, w, h };

    SDL_RenderCopy(runtime::renderer, runtime::buffers[id - 1], NULL, &dst);
}

// Audio
unsigned int muffin::audio::loadaudio(const char * path) {
    // Loads an audio chunk and returns it's ID
    if (path == NULL) runtime::chunks.push_back(Mix_LoadWAV_RW(runtime::data, false));
    else              runtime::chunks.push_back(Mix_LoadWAV(path));
    if (runtime::chunks.back() == NULL) trace::error(Mix_GetError());

    return runtime::chunks.size() - 1;
}

unsigned int muffin::audio::loadmusic(const char * path) {
    // Loads an audio chunk and returns it's ID
    if (path == NULL) runtime::musics.push_back(Mix_LoadMUS_RW(runtime::data, false));
    else              runtime::musics.push_back(Mix_LoadMUS(path));
    if (runtime::musics.back() == NULL) trace::error(Mix_GetError());

    return runtime::musics.size() - 1;
}

void muffin::audio::playaudio(unsigned int id) {
    // Plays audio
    if (Mix_PlayChannel(-1, runtime::chunks[id], 0) == -1) trace::error(Mix_GetError());
}

void muffin::audio::playmusic(unsigned int id, bool loop) {
    // Plays audio
    if (Mix_PlayMusic(runtime::musics[id], (loop ? -1 : 0)) == -1) trace::error(Mix_GetError());
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

void muffin::audio::stopaudio() {
    Mix_HaltChannel(-1);
}

void muffin::audio::stopmusic() {
    Mix_HaltMusic();
}

bool muffin::audio::playing() {
    return Mix_PlayingMusic();
}

void muffin::audio::volumeaudio(unsigned char volume) {
    if (Mix_Volume(-1, ((volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume)) == -1) trace::error(Mix_GetError());
}

void muffin::audio::volumemusic(unsigned char volume) {
    if (Mix_VolumeMusic(((volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume)) == -1) trace::error(Mix_GetError());
}

// Data
void muffin::data::loaddata(unsigned char * data, unsigned int size) {
    if (runtime::data != NULL) SDL_RWclose(runtime::data);
    runtime::data = SDL_RWFromMem(data, size);
    if (runtime::data == NULL) trace::error(SDL_GetError());
}

// System
const char * muffin::system::platform() {
    return SDL_GetPlatform();
}

const char * muffin::system::clipboard(const char * data) {
    const char * prev = SDL_GetClipboardText();
    if (prev == NULL) trace::error(SDL_GetError());
    if (SDL_SetClipboardText(data) == -1) trace::error(SDL_GetError());
    return prev;
}

const char * muffin::system::prefpath(const char * org, const char * app) {
    const char * path = SDL_GetPrefPath(org, app);
    if (path == NULL) trace::error(SDL_GetError());
    return path;
}

const char * muffin::system::basepath() {
    const char * path = SDL_GetBasePath();
    if (path == NULL) trace::error(SDL_GetError());
    return path;
}

// Trace
void muffin::trace::error(const char * what) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "libmuffin error", what, NULL);
    cerr << "libmuffin error: " << what << '\n';

    exit(-1);
}
