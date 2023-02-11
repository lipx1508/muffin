#ifndef MUFFIN_H
#define MUFFIN_H

#define MUFFIN_MAKEVERSION(major, minor, patch) (major * 100 + minor * 10 + patch)

#define MUFFIN_MAJOR   1
#define MUFFIN_MINOR   3
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
#define MUFFIN_KEY_DELETE               76
#define MUFFIN_KEY_END                  77
#define MUFFIN_KEY_PAGEDOWN             78
#define MUFFIN_KEY_RIGHT                79
#define MUFFIN_KEY_LEFT                 80
#define MUFFIN_KEY_DOWN                 81
#define MUFFIN_KEY_UP                   82
#define MUFFIN_KEY_NUMLOCKCLEAR         83
#define MUFFIN_KEY_KP_DIVIDE            84
#define MUFFIN_KEY_KP_MULTIPLY          85
#define MUFFIN_KEY_KP_MINUS             86
#define MUFFIN_KEY_KP_PLUS              87
#define MUFFIN_KEY_KP_ENTER             88
#define MUFFIN_KEY_KP_1                 89
#define MUFFIN_KEY_KP_2                 90
#define MUFFIN_KEY_KP_3                 91
#define MUFFIN_KEY_KP_4                 92
#define MUFFIN_KEY_KP_5                 93
#define MUFFIN_KEY_KP_6                 94
#define MUFFIN_KEY_KP_7                 95
#define MUFFIN_KEY_KP_8                 96
#define MUFFIN_KEY_KP_9                 97
#define MUFFIN_KEY_KP_0                 98
#define MUFFIN_KEY_KP_PERIOD            99
#define MUFFIN_KEY_NONUSBACKSLASH       100
#define MUFFIN_KEY_APPLICATION          101
#define MUFFIN_KEY_POWER                102
#define MUFFIN_KEY_KP_EQUALS            103
#define MUFFIN_KEY_F13                  104
#define MUFFIN_KEY_F14                  105
#define MUFFIN_KEY_F15                  106
#define MUFFIN_KEY_F16                  107
#define MUFFIN_KEY_F17                  108
#define MUFFIN_KEY_F18                  109
#define MUFFIN_KEY_F19                  110
#define MUFFIN_KEY_F20                  111
#define MUFFIN_KEY_F21                  112
#define MUFFIN_KEY_F22                  113
#define MUFFIN_KEY_F23                  114
#define MUFFIN_KEY_F24                  115
#define MUFFIN_KEY_EXECUTE              116
#define MUFFIN_KEY_HELP                 117
#define MUFFIN_KEY_MENU                 118
#define MUFFIN_KEY_SELECT               119
#define MUFFIN_KEY_STOP                 120
#define MUFFIN_KEY_AGAIN                121
#define MUFFIN_KEY_UNDO                 122
#define MUFFIN_KEY_CUT                  123
#define MUFFIN_KEY_COPY                 124
#define MUFFIN_KEY_PASTE                125
#define MUFFIN_KEY_FIND                 126
#define MUFFIN_KEY_MUTE                 127
#define MUFFIN_KEY_VOLUMEUP             128
#define MUFFIN_KEY_VOLUMEDOWN           129
#define MUFFIN_KEY_LOCKINGCAPSLOCK      130
#define MUFFIN_KEY_LOCKINGNUMLOCK       131
#define MUFFIN_KEY_LOCKINGSCROLLLOCK    132
#define MUFFIN_KEY_KP_COMMA             133
#define MUFFIN_KEY_KP_EQUALSAS400       134
#define MUFFIN_KEY_INTERNATIONAL1       135
#define MUFFIN_KEY_INTERNATIONAL2       136
#define MUFFIN_KEY_INTERNATIONAL3       137
#define MUFFIN_KEY_INTERNATIONAL4       138
#define MUFFIN_KEY_INTERNATIONAL5       139
#define MUFFIN_KEY_INTERNATIONAL6       140
#define MUFFIN_KEY_INTERNATIONAL7       141
#define MUFFIN_KEY_INTERNATIONAL8       142
#define MUFFIN_KEY_INTERNATIONAL9       143
#define MUFFIN_KEY_LANG1                144
#define MUFFIN_KEY_LANG2                145
#define MUFFIN_KEY_LANG3                146
#define MUFFIN_KEY_LANG4                147
#define MUFFIN_KEY_LANG5                148
#define MUFFIN_KEY_LANG6                149
#define MUFFIN_KEY_LANG7                150
#define MUFFIN_KEY_LANG8                151
#define MUFFIN_KEY_LANG9                152
#define MUFFIN_KEY_ALTERASE             153
#define MUFFIN_KEY_SYSREQ               154
#define MUFFIN_KEY_CANCEL               155
#define MUFFIN_KEY_CLEAR                156
#define MUFFIN_KEY_PRIOR                157
#define MUFFIN_KEY_RETURN2              158
#define MUFFIN_KEY_SEPARATOR            159
#define MUFFIN_KEY_OUT                  160
#define MUFFIN_KEY_OPER                 161
#define MUFFIN_KEY_CLEARAGAIN           162
#define MUFFIN_KEY_CRSEL                163
#define MUFFIN_KEY_EXSEL                164
#define MUFFIN_KEY_KP_00                176
#define MUFFIN_KEY_KP_000               177
#define MUFFIN_KEY_THOUSANDSSEPARATOR   178
#define MUFFIN_KEY_DECIMALSEPARATOR     179
#define MUFFIN_KEY_CURRENCYUNIT         180
#define MUFFIN_KEY_CURRENCYSUBUNIT      181
#define MUFFIN_KEY_KP_LEFTPAREN         182
#define MUFFIN_KEY_KP_RIGHTPAREN        183
#define MUFFIN_KEY_KP_LEFTBRACE         184
#define MUFFIN_KEY_KP_RIGHTBRACE        185
#define MUFFIN_KEY_KP_TAB               186
#define MUFFIN_KEY_KP_BACKSPACE         187
#define MUFFIN_KEY_KP_A                 188
#define MUFFIN_KEY_KP_B                 189
#define MUFFIN_KEY_KP_C                 190
#define MUFFIN_KEY_KP_D                 191
#define MUFFIN_KEY_KP_E                 192
#define MUFFIN_KEY_KP_F                 193
#define MUFFIN_KEY_KP_XOR               194
#define MUFFIN_KEY_KP_POWER             195
#define MUFFIN_KEY_KP_PERCENT           196
#define MUFFIN_KEY_KP_LESS              197
#define MUFFIN_KEY_KP_GREATER           198
#define MUFFIN_KEY_KP_AMPERSAND         199
#define MUFFIN_KEY_KP_DBLAMPERSAND      200
#define MUFFIN_KEY_KP_VERTICALBAR       201
#define MUFFIN_KEY_KP_DBLVERTICALBAR    202
#define MUFFIN_KEY_KP_COLON             203
#define MUFFIN_KEY_KP_HASH              204
#define MUFFIN_KEY_KP_SPACE             205
#define MUFFIN_KEY_KP_AT                206
#define MUFFIN_KEY_KP_EXCLAM            207
#define MUFFIN_KEY_KP_MEMSTORE          208
#define MUFFIN_KEY_KP_MEMRECALL         209
#define MUFFIN_KEY_KP_MEMCLEAR          210
#define MUFFIN_KEY_KP_MEMADD            211
#define MUFFIN_KEY_KP_MEMSUBTRACT       212
#define MUFFIN_KEY_KP_MEMMULTIPLY       213
#define MUFFIN_KEY_KP_MEMDIVIDE         214
#define MUFFIN_KEY_KP_PLUSMINUS         215
#define MUFFIN_KEY_KP_CLEAR             216
#define MUFFIN_KEY_KP_CLEARENTRY        217
#define MUFFIN_KEY_KP_BINARY            218
#define MUFFIN_KEY_KP_OCTAL             219
#define MUFFIN_KEY_KP_DECIMAL           220
#define MUFFIN_KEY_KP_HEXADECIMAL       221
#define MUFFIN_KEY_LCTRL                224
#define MUFFIN_KEY_LSHIFT               225
#define MUFFIN_KEY_LALT                 226
#define MUFFIN_KEY_LGUI                 227
#define MUFFIN_KEY_RCTRL                228
#define MUFFIN_KEY_RSHIFT               229
#define MUFFIN_KEY_RALT                 230
#define MUFFIN_KEY_RGUI                 231
#define MUFFIN_KEY_MODE                 257
#define MUFFIN_KEY_AUDIONEXT            258
#define MUFFIN_KEY_AUDIOPREV            259
#define MUFFIN_KEY_AUDIOSTOP            260
#define MUFFIN_KEY_AUDIOPLAY            261
#define MUFFIN_KEY_AUDIOMUTE            262
#define MUFFIN_KEY_MEDIASELECT          263
#define MUFFIN_KEY_WWW                  264
#define MUFFIN_KEY_MAIL                 265
#define MUFFIN_KEY_CALCULATOR           266
#define MUFFIN_KEY_COMPUTER             267
#define MUFFIN_KEY_AC_SEARCH            268
#define MUFFIN_KEY_AC_HOME              269
#define MUFFIN_KEY_AC_BACK              270
#define MUFFIN_KEY_AC_FORWARD           271
#define MUFFIN_KEY_AC_STOP              272
#define MUFFIN_KEY_AC_REFRESH           273
#define MUFFIN_KEY_AC_BOOKMARKS         274
#define MUFFIN_KEY_BRIGHTNESSDOWN       275
#define MUFFIN_KEY_BRIGHTNESSUP         276
#define MUFFIN_KEY_DISPLAYSWITCH        277
#define MUFFIN_KEY_KBDILLUMTOGGLE       278
#define MUFFIN_KEY_KBDILLUMDOWN         279
#define MUFFIN_KEY_KBDILLUMUP           280
#define MUFFIN_KEY_EJECT                281
#define MUFFIN_KEY_SLEEP                282

