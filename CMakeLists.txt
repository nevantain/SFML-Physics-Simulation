cmake_minimum_required(VERSION 3.10)
project(SFML-Physics-Simulation)

set(CMAKE_CXX_STANDARD 14)

# Находим SFML
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Включаем заголовочные файлы
include_directories(include)

# Добавляем исполняемый файл
add_executable(SFML-Physics-Simulation
    src/circle.cpp
    src/rectangle.cpp
    src/physicsObject.cpp
    src/physicsEngine.cpp
    src/externalForces.cpp
    src/inputHandler.cpp
    src/game.cpp
    src/main.cpp
)

# Линкуем SFML
target_link_libraries(SFML-Physics-Simulation sfml-graphics sfml-window sfml-system)