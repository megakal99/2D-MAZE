#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define largeur_window 620
#define hauteur_window 620
#define NMAX 32
#define MMAX 32
#define inf  1e3
#define N 31
#define M 31
//------------------------------------------------------------------//
//declaration variables globeaux
int maze[NMAX][MMAX];
int racine[NMAX * MMAX + 1];  // tableau des represantants(racines)
int size[NMAX * MMAX + 1];    // Tableau des taille(size) des cliques

						   
//prototypes des fonctions

int _find(int a); //Cette foonction retourne le representant de la clique de a

void _union(int a, int b); //Cette fonction unifie les cliques de a et b par size(implemenation de union by size

void _merge(int x, int y); ////Cette fonction permet d'enlever le mur entre deux cellules vides ayant 1 comme un element

void DFS(int x, int y, int len); ////Cette fonction permet de parcourir les cases vides(cases ont 1 comme element) a partir de l'entrée et de les numéroter dans l'ordre croissant en fonction de leurs distance à l'entrée

void generer(); //generation de labyrinthe des 0 comme obstacles et 1 comme chemins possibles

void print(SDL_Renderer* rend, SDL_Rect rectangle); //affichage labyrinthe avec interface graphique

void solution(int i, int j, SDL_Renderer* renderer, SDL_Rect rectangle); // solver labyrinthe

void clear(SDL_Renderer* rend); //clear window for generation a new maze
void zeros(); // reinitialiser les tableaux maze et racine et size pour genérer un nouveau labyrinthe








