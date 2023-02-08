#ifndef MUFFIN_H
#define MUFFIN_H

#define MUFFIN_MAKEVERSION(major, minor, patch) (major * 100 + minor * 10 + patch)

#define MUFFIN_MAJOR   1
#define MUFFIN_MINOR   1
#define MUFFIN_PATCH   0
#define MUFFIN_VERSION MUFFIN_MAKEVERSION(MUFFIN_MAJOR, MUFFIN_MINOR, MUFFIN_PATCH)

#define MUFFIN_KEY_UNKNOWN              0
#define MUFFIN_KEY_A                    4
#define MUFFIN_KEY_B                    5
#define MUFFIN_KEY_C                    6
#define MUFFIN_KEY_D                    7
#define MUFFIN_KEY_E                    8
#define MUFFIN_KEY_F                    9
#define MUFFIN_KEY_G                    10
#define MUFFIN_KEY_H                    11
#define MUFFIN_KEY_I                    12
#define MUFFIN_KEY_J                    13
#define MUFFIN_KEY_K                    14
#define MUFFIN_KEY_L                    15
#define MUFFIN_KEY_M                    16
#define MUFFIN_KEY_N                    17
#define MUFFIN_KEY_O                    18
#define MUFFIN_KEY_P                    19
#define MUFFIN_KEY_Q                    20
#define MUFFIN_KEY_R                    21
#define MUFFIN_KEY_S                    22
#define MUFFIN_KEY_T                    23
#define MUFFIN_KEY_U                    24
#define MUFFIN_KEY_V                    25
#define MUFFIN_KEY_W                    26
#define MUFFIN_KEY_X                    27
#define MUFFIN_KEY_Y                    28
#define MUFFIN_KEY_Z                    29
#define MUFFIN_KEY_1                    30
#define MUFFIN_KEY_2                    31
#define MUFFIN_KEY_3                    32
#define MUFFIN_KEY_4                    33
#define MUFFIN_KEY_5                    34
#define MUFFIN_KEY_6                    35
#define MUFFIN_KEY_7                    36
#define MUFFIN_KEY_8                    37
#define MUFFIN_KEY_9                    38
#define MUFFIN_KEY_0                    39
#define MUFFIN_KEY_RETURN               40
#define MUFFIN_KEY_ESCAPE               41
#define MUFFIN_KEY_BACKSPACE            42
#define MUFFIN_KEY_TAB                  43
#define MUFFIN_KEY_SPACE                44
#define MUFFIN_KEY_MINUS                45
#define MUFFIN_KEY_EQUALS               46
#define MUFFIN_KEY_LEFTBRACKET          47
#define MUFFIN_KEY_RIGHTBRACKET         48
#define MUFFIN_KEY_BACKSLASH            49
#define MUFFIN_KEY_NONUSHASH            50
#define MUFFIN_KEY_SEMICOLON            51
#define MUFFIN_KEY_APOSTROPHE           52
#define MUFFIN_KEY_GRAVE                53
#define MUFFIN_KEY_COMMA                54
#define MUFFIN_KEY_PERIOD               55
#define MUFFIN_KEY_SLASH                56
#define MUFFIN_KEY_CAPSLOCK             57
#define MUFFIN_KEY_F1                   58
#define MUFFIN_KEY_F2                   59
#define MUFFIN_KEY_F3                   60
#define MUFFIN_KEY_F4                   61
#define MUFFIN_KEY_F5                   62
#define MUFFIN_KEY_F6                   63
#define MUFFIN_KEY_F7                   64
#define MUFFIN_KEY_F8                   65
#define MUFFIN_KEY_F9                   66
#define MUFFIN_KEY_F10                  67
#define MUFFIN_KEY_F11                  68
#define MUFFIN_KEY_F12                  69
#define MUFFIN_KEY_PRINTSCREEN          70
#define MUFFIN_KEY_SCROLLLOCK           71
#define MUFFIN_KEY_PAUSE                72
#define MUFFIN_KEY_INSERT               73
#define MUFFIN_KEY_HOME                 74
#define MUFFIN_KEY_PAGEUP               75
#define MUFFIN_KEY_DELETE               78
#define MUFFIN_KEY_END                  79
#define MUFFIN_KEY_PAGEDOWN             80
#define MUFFIN_KEY_RIGHT                81
#define MUFFIN_KEY_LEFT                 82
#define MUFFIN_KEY_DOWN                 83
#define MUFFIN_KEY_UP                   84
#define MUFFIN_KEY_NUMLOCKCLEAR         85

#define MUFFIN_BACKEND_SDL2             0
#define MUFFIN_BACKEND_GL2              1

namespace muffin {
    // Main
    void init(unsigned char backend);
    void config(const char * title, unsigned int w, unsigned int h, bool fullscreen = false);
    bool poll();
    void update();
    unsigned int ticksms();

    // Input
    namespace input {
        bool loadjoystick(unsigned int id);
        bool joystick(unsigned int port, unsigned int id);
        bool joystickevent(unsigned int id);

        bool keyboard(unsigned int id);
        bool keyboardevent(unsigned int id);
    };
    
    // Graphics
    namespace graphics {
        unsigned int loadimage(const char * path);
        unsigned int loadfont(const char * path, unsigned int size);
        void setcolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        void setcolorhex(unsigned long hex);
        void setscale(unsigned int size);
        void clear();
        void drawdot(int x, int y);
        void drawrect(int x, int y, int w, int h);
        void drawfillrect(int x, int y, int w, int h);
        void drawline(int x1, int y1, int x2, int y2);
        void drawimage(unsigned int id, int x, int y, int w, int h, bool flip = false, int sx = 0, int sy = 0, int sw = 0, int sh = 0);
        void drawtext(unsigned int id, const char * text, int x, int y, double size, unsigned int wrap = 0);
    };

    // Audio
    namespace audio {
        unsigned int loadaudio(const char * path);
        unsigned int loadmusic(const char * path);

        void playaudio(unsigned int id);
        void playmusic(unsigned int id, bool loop = false);

        void pauseaudio();
        void pausemusic();

        void resumeaudio();
        void resumemusic();

        void volumeaudio(unsigned char volume);
        void volumemusic(unsigned char volume);
    };

    // Trace
    namespace trace {
        void error(const char * what);
    };
};

#endif
