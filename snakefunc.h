#include <SDL3/SDL.h>

// Handles responses to key presses.
void on_key_press(SDL_KeyboardEvent keyboardEvent);

// Initializes grid positions.
void grid_init(int sz, SDL_FPoint g[sz][sz], int w, int h);

// Draws a grid on the renderer window.
void draw_grid(int sz, SDL_FPoint g[sz][sz], SDL_Renderer* r);

// Draws the border around the
void draw_border(n, grid, renderer);
