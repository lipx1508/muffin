LDFLAGS  := -std=c++11 -Wall -fPIC
SOURCE   := $(wildcard src/*.cpp)
OUTPUT   := $(patsubst src/%.cpp, bin/%.o, $(SOURCE))
LIBS     := -lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TARGET   := libmuffin.so

.PHONY: all link clean docs

all: $(OUTPUT) link

bin/%.o: src/%.cpp
	@echo '[ Building $<... ]'
	@g++ $(LDFLAGS) -c $^ -o $@ $(INCLUDES) $(LIBS)

link:
	@echo '[ Linking... ]'
	@g++ -g -rdynamic -shared $(LDFLAGS) $(OUTPUT) -o $(TARGET) $(INCLUDES) $(LIBS)

install:
	@echo '[ Installing... ]'
	@cp -fr src/*.hpp /usr/local/include/muffin
	@cp -fr *.so /usr/local/lib/
	@echo /usr/local/lib/ | tee /etc/ld.so.conf.d/muffin.conf
	@ldconfig

docs:
	@doxygen Doxyfile

clean:
	@echo '[ Cleaning... ]'
	@rm -fr bin/*.o
