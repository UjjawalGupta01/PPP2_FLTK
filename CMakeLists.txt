cmake_minimum_required(VERSION 3.2.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(PPP2_FLTK)

find_package(FLTK REQUIRED NO_MODULE)
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

add_executable(PPP2_FLTK src/main.cpp src/GUI.cpp src/Graph.cpp src/Window.cpp)

target_include_directories(PPP2_FLTK PUBLIC ${FLTK_INCLUDE_DIRS})

target_link_libraries(PPP2_FLTK PRIVATE fltk fltk_images)
