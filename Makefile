ifeq ($(OS),Windows_NT) 
RM = del /Q /F
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif


SRC_DIR=src
BUILD_DIR=build

CC=g++ -g -Wall
INCLUDE=-I $(SRC_DIR)/include
LIB=-L $(SRC_DIR)/lib

SRC_FILES=$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/game.cpp\
			$(SRC_DIR)/Bitmap.cpp\
			$(SRC_DIR)/ResourceManager.cpp\
			$(SRC_DIR)/rocket.cpp\

EXEC=$(BUILD_DIR)/main
CC_SDL=-lmingw32 -lSDL2main -lSDL2
CC_SDL_IMG=-lSDL2_image

#all:Build

all:
	$(CC) $(INCLUDE) $(LIB) -o $(EXEC) $(SRC_FILES) $(CC_SDL_IMG) $(CC_SDL) 
#	g++ -I src/include -L src/lib -o $(EXEC) main.cpp $(CC_SDL)

build_run:all
	$(EXEC)

clean:
	@echo "Clean project"
	$(RM) main.exe *.o
	@echo "Clean complete"

.PHONY: clean