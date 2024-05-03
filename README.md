# Circle Drawing with SDL

This project is a simple demonstration of drawing a circle using SDL (Simple DirectMedia Layer) library in C. The circle's radius increases over time, and if it collides with any of the window's boundaries, it resets to its initial value.

## Features

- Draws a circle using SDL's rendering functions.
- The circle's radius increases gradually.
- Resets the radius to its initial value if it collides with the window boundaries.

## Prerequisites

- SDL2 development libraries installed on your system.
- C & C++ compiler (GCC recommended) supporting C99 standard.

## How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/omorsultan/SWE-0610-1250.git
2. Navigate to the project directory:
    ```bash
    cd SWE-0610-1250
3. Compile the source code(Using Terminal):
    ```bash
    g++ -I src/include -L src/lib -o TASK101 TASK101.cpp -lmingw32 -lSDL2main -lSDL2
	g++ -I src/include -L src/lib -o TASK102 TASK102.cpp -lmingw32 -lSDL2main -lSDL2
4. Run the executable:
    ```bash
    ./TASK101
    ./TASK102

## Controls
    Close the application: Click the close button on the window or press Ctrl + C in the terminal.
## License
    This project is licensed under the MIT License.