#define MUFFIN_BUTTON_LEFT              1
#define MUFFIN_BUTTON_MIDDLE            2
#define MUFFIN_BUTTON_RIGHT             3

//! All the muffin API
namespace muffin {
    //! Inits muffin backends
    void init(const char * title = "muffin window", unsigned int w = 800, unsigned int h = 800, bool fullscreen = false);
    //! Polls and updates event handling
    bool poll();
    //! Updates the internal backend
    void update();
    //! Ticks since the backend initialization
    unsigned int ticksms();
    //! Clears the entire muffin internal state
    void close();
    
    //! Input (for keyboards, joysticks, etc)
    namespace input {
        //! Loads a joystick internally, and returns if is it loaded
        bool loadjoystick(unsigned int id);
        //! Gets a joystick input from a specific port
        bool joystick(unsigned int port, unsigned int id);
        //! Gets a joystick axis state from a specific port
        bool joystickaxis(unsigned int port, unsigned int id);
        //! Gets a joystick input using events
        bool joystickevent(unsigned int id);

        //! Gets keyboard input
        bool keyboard(unsigned int id);
        //! Gets keyboard input using events
        bool keyboardevent(unsigned int id);

        //! Gets mouse input
        bool mouse(unsigned int id);
        //! Gets mouse position x
        int mousex();
        //! Gets mouse position y
        int mousey();
    };
    
