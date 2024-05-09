#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define CIRCLE_RADIUS 20
#define MOVEMENT_SPEED 4// Double the movement speed for the red circle

bool initializeSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Moving Circles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int x = -radius; x <= radius; x++) {
        int height = (int)sqrt(radius * radius - x * x);
        for (int y = -height; y <= height; y++) {
            SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!initializeSDL(&window, &renderer)) {
        return 1;
    }

    int circle1X = 0;
    int circle1Y = SCREEN_HEIGHT / 2;

    int circle2X = SCREEN_WIDTH / 2;
    int circle2Y = SCREEN_HEIGHT;

    bool collision = false;

    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                // Handle key inputs for moving circle 2
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        circle2Y -= 2*MOVEMENT_SPEED;
                        break;
                    case SDLK_DOWN:
                        circle2Y += 2*MOVEMENT_SPEED;
                        break;
                    case SDLK_LEFT:
                        circle2X -= 3*MOVEMENT_SPEED;
                        break;
                    case SDLK_RIGHT:
                        circle2X += 3*MOVEMENT_SPEED;
                        break;
                }
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Update circle 1 position
        circle1X += MOVEMENT_SPEED;
        if (circle1X >= SCREEN_WIDTH + CIRCLE_RADIUS) {
            circle1X = -CIRCLE_RADIUS; // Reset the circle position once it goes off-screen
        }

        // Check for collision
        int dx = circle1X - circle2X;
        int dy = circle1Y - circle2Y;
        int distance = sqrt(dx * dx + dy * dy);
        if (distance < 2 * CIRCLE_RADIUS) {
            collision = true;
        } else {
            collision = false;
        }

        // Draw circle 1
        SDL_Color black = {0, 0, 0, 255};
        drawCircle(renderer, circle1X, circle1Y, CIRCLE_RADIUS, black);

        // Draw circle 2
        SDL_Color red = {255, 0, 0, 255};
        if (collision) {
            // Change the color of circle 2 upon collision
            red.r = 0;
            red.g = 255;
            red.b = 0;
        }
        drawCircle(renderer, circle2X, circle2Y, CIRCLE_RADIUS, red);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
