cmake_minimum_required(VERSION 3.0.0)
project(FMQChallenge VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_subdirectory(external/SFML)

add_executable(FMQChallenge
    src/game.h
    src/game.cpp
    src/element.h
    src/element.cpp
    src/sprite_element.h
    src/sprite_element.cpp
    src/text_element.h
    src/text_element.cpp
    src/ball.h
    src/ball.cpp
    src/ball_holder.h
    src/ball_holder.cpp
    src/ui.h
    src/ui.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC external/SFML/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/SFML/src)

target_link_libraries(${PROJECT_NAME}
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-system
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
