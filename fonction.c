#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"


int playjeu ()
{
    SDL_Surface *screen,*bg;
    int done=1;
    SDL_Event event;
    Mix_Music *music;
    SDL_Rect posbg,positionecran;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Error: %s\n",SDL_GetError());

    }
    screen = SDL_SetVideoMode(1600,769,32,SDL_HWSURFACE|SDL_DOUBLEBUF);//10000,360
    if(!screen)
    {
        printf("Error: %s\n",SDL_GetError());
    }

    bg = IMG_Load("Maps/map1.png");
    positionecran.x = 225-32;
    posbg.x = 0;
    positionecran.y = 225-32;
    posbg.y = 0-500;

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("Error : %s",Mix_GetError());
    }
    music = Mix_LoadMUS("Music/music.mp3");
    Mix_PlayMusic(music,-1);
    while(done)
    {
        SDL_BlitSurface(bg,NULL,screen,&posbg);
        SDL_Flip(screen);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE )
                {
                    return 0;
                    done=0;
                }
                break;
            case SDL_QUIT:
                return 0 ;
                break;
            }
        }
    }
    Mix_FreeMusic(music);
}



void animation (SDL_Surface *img[8],SDL_Surface *screen,SDL_Rect positionFond)

{
   int i;
   for(i=1;i<8;i++)
   {
     SDL_BlitSurface(img[i], NULL,screen,&positionFond);
   }
}

