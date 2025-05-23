// snakefunc.c
#include <SDL3/SDL.h>
#include <stdlib.h>

// Direction
typedef enum {up, right, down, left} Direction;

// Snake body
typedef struct {
	int i;
	int j;

	
} Snake_Segment;

// Handles responses to key presses.
void on_key_press(SDL_KeyboardEvent keyboardEvent);

// Initializes grid positions.
void grid_init(int sz, SDL_FPoint g[sz+1][sz+1], int w, int h);

// Draws a grid on the renderer window.
void draw_grid(int sz, SDL_FPoint g[sz+1][sz+1], SDL_Renderer *r);

// Colors cell [i,j]
void color_cell(int i, int j, int sz, SDL_FPoint g[sz+1][sz+1], SDL_Renderer *r, SDL_FColor color);

// Draws the border around the window
void draw_border(int sz, SDL_FPoint g[sz+1][sz+1], SDL_Renderer *r);

// Adds one segment to the snake array
void add_segment(Snake_Segment **snake_p, int *sz);