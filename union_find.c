#include "header.h"



//Cette foonction retourne le representant de la clique de a,implémentation de find par les tableaux
int _find(int a) {
    if (racine[a] == a) return a;
    return _find(racine[a]);
}
//Cette fonction unifie les cliques de a et b,l'implémentation d'union by size par les tableaux
void _union(int a, int b) {
    int ra = _find(a), rb = _find(b);
    if (ra == rb) return;    //Si les deux représentants sont égaux alors on fait rien
    if (size[ra] > size[rb]) size[ra] += size[rb], racine[rb] = ra;  // Si les 2 représentants sont différents alors on va les unifier dans une seule clique
    else size[rb] += size[ra], racine[ra] = rb;
}

//Cette fonction permet d'enlever le mur entre deux cellules vides
void _merge(int x, int y) {
    int i = rand() % 4;
    switch (i) {
    case 0:
        // right
        // recherche d'une case à droite si c'est possible pour percer le mur
        if (y + 2 < M - 1 && _find(x * N + y) != _find(x * N + y + 2))
        {
            maze[x][y + 1]++;
            _union(x * N + y, x * N + y + 2);
        }
        break;
    case 1:
        // left
        // recherche d'une case à gauche si c'est possible pour percer le mur
        if (y - 2 > 0 && _find(x * N + y) != _find(x * N + y - 2))
        {
            maze[x][y - 1]++;
            _union(x * N + y, x * N + y - 2);
        }
        break; 
    case 2:
        // up
        // recherche d'une case en haut si c'est possible pour percer le mur
        if (x - 2 > 0 && _find(x * N + y) != _find((x - 2) * N + y))
        {
            maze[x - 1][y]++;
            _union(x * N + y, (x - 2) * N + y);
        }
        break; 
    case 3:
        // down
        // recherche d'une case en bas si c'est possible pour percer le mur
        if (x + 2 < N - 1 && _find(x * N + y) != _find((x + 2) * N + y))
        {
            maze[x + 1][y]++;
            _union(x * N + y, (x + 2) * N + y);
        }
        break; 
    }
}
