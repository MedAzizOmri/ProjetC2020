#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "header.h"


void initPerso(perso *p)
{
    p->sprite=IMG_Load("sprite sheet.png");

    p->posPerso.x=0;
    p->posPerso.y=290;

    p->posSprite.w=50;
    p->posSprite.h=40;
    p->posSprite.y=0;
    p->posSprite.x=0;

    p->score=0;
    p->vie=3;
    p->direction=2;
}

void initPersotwo(persod *pd)
{
    pd->sprite=IMG_Load("sprite sheet 2.png");

    pd->posPerso.x=0;
    pd->posPerso.y=290;

    pd->posSprite.w=50;
    pd->posSprite.h=40;
    pd->posSprite.y=0;
    pd->posSprite.x=0;

    pd->score=0;
    pd->vie=3;
    pd->direction=2;
}


//height = hauteur
//wight = largeur
void afficherPerso(perso p, SDL_Surface * screen)
{
    SDL_Surface *texte=NULL;
    char s[10];
    TTF_Font *police=NULL;
    SDL_Color couleurBlanche= {255,255,255};
    TTF_Init();
    SDL_Rect positiontexte;
    police=TTF_OpenFont("Urusans.ttf",40);
    sprintf (s,"Score: %d",p.score);
    texte=TTF_RenderText_Blended(police,s,couleurBlanche);
    positiontexte.x=5;
    positiontexte.y=40;
    SDL_BlitSurface(texte,NULL,screen,&positiontexte);


    SDL_Surface *imghearts=NULL;
    SDL_Rect posHearts;
    posHearts.x=70;
    posHearts.y=0;
    imghearts = IMG_Load("hearts.png");
    SDL_BlitSurface(imghearts,NULL,screen,&posHearts);

    SDL_Surface *vie=NULL;
    SDL_Rect positiontxtvie;
    vie=TTF_RenderText_Blended(police,"Vie",couleurBlanche);
    positiontxtvie.x=5;
    positiontxtvie.y=0;
    SDL_BlitSurface(vie,NULL,screen,&positiontxtvie);

    SDL_BlitSurface(p.sprite,&p.posSprite,screen,&p.posPerso);
}

void afficherPersotwo(persod pd, SDL_Surface * screen)
{
    SDL_Surface *texte=NULL;
    char s[10];
    TTF_Font *police=NULL;
    SDL_Color couleurBlanche= {255,255,255};
    TTF_Init();
    SDL_Rect positiontexte;
    police=TTF_OpenFont("Urusans.ttf",40);
    sprintf (s,"%d",pd.score);
    texte=TTF_RenderText_Blended(police,s,couleurBlanche);
    positiontexte.x=190;
    positiontexte.y=40;
    SDL_BlitSurface(texte,NULL,screen,&positiontexte);


    SDL_Surface *imghearts=NULL;
    SDL_Rect posHearts;
    posHearts.x=70;
    posHearts.y=0;
    imghearts = IMG_Load("hearts.png");
    SDL_BlitSurface(imghearts,NULL,screen,&posHearts);

    SDL_Surface *vie=NULL;
    SDL_Rect positiontxtvie;
    vie=TTF_RenderText_Blended(police,"Vie",couleurBlanche);
    positiontxtvie.x=5;
    positiontxtvie.y=0;
    SDL_BlitSurface(vie,NULL,screen,&positiontxtvie);

    SDL_BlitSurface(pd.sprite,&pd.posSprite,screen,&pd.posPerso);
}


void deplacerPerso(perso *p,int a)
{
    int speed=2;
    if(a==1)
        speed=10;
    if (a==0)
        speed=4;
    switch(p->direction)
    {
    case 3:
        p->posPerso.x+=speed;
        break;
    case 0:
        p->posPerso.x-=speed;
        break;
    }
}

void deplacerPersotwo(persod *pd,int ac)
{
    int speed=2;
    if(ac==1)
        speed=10;
    if (ac==0)
        speed=4;
    switch(pd->direction)
    {
    case 3:
        pd->posPerso.x+=speed;
        break;
    case 0:
        pd->posPerso.x-=speed;
        break;
    }
}


void animerPerso(perso* p,int frame)
{
    if(p->direction==3) //yemshi aalimin
        p->posSprite.y=40;
    else if(p->direction==2) //yetnafes aalimin
        p->posSprite.y=0;
    else if(p->direction==0) //yemshi aalisar
        p->posSprite.y=160;
    else if(p->direction==1) //yetnafes aalisar
        p->posSprite.y=120;

    if(p->posSprite.x>=350) //350 --> kamelt e tsawer lkol
        p->posSprite.x=0;
    else p->posSprite.x+=50*frame;
}

void animerPersotwo(persod* pd,int fr)
{
    if(pd->direction==3) //yemshi aalimin
        pd->posSprite.y=40;
    else if(pd->direction==2) //yetnafes aalimin
        pd->posSprite.y=0;
    else if(pd->direction==0) //yemshi aalisar
        pd->posSprite.y=160;
    else if(pd->direction==1) //yetnafes aalisar
        pd->posSprite.y=120;

    if(pd->posSprite.x>=350) //350 --> kamelt e tsawer lkol
        pd->posSprite.x=0;
    else pd->posSprite.x+=50*fr;
}


void saut(perso* p,int j)
{

    if(p->direction==2)
    {
        if(j<=8)
        {
            p->posPerso.y= p->posPerso.y-(1*j);
            p->posPerso.x=p->posPerso.x+(0.5*j);
        }

        else if(j>8)
        {
            p->posPerso.y= p->posPerso.y+(1*(j-8));
            p->posPerso.x=p->posPerso.x+(0.5*j);
        }
    }
    else if(p->direction==1)
    {
        if(j<=8)
        {
            p->posPerso.y= p->posPerso.y-(1*j);
            p->posPerso.x=p->posPerso.x-(0.5*j);
        }

        else if(j>8)
        {
            p->posPerso.y= p->posPerso.y+(1*(j-8));
            p->posPerso.x=p->posPerso.x-(0.5*j);
        }
    }
}

void sauttwo(persod* pd,int s)
{

    if(pd->direction==2)
    {
        if(s<=8)
        {
            pd->posPerso.y= pd->posPerso.y-(1*s);
            pd->posPerso.x=pd->posPerso.x+(0.5*s);
        }

        else if(s>8)
        {
            pd->posPerso.y= pd->posPerso.y+(1*(s-8));
            pd->posPerso.x=pd->posPerso.x+(0.5*s);
        }
    }
    else if(pd->direction==1)
    {
        if(s<=8)
        {
            pd->posPerso.y= pd->posPerso.y-(1*s);
            pd->posPerso.x=pd->posPerso.x-(0.5*s);
        }

        else if(s>8)
        {
            pd->posPerso.y= pd->posPerso.y+(1*(s-8));
            pd->posPerso.x=pd->posPerso.x-(0.5*s);
        }
    }
}