    //! Graphics (drawing shapes, loading images, etc)
    namespace graphics {
        //! Loads a image internally, and then returns a unique ID, which can be used for drawing later
        unsigned int loadimage(const char * path);
        //! Loads a font internally, and then returns a unique ID, which can be used for drawing later
        unsigned int loadfont(const char * path, unsigned int size);
        
        //! Sets the current drawing color to be used
        void setcolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        //! Sets the current drawing color to be used using HEX instead of pure RGBA
        void setcolorhex(unsigned long hex);
        //! Sets the render scale
        void setscale(unsigned int size);
        //! Clears the screen and the internal buffers
        void clear();
        
        //! Draws a single dot on the screen using the current color
        void drawdot(int x, int y);
        //! Draws a rectangle on the screen using the current color
        void drawrect(int x, int y, int w, int h);
        //! Draws a filled rectangle on the screen using the current color
        void drawfillrect(int x, int y, int w, int h);
        //! Draws a line on the screen using the current color
        void drawline(int x1, int y1, int x2, int y2);
        //! Draws a image on the screen using the specified ID
        void drawimage(unsigned int id, int x, int y, int w, int h, bool flip = false, int sx = 0, int sy = 0, int sw = 0, int sh = 0);
        //! Draws a text on the screen using the specified font ID and current color
        void drawtext(unsigned int id, const char * text, int x, int y, double size, unsigned int wrap = 0);
    };

    //! Audio (loading and playing music, setting music volume, pausing music, etc)
    namespace audio {
        //! Loads an audio internally, and then returns a unique ID, which can be used for playing later
        unsigned int loadaudio(const char * path);
        //! Loads a music internally, and then returns a unique ID, which can be used for playing later
        unsigned int loadmusic(const char * path);

        //! Plays audio with the specified ID
        void playaudio(unsigned int id);
        //! Plays music with the specified ID
        void playmusic(unsigned int id, bool loop = false);

        //! Pauses all audios
        void pauseaudio();
        //! Pauses all musics
        void pausemusic();

        //! Resumes all audios
        void resumeaudio();
        //! Resumes all musics
        void resumemusic();

        //! Sets all the audios volume to the specfied value (max. 128, anything higher than this will be set down to 128 again)
        void volumeaudio(unsigned char volume);
        //! Sets all the musics volume to the specfied value (max. 128, anything higher than this will be set down to 128 again)
        void volumemusic(unsigned char volume);
    };

    //! Data (more advanced, used for loading data from memory instead of disk)
    namespace data {
        //! Loads a data file
        void loaddata(unsigned char * data, unsigned int size);
    };

    //! Tracing (throws errors with correct handling)
    namespace trace {
        //! Throws an error and displays a nice error window
        void error(const char * what);
    };
};

#endif
