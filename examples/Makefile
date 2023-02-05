LDFLAGS  := -std=c++11 -Wall -fPIC
SOURCE   := $(wildcard *.cpp)
OUTPUT   := $(patsubst %.cpp, %.o, $(SOURCE))
LIBS     := -lm -lmuffin
TARGET   := main

.PHONY: all link clean

all: $(OUTPUT) link

%.o: %.cpp
	@echo '[ Building $<... ]'
	@g++ $(LDFLAGS) -c $^ -o $@ $(INCLUDES) $(LIBS)

link:
	@echo '[ Linking... ]'
	@g++ $(LDFLAGS) $(OUTPUT) -o $(TARGET) $(INCLUDES) $(LIBS)

clean:
	@echo '[ Cleaning... ]'
	@rm -fr bin/*.o