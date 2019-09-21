cmake_minimum_required(VERSION 3.13)
project(DonCEyKongJr)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

add_executable(DonCEyKongJr
        src/main.c
        src/controller.h
        src/controller.c

        src/app/game.h
        src/app/game.c

        src/communication/communication.c
        src/communication/communication.h
        src/communication/JsonParser.c
        src/communication/JsonParser.h
        src/communication/socketClient.h
        src/communication/socketClient.c
        )

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        )
target_link_libraries(DonCEyKongJr ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_MIXER_LIBRARY}
        )