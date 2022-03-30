cmake_minimum_required(VERSION 3.0.0)
project(FMQChallenge VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_subdirectory(external/SFML)
add_subdirectory(src)

add_executable(FMQChallenge src/main.cpp)

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
