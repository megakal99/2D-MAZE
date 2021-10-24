#include"header.h"
int main(int argc, char* argv[]) {
    //initialisation de SDL 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
        exit(1);
    }
    //creation de fenetre s'appele Labyrinthe prend le centre d'ecran comme position et 620*620 comme une taille
    SDL_Window* window = SDL_CreateWindow("Labyrinthe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur_window, hauteur_window, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        fprintf(stderr, "Erreur of open window: %s\n", SDL_GetError());
        exit(1);
    }
    //creation de renderer pour dessiner sur la fenetre
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Erreur au niveau de dessin sur fenetre: %s\n", SDL_GetError());
        exit(1);
    }
    //on donne l'arriere plan  le couleur blanc
    if (SDL_SetRenderDrawColor(renderer, 250, 250, 250, SDL_ALPHA_OPAQUE) != 0) {
        fprintf(stderr, "Erreur of  background color: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Rect rectangle;
    rectangle.w = 20;
    rectangle.h = 20;
    SDL_Event event;
    SDL_bool program_launched = SDL_TRUE;
    while (program_launched) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                program_launched = SDL_FALSE;
        }
        generer();
        print(renderer, rectangle);
        solution(M - 1, N - 2, renderer, rectangle);
        solution(M - 1, 1, renderer, rectangle);
        clear(renderer, rectangle);
        zeros();
        SDL_Delay(2000);
        
        


    }
   
    //fermer la SDL et détruire le renderer et la fenetre
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}
