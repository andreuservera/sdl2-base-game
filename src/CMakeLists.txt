set(SOURCE_FILES
    main.cpp
    Bitmap.cpp
    game.cpp
    ResourceManager.cpp
    rocket.cpp
)

add_executable(Game ${SOURCE_FILES})

target_link_libraries(Game
    SDL2
    SDL2_image
)