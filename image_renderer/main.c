#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <stdio.h>

const int SCREEN_WIDTH = 596;
const int SCREEN_HEIGHT = 521;

typedef int bool;
#define true 1
#define false 0

int main(int argc, char* args[])
{
    // window will be rendering to
    SDL_Window* window = NULL;
    
    // window surface
    SDL_Surface* screenSurface = NULL;

    // initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // create the window
    window = SDL_CreateWindow("imageRendering", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // load the image
    SDL_Surface* imageSurface = IMG_Load("image.png"); 
    if (imageSurface == NULL)
    {
        printf("Failed to load image! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1; 
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);

    // update the surface
    SDL_UpdateWindowSurface(window);

    // keep the window open
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0; 
}
