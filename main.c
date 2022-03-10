#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "header.h"


int main()
{
    SDL_Event event;
    SDL_Surface *screen=NULL;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }

    screen=SDL_SetVideoMode(600,385,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    SDL_Rect posImage;
    posImage.x=0;
    posImage.y=0;
    SDL_Surface *img=NULL;
    img = IMG_Load("mario.png");

    int gamerunning=1;
    int frame=0,frames=0;
    const int FPS=30;
    int acc=0,accd=0;
    int jump=0,jumpd=0;
    int j=0,k=0;

    Uint32 start;
    perso p;
    persod pd;
    initPerso(&p);
    initPersotwo(&pd);
    SDL_EnableKeyRepeat(1,1);

    while(gamerunning)
    {
        SDL_BlitSurface(img,NULL,screen,&posImage);
        if(jump==1)
        {
            j++;
            if(j==17)
            {
                j=0;
                jump=0;
            }
        }
	if(jumpd==1)
        {
            k++;
            if(k==17)
            {
                k=0;
                jumpd=0;
            }
        }
        start=SDL_GetTicks();
        afficherPerso(p,screen);
        animerPerso(&p,frame);

        afficherPersotwo(pd,screen);
        animerPersotwo(&pd,frames);

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                gamerunning=0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gamerunning=0;
                    break;
                case SDLK_RIGHT:
                    p.score++;
                    p.direction=3;
                    deplacerPerso(&p,acc);
                    break;
		case SDLK_d:
                    pd.score++;
                    pd.direction=3;
                    deplacerPersotwo(&pd,accd);
                    break;
                case SDLK_LEFT:
                    p.score--;
                    p.direction=0;
                    deplacerPerso(&p,acc);
		    break;
		case SDLK_q:
                    pd.score--;
                    pd.direction=0;
                    deplacerPersotwo(&pd,accd);
                    break;
                case SDLK_SPACE:
                    if(acc==0)
                        acc=1;
                    break;
		case SDLK_c:
		    if(accd==0)
			accd=1;
                    break;
                case SDLK_UP:
                    jump=1;
                    break;
		case SDLK_z:
                    jumpd=1;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {

                case SDLK_SPACE:
                    if(acc==1)
                        acc=0;
                    break;
		case SDLK_c:
                    if(accd==1)
                        accd=0;
                    break;
                case SDLK_RIGHT:
                    p.direction=2;
                    break;
		case SDLK_d:
                    pd.direction=2;
                    break;
                case SDLK_LEFT:
                    p.direction=1;
                    break;
		case SDLK_q:
                    pd.direction=1;
                    break;
                }
                break;
            }
        }
        saut(&p,j);
        sauttwo(&pd,k);
        SDL_Flip(screen);
        frame++;
        if(frame==7)
            frame=0;
        if(1000/FPS>SDL_GetTicks()-start) //( (1000/FPS) --> duree mtaa kol frame fi 1s)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
    TTF_Quit();
    SDL_Quit();
    return 0;
}

