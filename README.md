# SFML-Physics-Simulation
Simple physics simulation using SFML with support for simple geometric shapes.

## Features

- Collision detection between circles.
- Basic physics (gravity, velocity, mass).
- Interactive object manipulation with the mouse.
- Support for creating circles on mouse click.

## Requirements

- [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
- C++ compiler with C++14 support

## Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/nevantain/SFML-Physics-Simulation.git
   cd SFML-Physics-Simulation
   ./SFML-Physics-Simulation

2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./SFML-Physics-Simulation
   
## Usage

- Left mouse click: Create a circle.

- Right mouse click: Select and drag an object.

- Objects interact with each other and with the window boundaries.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## How to Contribute
If you'd like to contribute to this project, please follow these steps:

1. Fork the repository.

2. Create a new branch (bash```git checkout -b feature/AmazingFeature```).

4. Commit your changes (bash```git commit -m 'Add some AmazingFeature'```).

5. Push the branch (bash```git push origin feature/AmazingFeature```).

6. Open a Pull Request.
