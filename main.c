#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "snakefunc.h"

void a(){}

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

        // Drawing
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        // Grid
        draw_grid(n, grid, renderer);
        draw_border(n, grid, renderer);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}