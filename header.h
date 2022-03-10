#ifndef HEADER_H_
#define HEADER_H_


typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect posPerso;
    SDL_Rect posSprite;

    int direction;
    int score;
    int vie;
} perso;

typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect posPerso;
    SDL_Rect posSprite;

    int direction;
    int score;
    int vie;
} persod;

void initPerso(perso *p);
void initPersotwo(persod *pd);

void afficherPerso(perso p, SDL_Surface * screen);
void afficherPersotwo(persod pd, SDL_Surface * screen);

void deplacerPerso(perso *p,int a);
void deplacerPersotwo(persod *pd,int ac);

void saut(perso* p,int j);
void sauttwo(persod* pd,int s);

void animerPerso(perso* p,int frame);
void animerPersotwo(persod* pd,int fr);


#endif

