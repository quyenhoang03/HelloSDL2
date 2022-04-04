cmake_minimum_required(VERSION 3.21)
project(HelloSDL2)

set(CMAKE_CXX_STANDARD 11)

include_directories(D:/SDL2_for_visualstudio/SDL2-2.0.20/include D:/SDL2_for_visualstudio/SDL2_image-2.0.5/include D:/SDL2_for_visualstudio/SDL2_mixer-2.0.4/include D:/SDL2_for_visualstudio/SDL2_ttf-2.0.18/include)
link_directories(D:/SDL2_for_visualstudio/SDL2-2.0.20/lib/x64 D:/SDL2_for_visualstudio/SDL2_image-2.0.5/lib/x64 D:/SDL2_for_visualstudio/SDL2_mixer-2.0.4/lib/x64 D:/SDL2_for_visualstudio/SDL2_ttf-2.0.18/lib/x64)
add_executable(HelloSDL2 main.cpp CommonFunction.h BaseObject.h CommonFunction.cpp BaseObject.cpp game_map.h game_map.cpp MainObject.h MainObject.cpp ImpTimer.h ImpTimer.cpp)

target_link_libraries(HelloSDL2 SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)






