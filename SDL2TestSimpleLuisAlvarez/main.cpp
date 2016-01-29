
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character, *chac;
SDL_Rect rect_background,rect_character, rect_chac;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    chac = IMG_LoadTexture(renderer, "mario.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    SDL_QueryTexture(chac, NULL, NULL, &w, &h);
    rect_character.x = 0; rect_character.y = 100; rect_character.w = w; rect_character.h = h;
    rect_chac.x = 1; rect_chac.y = 60; rect_chac.w = w; rect_chac.h = h;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_a)

                    rect_character.x--;
                    rect_chac.x--;
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
                    rect_chac.x++;
                if(Event.key.keysym.sym == SDLK_w)
                    rect_character.y--;
                    rect_chac.y--;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_character.y++;
                    rect_chac.y++;

            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, chac, NULL, &rect_chac);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
