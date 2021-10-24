#include "Header.h"

//Cette fonction permet de parcourir les cases vides a partir de l'entrée et de les numéroter dans l'ordre croissant en fonction de leurs distance à l'entrée
void DFS(int x, int y, int len) {
	if (!(x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1)) return; //vérifie si la case existe et qu'elle est vide
	maze[x][y] = len; // la case reçoit un numero len
	DFS(x + 1, y, len + 1);
	DFS(x, y + 1, len + 1);
	DFS(x - 1, y, len + 1);
	DFS(x, y - 1, len + 1);
}
                     //solution  de labyrinthe------------------//

void solution(int i, int j, SDL_Renderer* renderer, SDL_Rect rectangle) {
    int up, down, right, left, X, Y, a, b;
    DFS(j, i, 2); //numérotage de tout les chemins possibles(les cases vides) de la case (i,j) par ordre décroissante à partir de 2
    SDL_SetRenderDrawColor(renderer, 0,250 ,0, SDL_ALPHA_OPAQUE); //l'objet qui bouge est un rectangle de couleur vert
    a = -1;
    b = N - 2;
    rectangle.x = 20 * a;
    rectangle.y = 20 * b;
    while (a != i || b != j) {
        //vrification de la possibilité de mouvement si le condition est vrai on peut bouger sinon on ne peut pas bouger par affectation de valeur inf 
        up = (b - 1 > 0 && maze[b - 1][a] ? maze[b - 1][a] : inf); 
        left = (a - 1 > 0 && maze[b][a - 1] ? maze[b][a - 1] : inf);
        right = (a + 1 < N && maze[b][a + 1] ? maze[b][a + 1] : inf);
        down = (b + 1 < N && maze[b + 1][a] ? maze[b + 1][a] : inf);
        
        if (left < right && left < up && left < down) //mouvement la gauche
        {
            X = b;
            Y = a - 1;
        }
        if (right < left && right < up && right < down)  //mouvement vers la droite
        {
            X = b;
            Y = a + 1;
        }
        if (down < right && down < up && down < left) //mouvement vers le bas
        {
            X = b + 1;
            Y = a;
        }
        if (up < right && up < left && up < down) //mouvement vers le haut
        {
            X = b - 1;
            Y = a;
        }
        maze[X][Y] = inf; // la case (X,Y) est visitée
        a = Y, b = X;
        rectangle.x = 20 * Y;
        rectangle.y = 20 * X;
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderPresent(renderer); // dessin du chemin de solution
        SDL_Delay(150); // la vitesse de mouvement d'objet 0.15 seconde
    }
    // le chemin prend  le couleur d'arriere plan et on reinitialise  labyrinte pour le deuxieme solution
    SDL_SetRenderDrawColor(renderer, 250, 250, 250, SDL_ALPHA_OPAQUE); 
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (maze[i][j] > 0) {
                rectangle.x = 20 * j;
                rectangle.y = 20 * i;
                maze[i][j] = 1;
                SDL_RenderFillRect(renderer, &rectangle);

            }
        }
    }
    SDL_RenderPresent(renderer);
}
                    //***********************************Restart*******************************// 

//clear la fenetre pour dessiner un autre labyrinthe
void clear(SDL_Renderer* rend)
{
    
    SDL_RenderClear(rend);
    SDL_SetRenderDrawColor(rend, 250, 250, 250, SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(rend);
}

//reinitialiser les tableaux maze et racine et size pour genérer un nouveau labyrinthe
void zeros() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            maze[i][j] = 0;
        }
    }
    for (i = 0; i < NMAX * MMAX + 1; i++) {
        racine[i] = 0;
        size[i] = 0;
    }
}

