# SLD2 Game
This repo is intended to provide a basic starting point to develop a game using SDL2 in C++.

## Dependencies

### SDL2
Install by cloning the github repo and runing the following commands (copy paste all together):

```
git clone https://github.com/libsdl-org/SDL && \
cd SDL && \
./configure && \
make && \
sudo make install 
```

### SDL2_image

```
git clone https://github.com/libsdl-org/SDL_image && \
cd SDL_image && \
./configure && \
make && \
sudo make install 
```

You maybe need to install autoconf

```
sudo apt-get install autoconf
```

And you maybe have to run `./autogen.sh`

## Compile And Run

If you use vscode you can use the tasks written in *tasks.json*. If not you can configure and build with the following commands:

```
mkdir build
cd build
cmake ..
make
```

Executable is saved in the */bin* folder.
