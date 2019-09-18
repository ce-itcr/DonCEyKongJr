cmake_minimum_required(VERSION 3.13)
project(DonCEyKongJr)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_definitions(${GTK_CFLAGS_OTHER})

add_executable(DonCEyKongJr main.c src/controller.c src/controller.h src/communication/socketClient.c src/communication/socketClient.h src/app/Interface.c src/app/Interface.h)
target_link_libraries(DonCEyKongJr ${GTK_LIBRARIES})