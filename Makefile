# Variables
CC       := g++
LDFLAGS  := -std=c++11 -Wall -fPIC
SOURCE   := $(wildcard src/*.cpp)
OUTPUT   := $(patsubst src/%.cpp, bin/%.o, $(SOURCE))

ifeq ($(OS), Windows_NT)
	LIBS     := -Iinclude -Llib/SDL2 -lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	EXTLIB   := dll
	EXTEXE   := exe
	TARGET   := libmuffin.$(EXTLIB)
else
	LIBS     := -lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	EXTLIB   := so
	EXTEXE   := bin
	TARGET   := libmuffin.$(EXTLIB)
endif

.PHONY: make all link clean docs examples

# Compiling
all: $(OUTPUT) link

bin/%.o: src/%.cpp
	@echo [ Building $<... ]
	@$(CC) $(LDFLAGS) -c $^ -o $@ $(LIBS)

# Linking
link:
	@echo [ Linking... ]
	@$(CC) -g -shared $(LDFLAGS) $(OUTPUT) -o $(TARGET) $(LIBS)

# Install (linux only)
install:
ifeq ($(OS), Windows_NT)
	@echo 'Instalation is not avaliable on Windows platforms.'
else
	@echo [ Installing... ]
	@cp -fr src/*.hpp /usr/local/include/muffin
	@cp -fr *.so /usr/local/lib/
	@echo /usr/local/lib/ | tee /etc/ld.so.conf.d/muffin.conf
	@ldconfig
endif
	
# Examples
examples:
	@echo [ Building examples... ]
	@$(CC) $(LDFLAGS) -g examples/1_hello_world/main.cpp -o examples/bin/1_hello_world.$(EXTEXE) -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/2_shapes/main.cpp      -o examples/bin/2_shapes.$(EXTEXE)      -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/3_images/main.cpp      -o examples/bin/3_images.$(EXTEXE)      -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/4_music/main.cpp       -o examples/bin/4_music.$(EXTEXE)       -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/5_data/main.cpp        -o examples/bin/5_data.$(EXTEXE)        -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/6_input/main.cpp       -o examples/bin/6_input.$(EXTEXE)       -lm -lmuffin

# Doxygen
docs:
	@doxygen Doxyfile

# Cleaning
clean:
	@echo [ Cleaning... ]
ifeq ($(OS), Windows_NT)
	@del /S "bin\*.o" "examples\bin\*.exe" "examples\bin\*.out" "*.so" "*.dll"
else
	@rm -fr bin/*.o examples/bin/*.exe examples/bin/*.out *.so
endif
