CC       := g++
LDFLAGS  := -std=c++11 -Wall -fPIC
SOURCE   := $(wildcard src/*.cpp)
OUTPUT   := $(patsubst src/%.cpp, bin/%.o, $(SOURCE))
LIBS     := -lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TARGET   := libmuffin.so

.PHONY: make all link clean docs examples

all: $(OUTPUT) link

bin/%.o: src/%.cpp
	@echo '[ Building $<... ]'
	@$(CC) $(LDFLAGS) -c $^ -o $@ $(LIBS)

link:
	@echo '[ Linking... ]'
	@$(CC) -g -shared $(LDFLAGS) $(OUTPUT) -o $(TARGET) $(LIBS)

install:
	@echo '[ Installing... ]'
	@cp -fr src/*.hpp /usr/local/include/muffin
	@cp -fr *.so /usr/local/lib/
	@echo /usr/local/lib/ | tee /etc/ld.so.conf.d/muffin.conf
	@ldconfig

examples:
	@echo '[ Building examples... ]'
	@$(CC) $(LDFLAGS) -g examples/1_hello_world/main.cpp -o examples/bin/1_hello_world.out -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/2_shapes/main.cpp      -o examples/bin/2_shapes.out           -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/3_images/main.cpp      -o examples/bin/3_images.out           -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/4_music/main.cpp       -o examples/bin/4_music.out             -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/5_data/main.cpp        -o examples/bin/5_data.out               -lm -lmuffin
	@$(CC) $(LDFLAGS) -g examples/6_input/main.cpp       -o examples/bin/6_input.out             -lm -lmuffin

docs:
	@doxygen Doxyfile

clean:
	@echo '[ Cleaning... ]'
	@rm -fr bin/*.o examples/*/*.out *.so
