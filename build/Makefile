CC = g++
VPATH = ../src
#CFLAGS = -I../lib/hashmap -I../lib/gamelib
CFLAGS += -std=c11 -Wpedantic -Wall -Wextra -Wmissing-prototypes -Wstrict-prototypes -Wconversion -Wshadow -Wcast-qual -Wnested-externs
CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
# CFLAGS += -O2 -DNDEBUG
CFLAGS += `sdl2-config --cflags` -MMD
LDFLAGS = `sdl2-config --libs` -lSDL2_image #-lm
OBJECTS = \
    game.o main.o

all: Main

Main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

-include $(OBJECTS:.o=.d)

clean:
	rm -f *.o *.d Main
