#include"Header.h"

void generer() {
    int i, j, x, y;
    int cells = 0;
    // On commence par rendre le tableau comme une grille là ou il ya des cases vides si i et j impaires et des cases non vides sinon
    for (i = 1; i < N; i += 2) {
        for (j = 1; j < M; j += 2) {
            maze[i][j] = 1; // case vide si i et j sont impaires
            cells++; // nombres de cases vides
            racine[i * N + j] = i * N + j; //on affecte à chaque clique qui est une case vide son representant qui est son indice (i*N+j)
            size[i * N + j] = 1; //on  affecte a  chaque clique la taille 1
        }
    }
    //Tanqu'il y a pas un chemin possible à partir de l'entrée a tous les cases vides
    while (size[_find(N + 1)] < cells) { // There is a path from entry to all cells if sz == cells,
        x = 2 * (rand() % (N / 2)) + 1;
        y = 2 * (rand() % (M / 2)) + 1;
        _merge(x, y); // lier les 2 cases vides en cassant le mur
    }
    maze[N - 2][0] = maze[N - 2][M - 1] = maze[1][M - 1] = 1; // cases vides pour l'entrée et les deux sorties
}

void print(SDL_Renderer* rend, SDL_Rect rectangle) 
{
    int i, j;
    SDL_SetRenderDrawColor(rend, 103, 52, 52, SDL_ALPHA_OPAQUE); //on donne les obstacles le couleur 103Rouge 52Green 52Bleu
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
           
            if (maze[i][j] == 0) {
                rectangle.x = j * 20;
                rectangle.y = i * 20;
                SDL_RenderFillRect(rend, &rectangle); 
            }
        }
    }
   
   SDL_RenderPresent(rend);
}