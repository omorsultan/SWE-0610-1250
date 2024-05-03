# Circle Drawing with SDL

This project is a simple demonstration of drawing a circle using SDL (Simple DirectMedia Layer) library in C. The circle's radius increases over time, and if it collides with any of the window's boundaries, it resets to its initial value.

## Features

- Draws a circle using SDL's rendering functions.
- The circle's radius increases gradually.
- Resets the radius to its initial value if it collides with the window boundaries.

## Prerequisites

- SDL2 development libraries installed on your system.
- C compiler (GCC recommended) supporting C99 standard.

## How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/circle-drawing-sdl.git
2. Navigate to the project directory:
    ```bash
    cd circle-drawing-sdl
3. Compile the source code:
    ```bash
    gcc main.c -o circle_drawing -lSDL2
4. Run the executable:
    ```bash
    ./circle_drawing

## Controls
    Close the application: Click the close button on the window or press Ctrl + C in the terminal.
## License
    This project is licensed under the MIT License.