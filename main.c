// main.c
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "snakefunc.h"

int main(int argc, char *args[]){
    // Init
    SDL_SetAppMetadata("Snake", "0.0.1", NULL);
    SDL_Init(SDL_INIT_VIDEO);

    // Window
    const int width = 800;
    const int height = 800;
    SDL_Window *win = SDL_CreateWindow("Snake", width, height, SDL_WINDOW_MAXIMIZED);
    SDL_ShowWindow(win);

    // Grid
    const int n = 50;
    SDL_FPoint grid[n+1][n+1];
    grid_init(n, grid, width, height);

    // Setting random seed
    SDL_Time time;
    SDL_GetCurrentTime(&time);
    SDL_srand(time);

    // Snake variables
    Snake_Segment *snake = (Snake_Segment *) SDL_malloc(sizeof(Snake_Segment));
    int snakeLength = 1;
    snake[0].j = n/2 + SDL_rand(21) - 10;
    snake[0].i = n/2 + SDL_rand(21) - 10;
    SDL_FColor snakeColor = {0.8, 0.5, 0, 1.0};
    // add_segment(&snake, &snakeLength);
    
    // Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(win, NULL);

    bool isRunning = true;
    SDL_Event event;
    while (isRunning){
        // Listen for events
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_EVENT_KEY_DOWN:
                on_key_press(event.key);
                break;
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            }
        }

        /// Drawing 
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        // Grid
        draw_grid(n, grid, renderer);
        draw_border(n, grid, renderer);

        // Draws snake
        color_cell(snake[0].i, snake[0].j, n, grid, renderer, snakeColor);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}