cmake_minimum_required(VERSION 3.6)
project(RTv1)

file(GLOB SOURCES ./src/*.c ./src/*/*.c ./src/*/*/*.c ./src/*/*/*/*.c ./src/*/*/*/*/*.c)

set(LIB_PATH libft)


set(HOME_FLAGS "-I ./inc -I /Users/bruteflow/Library/Frameworks/SDL2.framework/Versions/A/Headers -I /Users/bruteflow/Library/Frameworks/SDL2_mixer.framework/Versions/A/Headers -I /Users/bruteflow/Library/Frameworks/SDL2_image.framework/Versions/A/Headers -F /nfs/2016/m/mvlad/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer")
#set(MACOS_FLAGS "-I ./inc -I ./frameworks/SDL2/Versions/A/Headers -I ./frameworks/SDL2_image/Versions/A/Headers -F ./frameworks -framework SDL2 -framework SDL2_image")
set(CMAKE_C_FLAGS ${HOME_FLAGS})
set(SOURCE_FILES ${SOURCES})
include_directories("./libft/" "./inc")
add_executable(RTv1 ${SOURCE_FILES})

file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(RTv1 ft)