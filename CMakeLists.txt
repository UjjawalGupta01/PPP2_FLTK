cmake_minimum_required(VERSION 3.2.3)
set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
set (CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(PPP2_FLTK)

# The following line is required only if (a) you didn't install FLTK
# or if (b) find_package can't find your installation directory because
# you installed FLTK in a non-standard location.  It points to
# (a) the base folder of the build directory, or
# (b) <fltk-install-prefix>/share/fltk
# resp., where <fltk-install-prefix> is the installation prefix you
# used to install FLTK.
# (The file FLTKConfig.cmake and others must be found in that path.)
#set(FLTK_DIR /path/to/fltk)

find_package(FLTK REQUIRED NO_MODULE)
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)
# find_package(FLTK_IMAGES REQUIRED)

add_executable(PPP2_FLTK src/main.cpp src/GUI.cpp src/Graph.cpp src/Window.cpp src/my_class.cpp)

target_include_directories(PPP2_FLTK PUBLIC /home/bento306/source/GSL/include)
target_include_directories(PPP2_FLTK PUBLIC ${FLTK_INCLUDE_DIRS})

target_link_libraries(PPP2_FLTK PRIVATE fltk fltk_images)


install(TARGETS PPP2_FLTK RUNTIME DESTINATION bin)










