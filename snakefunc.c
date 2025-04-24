#include "snakefunc.h"

void on_key_press(SDL_KeyboardEvent keyboardEvent){
	SDL_Event quit;
	SDL_zero(quit);
	quit.type = SDL_EVENT_QUIT;

	switch (keyboardEvent.key){
	case SDLK_ESCAPE:
		SDL_PushEvent(&quit);
		break;
	}
}

void grid_init(int sz, SDL_FPoint g[sz][sz], int w, int h){
	for (int i = 0; i <= sz; i++){
        for (int j = 0; j <= sz; j++){
            g[i][j].x = (float) w / sz * j;          
            g[i][j].y = (float) h / sz * i;
        }
    }
}

void draw_grid(int sz, SDL_FPoint g[sz][sz], SDL_Renderer* r){
	int w, h;
	SDL_Window *win = SDL_GetRenderWindow(r);
	SDL_GetWindowSize(win, &w, &h);

	SDL_Color ogcolor;
	SDL_GetRenderDrawColor(r, &ogcolor.r, &ogcolor.g, &ogcolor.b, &ogcolor.a);

	SDL_SetRenderDrawColor(r, 200, 200, 200, 1);
	
	for (int i = 0; i < sz; i++) SDL_RenderLine(r, 0, g[i][0].y, w, g[i][0].y);
	for (int i = 0; i < sz; i++) SDL_RenderLine(r, g[0][i].x, 0, g[0][i].x, h);

	SDL_SetRenderDrawColor(r, ogcolor.r, ogcolor.g, ogcolor.b, ogcolor.a);
}

void color_cell(int i, int j, int sz, SDL_FPoint g[sz][sz], SDL_Renderer *r, SDL_FColor color){
	
	SDL_Vertex vertices[4];
	// Putting the corners of the cell into the vertices array
	int c = 0;
	for (int I = i; I < i + 2; I++){
		for (int J = j; J < j + 2; J++){
			vertices[c].color = color;
			vertices[c++].position = g[I][J];
		}
	}

	int indices[6] = {0, 1, 2, 1, 2, 3}; // Order for the triangles

	SDL_RenderGeometry(r, NULL, vertices, 4, indices, 6);
}

void draw_border(int sz, SDL_FPoint g[sz][sz], SDL_Renderer* r){
	for (int i = 0; i < sz; i++){
		
	}
}