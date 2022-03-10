#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"


int main (void)
{
    int z=1,e=1,b=1;
    int width=1280,height=720;
    int pausem=0,fullscreen=0,test=1,etatjeu=0;
    TTF_Init();
    char pause;
    SDL_Surface *screen;
    SDL_Surface *ecran = NULL;
    SDL_Surface *imageDeFond = NULL;

    SDL_Surface *new_game = NULL,*credits=NULL,*help=NULL,*quit=NULL;
    SDL_Surface *new_game1 = NULL,*credits1=NULL,*help1=NULL,*quit1=NULL;
    SDL_Surface *coordinates=NULL;
    SDL_Surface *texte1=NULL;
    SDL_Surface *yes=NULL,*no=NULL,*bg=NULL;
    SDL_Surface *retuur=NULL;
    SDL_Surface *icon=NULL;

    SDL_Surface *mute=NULL,*fullscreeen=NULL,*plus=NULL,*moin=NULL,*back=NULL;
    SDL_Surface *fmute=NULL,*ffullscreen=NULL,*fvolume=NULL;
    SDL_Surface *ayed=NULL,*omri=NULL,*berraies=NULL,*hamdi=NULL,*hamida=NULL,*chargui=NULL;
    SDL_Surface *titlegame=NULL;

    TTF_Font *fonttest,*fonttestt,*fontquit,*fontmute,*fontfullscreen,*fontvolume,*fontcredits,*fonttitle;

    SDL_Rect positionFond ;
    SDL_Rect positionnew_game0,positioncredits0,positionhelp0,positionquit0;
    SDL_Rect positionnew_game1,positioncredits1,positionhelp1,positionquit1;
    SDL_Rect positionnew_game,positioncredits,positionhelp,positionquit;
    SDL_Rect coordinatesposition;
    SDL_Rect positionyes,positionyes1;
    SDL_Rect positionno,positionno1;
    SDL_Rect positionbg;
    SDL_Rect texte1position;
    SDL_Rect positionreturn;
    SDL_Rect positiontitle;
    ///setting
    SDL_Rect positionmute,positionmute1;
    SDL_Rect positionfullscreen,positionfullscreen1;
    SDL_Rect positionback,positionback1;
    SDL_Rect positionplus,positionplus1;
    SDL_Rect positionmoin,positionmoin1;

    SDL_Rect positionfontmute,positionfontfullscreen,positionfontvolume;
    SDL_Rect positionayed,positionomri,positionberraies,positionhamdi,positionhamida,positionchargui;

    SDL_Color colorcoor= {0,0,0};
    SDL_Color colorfont= {255,255,255};
    SDL_Color black= {0,0,0};
    SDL_Color red= {200,0,0};
    SDL_Color green= {0,100,0};
    SDL_Event event ;
    int continuer=1;
    screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME); ///screen
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
    
    positionFond.x = 0;
    positionFond.y = 0;
    positionbg.x=0;
    positionbg.y=0;
    positionnew_game0.x = (width*40)/100; //380
    positionnew_game0.y = height*0.22; //205
    positioncredits0.x = (width*40)/100; //446
    positioncredits0.y = (height*0.22)+100; //118
    positionhelp0.x = (width*40)/100; //555
    positionhelp0.y = (height*0.22)+200; //105
    positionquit0.x = (width*40)/100;//467
    positionquit0.y = (height*0.22)+300;//64
    positionnew_game1.x = (width*40)/100;//370
    positionnew_game1.y = (height*0.22);//205
    positioncredits1.x = (width*40)/100;//446
    positioncredits1.y = (height*0.22)+100;//118
    positionhelp1.x = (width*40)/100;//555
    positionhelp1.y = (height*0.22)+200;//105
    positionquit1.x =(width*40)/100;//467
    positionquit1.y = (height*0.22)+300;//64
    coordinatesposition.x=920;
    coordinatesposition.y=520;
    texte1position.x=10;
    texte1position.y=height*0.93;
    positionreturn.x=(width*35)/100;
    positionreturn.y=200;

    positionfontmute.x=(width*0.125);
    positionfontmute.y=(height*0.28);
    positionfontfullscreen.x=(width*0.125)+340;
    positionfontfullscreen.y=(height*0.28);
    positionfontvolume.x=(width*0.125)+740;
    positionfontvolume.y=(height*0.28);
    
    positionayed.x=(width*33)/100;
    positionayed.y=(height*0.17);
    positionomri.x=(width*40)/100;
    positionomri.y=(height*0.17)+80;
    positionberraies.x=(width*40)/100;
    positionberraies.y=(height*0.17)+160;
    positionhamdi.x=(width*40)/100;
    positionhamdi.y=(height*0.17)+240;
    positionhamida.x=(width*40)/100;
    positionhamida.y=(height*0.17)+320;
    positionchargui.x=(width*40)/100;
    positionchargui.y=(height*0.17)+400;

    positiontitle.x=380;
    positiontitle.y=10;

    SDL_Init(SDL_INIT_VIDEO);
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);

    imageDeFond = IMG_Load("1.png");///backround
    new_game = IMG_Load ("Buttons/playtest2.png");//startbutton
    new_game=IMG_Load ("Buttons/playtest.png");//startbutton2
    credits = IMG_Load ("Buttons/creditstest2.png");//creditsbutton
    credits = IMG_Load ("Buttons/creditstest.png");//creditsbutton2
    help = IMG_Load ("Buttons/settingstest2.png");//settingsbutton
    help = IMG_Load ("Buttons/settingstest.png");//settingsbutton2
    quit = IMG_Load ("Buttons/quittest2.png");//quitbutton
    quit = IMG_Load ("Buttons/quittest.png");//quitbutton2
    bg=IMG_Load("2.png");

    fonttest=TTF_OpenFont("Fonts/Ace.ttf",15);
    fonttestt=TTF_OpenFont("Fonts/Ace.ttf",25);
    fontquit=TTF_OpenFont("Fonts/Ace.ttf",80);
    fontmute=TTF_OpenFont("Fonts/Ace.ttf",55);
    fontfullscreen=TTF_OpenFont("Fonts/Ace.ttf",55);
    fontvolume=TTF_OpenFont("Fonts/Ace.ttf",55);
    fontcredits=TTF_OpenFont("Fonts/Amatic-Bold.ttf",80);
    fonttitle=TTF_OpenFont("Fonts/Drift.ttf",80);
    
    coordinates=TTF_RenderText_Blended(fonttest,"0,0",colorcoor);
    texte1=TTF_RenderText_Blended(fonttestt,"Copyright 2021 Demacia Team",colorfont);
    retuur=TTF_RenderText_Blended(fontquit, "Are You sure",red);
    titlegame=TTF_RenderText_Blended(fonttitle,"GREED ISLAND",colorfont);
    ///setting
    fmute=TTF_RenderText_Blended(fontmute,"mute",green);
    ffullscreen=TTF_RenderText_Blended(fontfullscreen,"screen size",green);
    fvolume=TTF_RenderText_Blended(fontvolume,"volume",green);
    ///credit
    ayed=TTF_RenderText_Blended(fontcredits,"med aziz ayed",black);
    omri=TTF_RenderText_Blended(fontcredits,"med aziz omri",black);
    hamdi=TTF_RenderText_Blended(fontcredits,"tasnim hamdi",black);
    berraies=TTF_RenderText_Blended(fontcredits,"louay berraies",black);
    hamida=TTF_RenderText_Blended(fontcredits,"hala hamida",black);
    chargui=TTF_RenderText_Blended(fontcredits,"firas chargui",black);

    positionnew_game = positionnew_game1;
    positioncredits=positioncredits0;
    positionhelp=positionhelp0;
    positionquit=positionquit0;
    coordinatesposition.x=940;
    coordinatesposition.y=550;

    SDL_BlitSurface(texte1,NULL,screen,&texte1position);
    SDL_BlitSurface(titlegame,NULL,screen,&positiontitle);
    Mix_Music *music;
    music = Mix_LoadMUS("Music/phunyuka.wav");
    Mix_PlayMusic(music,-1);
    Mix_Chunk *bip = NULL;
    bip = Mix_LoadWAV( "Sounds/bt3.wav" );

    icon=IMG_Load("icon.ico");
    SDL_WM_SetIcon(icon,NULL);
    putenv("SDL_VIDEO_CENTRED=1");
    
    int a=1,i;
    SDL_Flip(screen);
    char ch[50];

    SDL_Surface *img[8];
    for(i=1; i<9; i++)
    {
        sprintf(ch,"Background/%d.png",i);
        img[i]=IMG_Load(ch);
    }
    while (continuer)
    {
        etatjeu=1;
        while(etatjeu)
        {
            if (continuer==1)
            {
                animation(img,screen,positionFond);
                SDL_BlitSurface(coordinates,NULL,screen,&coordinatesposition);
                SDL_BlitSurface(new_game, NULL,screen, &positionnew_game);
                SDL_BlitSurface(credits, NULL,screen, &positioncredits);
                SDL_BlitSurface(help, NULL,screen, &positionhelp);
                SDL_BlitSurface(quit, NULL,screen, &positionquit);
                SDL_BlitSurface(texte1,NULL,screen,&texte1position);
                SDL_BlitSurface(titlegame,NULL,screen,&positiontitle);
                SDL_Flip(screen);
                SDL_Delay(10);
            }
            SDL_PollEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                continuer=0;
            case SDL_MOUSEBUTTONDOWN:
                ///Credit souris (clic gauche)
                if ((event.button.button==SDL_BUTTON_LEFT)&&((event.motion.x>(((width*40)/100)))&&(event.motion.y>(height*0.22)+100)&&(event.motion.x<(((width*40)/100)+263))&&(event.motion.y<(height*0.22)+189)))
                {
                    z=1;
                    while(z)
                    {
                        z=0;
                        int z=1,b=1,p=1;
                        positionback.x=25;
                        positionback.y=(height*0.84);
                        positionback1.x=25;
                        positionback1.y=(height*0.84);
                        
                        back=IMG_Load("backan1.png");
                        SDL_BlitSurface(bg,NULL,screen,&positionbg);
                        SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                        SDL_BlitSurface(omri,NULL,screen,&positionomri);
                        SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                        SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                        SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                        SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                        SDL_BlitSurface(back,NULL,screen,&positionback);
                        SDL_Flip(screen);
                        while(p)
                        {
                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                            SDL_BlitSurface(omri,NULL,screen,&positionomri);
                            SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                            SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                            SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                            SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                            SDL_BlitSurface(back,NULL,screen,&positionback);
                            SDL_Flip(screen);
                            SDL_WaitEvent(&event);
                            switch (event.type)
                            {
                            case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                case SDLK_DOWN:
                                {
                                    if(b==1)
                                    {
                                        back=IMG_Load("Buttons/backan2.png");
                                        positionback=positionback1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=1;
                                        break;
                                    }
                                    break;
                                }
                                case SDLK_RETURN:
                                {
                                    p=0;
                                    z=0;
            			    SDL_Flip(screen);
                                    break;
                                }
                                }
                                break;
                            }
                        }
                        z=0;
                        if(p==0)
                        {
                            z=0;
                        }
                    }
                }
                //Setting souris (clic gauche)
                if ((event.button.button==SDL_BUTTON_LEFT)&&((event.motion.x>(width*40)/100)&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<((width*40)/100)+263)&&(event.motion.y<(height*0.22)+289)))
                {
                    z=1;
                    while(z)
                    {
                        int p=1,b=1,c=1,y=1;
                        int fullscreeeen=0;
                        positionmute.x=(width*0.4)-400;
                        positionmute.y=(height*0.32);
                        positionfullscreen.x=(width*0.4);
                        positionfullscreen.y=(height*0.32);
                        positionplus.x=(width*0.4)+340;
                        positionplus.y=(height*0.32)+25;
                        positionmoin.x=(width*0.4)+480;
                        positionmoin.y=(height*0.32)+25;
                        positionback.x=25;
                        positionback.y=(height*0.84);
                        positionmute1.x=(width*0.4)-400;
                        positionmute1.y=(height*0.32);
                        positionfullscreen1.x=(width*0.4);
                        positionfullscreen1.y=(height*0.32);
                        positionplus1.x=(width*0.4)+340;
                        positionplus1.y=(height*0.32)+25;
                        positionmoin1.x=(width*0.4)+480;
                        positionmoin1.y=(height*0.32)+25;
                        positionback1.x=25;
                        positionback1.y=(height*0.84);

                        mute=IMG_Load("Buttons/musicoff1.png");
                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                        plus=IMG_Load("Buttons/+an1.png");
                        moin=IMG_Load("Buttons/-an1.png");
                        back=IMG_Load("Buttons/backan1.png");
                        
                        SDL_BlitSurface(bg,NULL,screen,&positionbg);
                        SDL_BlitSurface(mute,NULL,screen,&positionmute);
                        SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                        SDL_BlitSurface(plus,NULL,screen,&positionplus);
                        SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                        SDL_BlitSurface(back,NULL,screen,&positionback);
                        SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                        SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                        SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                        SDL_Flip(screen);
                        while(p)
                        {
                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(mute,NULL,screen,&positionmute);
                            SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                            SDL_BlitSurface(plus,NULL,screen,&positionplus);
                            SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                            SDL_BlitSurface(back,NULL,screen,&positionback);
                            SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                            SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                            SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                            SDL_Flip(screen);
                            SDL_WaitEvent(&event);
                            switch (event.type)
                            {
                            case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                case SDLK_LEFT:
                                    if(b==1)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an2.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=4;
                                        break;
                                    }
                                    else if(b==2)
                                    {
                                        mute=IMG_Load("Buttons/musicoffan2.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=1 ;
                                        break;
                                    }
                                    else if(b==3)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen2.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=2 ;
                                        break;
                                    }
                                    else
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an2.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=3 ;
                                        break;
                                    }
                                    break;
                                case SDLK_RIGHT:
                                    if(b==1)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen2.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=2 ;
                                        break;
                                    }
                                    else if(b==2)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an2.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=3 ;
                                        break;
                                    }
                                    else if(b==3)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an2.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=4 ;
                                        break;
                                    }
                                    else
                                    {
                                        mute=IMG_Load("Buttons/musicoffan2.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        b=1 ;
                                        break;
                                    }
                                    break;
                                case SDLK_DOWN:
				//Music Off (Just Key)
                                    if(c==1)
                                    {
                                        mute=IMG_Load("Buttons/musicoff1.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan2.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        positionback=positionback1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        c=0 ;
                                        break;
                                    }
                                    break;
                                case SDLK_UP:
                                    if(c==0)
                                    {
                                        mute=IMG_Load("Buttons/musicoffan2.png");
                                        fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                        plus=IMG_Load("Buttons/+an1.png");
                                        moin=IMG_Load("Buttons/-an1.png");
                                        back=IMG_Load("Buttons/backan1.png");
                                        positionmute=positionmute1;
                                        positionfullscreen=positionfullscreen1;
                                        positionplus=positionplus1;
                                        positionmoin=positionmoin1;
                                        positionback=positionback1;
                                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                        {
                                            return 1;
                                        }
                                        c=1 ;
                                        break;
                                    }
                                    break;
                                case SDLK_RETURN:
                                    if(c==0)
                                    {
                                      p=0;
            			      SDL_Flip(screen);
                                    }
                                    if(c==1)
                                    {
                                        switch(b)
                                        {
                                        case 1:
                                            if (pausem==1)
                                            {
                                                Mix_ResumeMusic();
                                                pausem=0;
                                            }
                                            else if (pausem==0)
                                            {
                                                Mix_PauseMusic();
                                                pausem=1;
                                            }
                                            break;
                                        case 2:
                                            if (fullscreeeen==0)
                                            {
                                                for(i=1;i<9;i++)
                                                {
                                                    sprintf(ch,"1920/%d.png",i);
                                                    img[i]=IMG_Load(ch);
                                                }
                                                width=1920;
                                                height=1080;
                                                SDL_Init(SDL_INIT_VIDEO);
                                                bg=IMG_Load("11f.png");
                                                imageDeFond = IMG_Load("1f.png");
                                                positionFond.x = 0;
                                                positionFond.y = 0;
                                                positionbg.x=0;
                                                positionbg.y=0;
                                                positionnew_game0.x = (width*43)/100; //380
                                                positionnew_game0.y = (height*0.22)+100; //205
                                                positioncredits0.x = (width*43)/100; //446
                                                positioncredits0.y = (height*0.22)+250; //118
                                                positionhelp0.x = (width*43)/100; //555
                                                positionhelp0.y = (height*0.22)+400; //105
                                                positionquit0.x = (width*43)/100;//467
                                                positionquit0.y = (height*0.22)+550;//64
                                                positionnew_game1.x = (width*43)/100;//370
                                                positionnew_game1.y = (height*0.22)+100;//205
                                                positioncredits1.x = (width*43)/100;//446
                                                positioncredits1.y = (height*0.22)+250;//118
                                                positionhelp1.x = (width*43)/100;//555
                                                positionhelp1.y = (height*0.22)+400;//105
                                                positionquit1.x =(width*43)/100;//467
                                                positionquit1.y = (height*0.22)+550;//64
                                                coordinatesposition.x=920;
                                                coordinatesposition.y=520;

                                                positionyes.x=(width*20)/100;
                                                positionyes.y=(height*0.22)+200;
                                                positionno.x=(width*60)/100;
                                                positionno.y=(height*0.22)+200;
                                                positionyes1.x=(width*20)/100;
                                                positionyes1.y=(height*0.22)+200;
                                                positionno1.x=(width*60)/100;
                                                positionno1.y=(height*0.22)+200;

                                                positionmute.x=(width*0.4)-400;
                                                positionmute.y=(height*0.32);
                                                positionfullscreen.x=(width*0.4);
                                                positionfullscreen.y=(height*0.32);
                                                positionplus.x=(width*0.4)+340;
                                                positionplus.y=(height*0.32)+25;
                                                positionmoin.x=(width*0.4)+480;
                                                positionmoin.y=(height*0.32)+25;
                                                positionback.x=25;
                                                positionback.y=(height*0.84);
                                                positionmute1.x=(width*0.4)-400;
                                                positionmute1.y=(height*0.32);
                                                positionfullscreen1.x=(width*0.4);
                                                positionfullscreen1.y=(height*0.32);
                                                positionplus1.x=(width*0.4)+340;
                                                positionplus1.y=(height*0.32)+25;
                                                positionmoin1.x=(width*0.4)+480;
                                                positionmoin1.y=(height*0.32)+25;
                                                positionback1.x=25;
                                                positionback1.y=(height*0.84);

                                                texte1position.x=10;
                                                texte1position.y=height*0.93;
                                                positionreturn.x=(width*40)/100;
                                                positionreturn.y=200;

                                                positionayed.x=(width*33)/100;
                                                positionayed.y=(height*0.17)+100;
                                                positionomri.x=(width*40)/100;
                                                positionomri.y=(height*0.17)+180;
                                                positionberraies.x=(width*40)/100;
                                                positionberraies.y=(height*0.17)+260;
                                                positionhamdi.x=(width*40)/100;
                                                positionhamdi.y=(height*0.17)+340;
                                                positionhamida.x=(width*40)/100;
                                                positionhamida.y=(height*0.17)+420;
                                                positionchargui.x=(width*40)/100;
                                                positionchargui.y=(height*0.17)+500;

                                                positionfontmute.x=(width*0.125)+200;
                                                positionfontmute.y=(height*0.28);
                                                positionfontfullscreen.x=(width*0.125)+540;
                                                positionfontfullscreen.y=(height*0.28);
                                                positionfontvolume.x=(width*0.125)+940;
                                                positionfontvolume.y=(height*0.28);

                                                positionnew_game = positionnew_game1;
                                                positioncredits=positioncredits0;
                                                positionhelp=positionhelp0;
                                                positionquit=positionquit0;
                                                positionyes=positionyes1;
                                                positionno=positionno1;
                                                positionmute=positionmute1;
                                                positionfullscreen=positionfullscreen1;
                                                positionplus=positionplus1;
                                                positionmoin=positionmoin1;
                                                positionback=positionback1;

                                                SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
                                                SDL_BlitSurface(coordinates,NULL,screen,&coordinatesposition);
                                                SDL_BlitSurface(new_game, NULL,screen, &positionnew_game);
                                                SDL_BlitSurface(credits, NULL,screen, &positioncredits);
                                                SDL_BlitSurface(help, NULL,screen, &positionhelp);
                                                SDL_BlitSurface(quit, NULL,screen, &positionquit);
                                                SDL_BlitSurface(texte1,NULL,screen,&texte1position);
					        SDL_BlitSurface(titlegame,NULL,screen,&positiontitle);
                                                SDL_BlitSurface(bg,NULL,screen,&positionbg);
                                                SDL_BlitSurface(yes,NULL,screen,&positionyes);
                                                SDL_BlitSurface(no,NULL,screen,&positionno);
                                                SDL_BlitSurface(retuur,NULL,screen,&positionreturn);
                                                SDL_BlitSurface(mute,NULL,screen,&positionmute);
                                                SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                                                SDL_BlitSurface(plus,NULL,screen,&positionplus);
                                                SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                                                SDL_BlitSurface(back,NULL,screen,&positionback);
                                                SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                                                SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                                                SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                                                SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                                                SDL_BlitSurface(omri,NULL,screen,&positionomri);
                                                SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                                                SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                                                SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                                                SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                                                screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                                                fullscreeeen=1;
                                            }
                                            else if (fullscreeeen==1)
                                            {
                                                for(i=1; i<9; i++)
                                                {
                                                    sprintf(ch,"Background/%d.png",i);
                                                    img[i]=IMG_Load(ch);
                                                }
                                                bg=IMG_Load("2.png");
                                                imageDeFond = IMG_Load("1.png");

                                                width=1280;
                                                height=720;
                                                SDL_Init(SDL_INIT_VIDEO);
                                                positionFond.x = 0;
                                                positionFond.y = 0;
                                                positionbg.x=0;
                                                positionbg.y=0;
                                                positionnew_game0.x = (width*40)/100; //380
                                                positionnew_game0.y = height*0.22; //205
                                                positioncredits0.x = (width*40)/100; //446
                                                positioncredits0.y = (height*0.22)+100; //118
                                                positionhelp0.x = (width*40)/100; //555
                                                positionhelp0.y = (height*0.22)+200; //105
                                                positionquit0.x = (width*40)/100;//467
                                                positionquit0.y = (height*0.22)+300;//64
                                                positionnew_game1.x = (width*40)/100;//370
                                                positionnew_game1.y = (height*0.22);//205
                                                positioncredits1.x = (width*40)/100;//446
                                                positioncredits1.y = (height*0.22)+100;//118
                                                positionhelp1.x = (width*40)/100;//555
                                                positionhelp1.y = (height*0.22)+200;//105
                                                positionquit1.x =(width*40)/100;//467
                                                positionquit1.y = (height*0.22)+300;//64

                                                positionfontmute.x=(width*0.125);
                                                positionfontmute.y=(height*0.28);
                                                positionfontfullscreen.x=(width*0.125)+340;
                                                positionfontfullscreen.y=(height*0.28);
                                                positionfontvolume.x=(width*0.125)+740;
                                                positionfontvolume.y=(height*0.28);

                                                positionyes.x=(width*20)/100;
                                                positionyes.y=(height*0.22)+200;
                                                positionno.x=(width*60)/100;
                                                positionno.y=(height*0.22)+200;
                                                positionyes1.x=(width*20)/100;
                                                positionyes1.y=(height*0.22)+200;
                                                positionno1.x=(width*60)/100;
                                                positionno1.y=(height*0.22)+200;

                                                positionmute.x=100;
                                                positionmute.y=225;
                                                positionfullscreen.x=500;
                                                positionfullscreen.y=225;
                                                positionplus.x=840;
                                                positionplus.y=250;
                                                positionmoin.x=980;
                                                positionmoin.y=250;
                                                positionback.x=25;
                                                positionback.y=(height*0.84);
                                                positionmute1.x=100;
                                                positionmute1.y=225;
                                                positionfullscreen1.x=500;
                                                positionfullscreen1.y=225;
                                                positionplus1.x=840;
                                                positionplus1.y=250;
                                                positionmoin1.x=980;
                                                positionmoin1.y=250;
                                                positionback1.x=25;
                                                positionback1.y=(height*0.84);
                                                coordinatesposition.x=920; 
                                                coordinatesposition.y=520; 
                                                texte1position.x=10;
                                                texte1position.y=height*0.93;
                                                positionreturn.x=(width*35)/100;
                                                positionreturn.y=200;

                                                positionayed.x=(width*33)/100;
                                                positionayed.y=(height*0.17);
                                                positionomri.x=(width*40)/100;
                                                positionomri.y=(height*0.17)+80;
                                                positionberraies.x=(width*40)/100;
                                                positionberraies.y=(height*0.17)+160;
                                                positionhamdi.x=(width*40)/100;
                                                positionhamdi.y=(height*0.17)+240;
                                                positionhamida.x=(width*40)/100;
                                                positionhamida.y=(height*0.17)+320;
                                                positionchargui.x=(width*40)/100;
                                                positionchargui.y=(height*0.17)+400;

                                                positionnew_game = positionnew_game1;
                                                positioncredits=positioncredits0;
                                                positionhelp=positionhelp0;
                                                positionquit=positionquit0;
                                                positionyes=positionyes1;
                                                positionno=positionno1;
                                                positionmute=positionmute1;
                                                positionfullscreen=positionfullscreen1;
                                                positionplus=positionplus1;
                                                positionmoin=positionmoin1;
                                                positionback=positionback1;
                                                screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
                                                fullscreeeen=0;
                                            }
                                            break;
                                        case 3:
					  {
                                            if(y!=1)
                                            {
                                                y=y-1;
                                                Mix_VolumeMusic(MIX_MAX_VOLUME/y);
                                            }
                                                break;
                                            break;
					  }
                                        case 4:
					  {
                                            y=y+1;
                                            Mix_VolumeMusic(MIX_MAX_VOLUME/y);
                                            break;
					  }
                                        }
                                    }
                                    break;
                                }
                            }
                            if(p==0)
                            {
                                z=0;
                            }
                        }
                    }
                    //Quit souris (clic gauche)
                    if ((event.button.button == SDL_BUTTON_LEFT)&&((event.motion.x>(((width*40)/100)))&&(event.motion.y>(height*0.22)+300)&&(event.motion.x<(((width*40)/100)+263))&&(event.motion.y<(height*0.22)+389)))
                    {
                        z=1;
                        while(z)
                        {
                            int p=1,b=1;
                            positionyes.x=(width*20)/100;
                            positionyes.y=(height*0.22)+200;
                            positionno.x=(width*60)/100;
                            positionno.y=(height*0.22)+200;
                            positionyes1.x=(width*20)/100;
                            positionyes1.y=(height*0.22)+200;
                            positionno1.x=(width*60)/100;
                            positionno1.y=(height*0.22)+200;

                            yes=IMG_Load("Buttons/yesan1.png");
                            no=IMG_Load("Buttons/noan1.png");

                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(yes,NULL,screen,&positionyes);
                            SDL_BlitSurface(no,NULL,screen,&positionno);
                            SDL_BlitSurface(retuur,NULL,screen,&positionreturn);
                            SDL_Flip(screen);
                            while(p)
                            {
                                SDL_BlitSurface(yes,NULL,screen,&positionyes);
                                SDL_BlitSurface(no,NULL,screen,&positionno);
                                SDL_Flip(screen);
                                SDL_WaitEvent(&event);
                                switch (event.type)
                                {
                                case SDL_MOUSEBUTTONDOWN:
                                    if ((event.button.button == SDL_BUTTON_LEFT)&&((event.motion.x>(((width*20)/100)))&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<(((width*20)/100)+217))&&(event.motion.y<(height*0.22)+371)))
                                    {
                                        return 99;
                                    }
                                    else if ((event.button.button == SDL_BUTTON_LEFT)&&((event.motion.x>(((width*60)/100)))&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<(((width*60)/100)+217))&&(event.motion.y<(height*0.22)+371)))
                                    {
                                        p=0;
                                    }
                                    break;
                                case SDL_KEYDOWN:
                                    switch (event.key.keysym.sym)
                                    {
                                    case SDLK_LEFT:
                                        if(b==1)
                                        {
                                            yes=IMG_Load("Buttons/yesan2.png");
                                            no=IMG_Load("Buttons/noan1.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2 ;
                                            break;
                                        }
                                        else
                                        {
                                            yes=IMG_Load("Buttons/yesan1.png");
                                            no=IMG_Load("Buttons/noan2.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_RIGHT:
                                        if(b==1)
                                        {
                                            yes=IMG_Load("Buttons/yesan2.png");
                                            no=IMG_Load("Buttons/noan1.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2 ;
                                            break;
                                        }
                                        else
                                        {
                                            yes=IMG_Load("Buttons/yesan1.png");
                                            no=IMG_Load("Buttons/noan2.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_RETURN:
                                    {
                                        switch(b)
                                        {
                                        case 1:
                                            p=0;
                                            break;
                                        case 2:
                                            return 99;
                                            break;
                                        }
                                        break;
                                    }
                                    }
                                    break;
                                }
                            }
                            if(p==0)
                            {
                                z=0;
                            }
                        }
                        break;
                    }
                }
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    return 99;
                case SDLK_RETURN:
                    switch(a)
                    {
                    case 1 :
                        etatjeu=2;
                        while (etatjeu==2)
                        {
                            etatjeu=playjeu();
                        }
                        continuer=0;
                        break;
                    case 2:
                        z=1;
                        while(z)
                        {
                            z=0;
                            int z=1,p=1,b=1;
                            positionback.x=25;
                            positionback.y=(height*0.84);
                            positionback1.x=25;
                            positionback1.y=(height*0.84);

                            back=IMG_Load("Buttons/backan1.png");
                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                            SDL_BlitSurface(omri,NULL,screen,&positionomri);
                            SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                            SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                            SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                            SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                            SDL_BlitSurface(back,NULL,screen,&positionback);
                            SDL_Flip(screen);
                            while(p)
                            {
                                SDL_BlitSurface(bg,NULL,screen,&positionbg);
                                SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                                SDL_BlitSurface(omri,NULL,screen,&positionomri);
                                SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                                SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                                SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                                SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                                SDL_BlitSurface(back,NULL,screen,&positionback);
                                SDL_Flip(screen);
                                SDL_WaitEvent(&event);
                                switch (event.type)
                                {
                                case SDL_KEYDOWN:
                                    switch (event.key.keysym.sym)
                                    {
                                    case SDLK_DOWN:
                                        if(b==1)
                                        {
                                            back=IMG_Load("Buttons/backan2.png");
                                            positionback=positionback1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1;
                                            break;
                                        }
                                        break;
                                    case SDLK_RETURN:
                                        p=0;
                                        z=0;
            				SDL_Flip(screen);
                                        break;
                                    }
                                    break;
                                }
                            }
                            z=0;
                            if(p==0)
                            {
                                z=0;
                            }
                        }
                        break;
                    case 3:
                        z=1;
                        while(z)
                        {
                            int p=1,b=1,c=1,y=1;
                            int fullscreeeen=0;

                            positionmute.x=(width*0.4)-400;
                            positionmute.y=(height*0.32);
                            positionfullscreen.x=(width*0.4);
                            positionfullscreen.y=(height*0.32);
                            positionplus.x=(width*0.4)+340;
                            positionplus.y=(height*0.32)+25;
                            positionmoin.x=(width*0.4)+480;
                            positionmoin.y=(height*0.32)+25;
                            positionback.x=25;
                            positionback.y=(height*0.84);
                            positionmute1.x=(width*0.4)-400;
                            positionmute1.y=(height*0.32);
                            positionfullscreen1.x=(width*0.4);
                            positionfullscreen1.y=(height*0.32);
                            positionplus1.x=(width*0.4)+340;
                            positionplus1.y=(height*0.32)+25;
                            positionmoin1.x=(width*0.4)+480;
                            positionmoin1.y=(height*0.32)+25;
                            positionback1.x=25;
                            positionback1.y=(height*0.84);

                            mute=IMG_Load("Buttons/musicoff1.png");
                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                            plus=IMG_Load("Buttons/+an1.png");
                            moin=IMG_Load("Buttons/-an1.png");
                            back=IMG_Load("Buttons/backan1.png");

                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(mute,NULL,screen,&positionmute);
                            SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                            SDL_BlitSurface(plus,NULL,screen,&positionplus);
                            SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                            SDL_BlitSurface(back,NULL,screen,&positionback);
                            SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                            SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                            SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                            SDL_Flip(screen);
                            while(p)
                            {
                                SDL_BlitSurface(bg,NULL,screen,&positionbg);
                                SDL_BlitSurface(mute,NULL,screen,&positionmute);
                                SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                                SDL_BlitSurface(plus,NULL,screen,&positionplus);
                                SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                                SDL_BlitSurface(back,NULL,screen,&positionback);
                                SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                                SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                                SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                                SDL_Flip(screen);
                                SDL_WaitEvent(&event);
                                switch (event.type)
                                {
                                case SDL_KEYDOWN:
                                    switch (event.key.keysym.sym)
                                    {
                                    case SDLK_LEFT:
                                        if(b==1)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an2.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=4 ;
                                            break;
                                        }
                                        else if(b==2)
                                        {
                                            mute=IMG_Load("Buttons/musicoffan2.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1 ;
                                            break;
                                        }
                                        else if(b==3)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen2.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2 ;
                                            break;
                                        }
                                        else
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an2.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=3 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_RIGHT:
                                        if(b==1)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen2.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2 ;
                                            break;
                                        }
                                        else if(b==2)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an2.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=3 ;
                                            break;
                                        }
                                        else if(b==3)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an2.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=4 ;
                                            break;
                                        }
                                        else
                                        {
                                            mute=IMG_Load("Buttons/musicoffan2.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_DOWN:
                                        if(c==1)
                                        {
                                            mute=IMG_Load("Buttons/musicoff1.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan2.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            positionback=positionback1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            c=0 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_UP:
                                        if(c==0)
                                        {
                                            mute=IMG_Load("Buttons/musicoffan2.png");
                                            fullscreeen=IMG_Load("Buttons/fullscreen1.png");
                                            plus=IMG_Load("Buttons/+an1.png");
                                            moin=IMG_Load("Buttons/-an1.png");
                                            back=IMG_Load("Buttons/backan1.png");

                                            positionmute=positionmute1;
                                            positionfullscreen=positionfullscreen1;
                                            positionplus=positionplus1;
                                            positionmoin=positionmoin1;
                                            positionback=positionback1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            c=1 ;
                                            break;
                                        }
                                        break;
                                    case SDLK_RETURN:
                                        if(c==0)
                                        {
                                           p=0;
            				   SDL_Flip(screen);
                                        }
                                        if(c==1)
                                        {
                                            switch(b)
                                            {
                                            case 1:
                                                if (pausem==1)
                                                {
                                                    Mix_ResumeMusic();
                                                    pausem=0;
                                                }
                                                else if (pausem==0)
                                                {
                                                    Mix_PauseMusic();
                                                    pausem=1;
                                                }
                                                break;
                                            case 2:
                                                if (fullscreeeen==0)
                                                {
                                                    for(i=1; i<9; i++)
                                                    {
                                                        sprintf(ch,"1920/%d.png",i);
                                                        img[i]=IMG_Load(ch);
                                                    }
                                                    width=1920;
                                                    height=1080;
                                                    SDL_Init(SDL_INIT_VIDEO);

                                                    bg=IMG_Load("11f.png");
                                                    imageDeFond = IMG_Load("1f.png");

                                                    positionFond.x = 0;
                                                    positionFond.y = 0;
                                                    positionbg.x=0;
                                                    positionbg.y=0;
                                                    positionnew_game0.x = (width*43)/100; //380
                                                    positionnew_game0.y = (height*0.22)+100; //205
                                                    positioncredits0.x = (width*43)/100; //446
                                                    positioncredits0.y = (height*0.22)+250; //118
                                                    positionhelp0.x = (width*43)/100; //555
                                                    positionhelp0.y = (height*0.22)+400; //105
                                                    positionquit0.x = (width*43)/100;//467
                                                    positionquit0.y = (height*0.22)+550;//64
                                                    positionnew_game1.x = (width*43)/100;//370
                                                    positionnew_game1.y = (height*0.22)+100;//205
                                                    positioncredits1.x = (width*43)/100;//446
                                                    positioncredits1.y = (height*0.22)+250;//118
                                                    positionhelp1.x = (width*43)/100;//555
                                                    positionhelp1.y = (height*0.22)+400;//105
                                                    positionquit1.x =(width*43)/100;//467
                                                    positionquit1.y = (height*0.22)+550;//64
                                                    coordinatesposition.x=920; 
                                                    coordinatesposition.y=520; 

                                                    positionyes.x=(width*20)/100;
                                                    positionyes.y=(height*0.22)+200;
                                                    positionno.x=(width*60)/100;
                                                    positionno.y=(height*0.22)+200;
                                                    positionyes1.x=(width*20)/100;
                                                    positionyes1.y=(height*0.22)+200;
                                                    positionno1.x=(width*60)/100;
                                                    positionno1.y=(height*0.22)+200;

                                                    positionmute.x=(width*0.4)-400;
                                                    positionmute.y=(height*0.32);
                                                    positionfullscreen.x=(width*0.4);
                                                    positionfullscreen.y=(height*0.32);
                                                    positionplus.x=(width*0.4)+340;
                                                    positionplus.y=(height*0.32)+25;
                                                    positionmoin.x=(width*0.4)+480;
                                                    positionmoin.y=(height*0.32)+25;
                                                    positionback.x=25;
                                                    positionback.y=(height*0.84);
                                                    positionmute1.x=(width*0.4)-400;
                                                    positionmute1.y=(height*0.32);
                                                    positionfullscreen1.x=(width*0.4);
                                                    positionfullscreen1.y=(height*0.32);
                                                    positionplus1.x=(width*0.4)+340;
                                                    positionplus1.y=(height*0.32)+25;
                                                    positionmoin1.x=(width*0.4)+480;
                                                    positionmoin1.y=(height*0.32)+25;
                                                    positionback1.x=25;
                                                    positionback1.y=(height*0.84);

                                                    texte1position.x=10;
                                                    texte1position.y=height*0.93;
                                                    positionreturn.x=(width*40)/100;
                                                    positionreturn.y=200;

                                                    positionayed.x=(width*40)/100;
                                                    positionayed.x=(width*33)/100;
                                                    positionayed.y=(height*0.17)+100;
                                                    positionomri.x=(width*40)/100;
                                                    positionomri.y=(height*0.17)+180;
                                                    positionberraies.x=(width*40)/100;
                                                    positionberraies.y=(height*0.17)+260;
                                                    positionhamdi.x=(width*40)/100;
                                                    positionhamdi.y=(height*0.17)+340;
                                                    positionhamida.x=(width*40)/100;
                                                    positionhamida.y=(height*0.17)+420;
                                                    positionchargui.x=(width*40)/100;
                                                    positionchargui.y=(height*0.17)+500;

                                                    positionfontmute.x=(width*0.125)+200;
                                                    positionfontmute.y=(height*0.28);
                                                    positionfontfullscreen.x=(width*0.125)+540;
                                                    positionfontfullscreen.y=(height*0.28);
                                                    positionfontvolume.x=(width*0.125)+940;
                                                    positionfontvolume.y=(height*0.28);

                                                    positionnew_game = positionnew_game1;
                                                    positioncredits=positioncredits0;
                                                    positionhelp=positionhelp0;
                                                    positionquit=positionquit0;
                                                    positionyes=positionyes1;
                                                    positionno=positionno1;
                                                    positionmute=positionmute1;
                                                    positionfullscreen=positionfullscreen1;
                                                    positionplus=positionplus1;
                                                    positionmoin=positionmoin1;
                                                    positionback=positionback1;

                                                    SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
                                                    SDL_BlitSurface(coordinates,NULL,screen,&coordinatesposition);
                                                    SDL_BlitSurface(new_game, NULL,screen, &positionnew_game);
                                                    SDL_BlitSurface(credits, NULL,screen, &positioncredits);
                                                    SDL_BlitSurface(help, NULL,screen, &positionhelp);
                                                    SDL_BlitSurface(quit, NULL,screen, &positionquit);
                                                    SDL_BlitSurface(texte1,NULL,screen,&texte1position);
						    SDL_BlitSurface(titlegame,NULL,screen,&positiontitle);
                                                    SDL_BlitSurface(bg,NULL,screen,&positionbg);
                                                    SDL_BlitSurface(yes,NULL,screen,&positionyes);
                                                    SDL_BlitSurface(no,NULL,screen,&positionno);
                                                    SDL_BlitSurface(retuur,NULL,screen,&positionreturn);
                                                    SDL_BlitSurface(mute,NULL,screen,&positionmute);
                                                    SDL_BlitSurface(fullscreeen,NULL,screen,&positionfullscreen);
                                                    SDL_BlitSurface(plus,NULL,screen,&positionplus);
                                                    SDL_BlitSurface(moin,NULL,screen,&positionmoin);
                                                    SDL_BlitSurface(back,NULL,screen,&positionback);
                                                    SDL_BlitSurface(fmute,NULL,screen,&positionfontmute);
                                                    SDL_BlitSurface(ffullscreen,NULL,screen,&positionfontfullscreen);
                                                    SDL_BlitSurface(fvolume,NULL,screen,&positionfontvolume);
                                                    SDL_BlitSurface(ayed,NULL,screen,&positionayed);
                                                    SDL_BlitSurface(omri,NULL,screen,&positionomri);
                                                    SDL_BlitSurface(berraies,NULL,screen,&positionberraies);
                                                    SDL_BlitSurface(hamdi,NULL,screen,&positionhamdi);
                                                    SDL_BlitSurface(hamida,NULL,screen,&positionhamida);
                                                    SDL_BlitSurface(chargui,NULL,screen,&positionchargui);
                                                    screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                                                    fullscreeeen=1;
                                                }
                                                else if (fullscreeeen==1)
                                                {
                                                    for(i=1; i<9; i++)
                                                    {
                                                        sprintf(ch,"Background/%d.png",i);
                                                        img[i]=IMG_Load(ch);
                                                    }
                                                    bg=IMG_Load("2.png");
                                                    imageDeFond = IMG_Load("1.png");
                                                    width=1280;
                                                    height=720;
                                                    SDL_Init(SDL_INIT_VIDEO);

                                                    positionFond.x = 0;
                                                    positionFond.y = 0;
                                                    positionbg.x=0;
                                                    positionbg.y=0;
                                                    positionnew_game0.x = (width*40)/100; //380
                                                    positionnew_game0.y = height*0.22; //205
                                                    positioncredits0.x = (width*40)/100; //446
                                                    positioncredits0.y = (height*0.22)+100; //118
                                                    positionhelp0.x = (width*40)/100; //555
                                                    positionhelp0.y = (height*0.22)+200; //105
                                                    positionquit0.x = (width*40)/100;//467
                                                    positionquit0.y = (height*0.22)+300;//64
                                                    positionnew_game1.x = (width*40)/100;//370
                                                    positionnew_game1.y = (height*0.22);//205
                                                    positioncredits1.x = (width*40)/100;//446
                                                    positioncredits1.y = (height*0.22)+100;//118
                                                    positionhelp1.x = (width*40)/100;//555
                                                    positionhelp1.y = (height*0.22)+200;//105
                                                    positionquit1.x =(width*40)/100;//467
                                                    positionquit1.y = (height*0.22)+300;//64

                                                    positionfontmute.x=(width*0.125);
                                                    positionfontmute.y=(height*0.28);
                                                    positionfontfullscreen.x=(width*0.125)+340;
                                                    positionfontfullscreen.y=(height*0.28);
                                                    positionfontvolume.x=(width*0.125)+740;
                                                    positionfontvolume.y=(height*0.28);

                                                    positionyes.x=(width*20)/100;
                                                    positionyes.y=(height*0.22)+200;
                                                    positionno.x=(width*60)/100;
                                                    positionno.y=(height*0.22)+200;
                                                    positionyes1.x=(width*20)/100;
                                                    positionyes1.y=(height*0.22)+200;
                                                    positionno1.x=(width*60)/100;
                                                    positionno1.y=(height*0.22)+200;

                                                    positionmute.x=100;
                                                    positionmute.y=225;
                                                    positionfullscreen.x=500;
                                                    positionfullscreen.y=225;
                                                    positionplus.x=840;
                                                    positionplus.y=250;
                                                    positionmoin.x=980;
                                                    positionmoin.y=250;
                                                    positionback.x=25;
                                                    positionback.y=(height*0.84);
                                                    positionmute1.x=100;
                                                    positionmute1.y=225;
                                                    positionfullscreen1.x=500;
                                                    positionfullscreen1.y=225;
                                                    positionplus1.x=840;
                                                    positionplus1.y=250;
                                                    positionmoin1.x=980;
                                                    positionmoin1.y=250;
                                                    positionback1.x=25;
                                                    positionback1.y=(height*0.84);
                                                    coordinatesposition.x=920;
                                                    coordinatesposition.y=520;
                                                    texte1position.x=10;
                                                    texte1position.y=height*0.93;
                                                    positionreturn.x=(width*35)/100;
                                                    positionreturn.y=200;

                                                    positionayed.x=(width*33)/100;
                                                    positionayed.y=(height*0.17);
                                                    positionomri.x=(width*40)/100;
                                                    positionomri.y=(height*0.17)+80;
                                                    positionberraies.x=(width*40)/100;
                                                    positionberraies.y=(height*0.17)+160;
                                                    positionhamdi.x=(width*40)/100;
                                                    positionhamdi.y=(height*0.17)+240;
                                                    positionhamida.x=(width*40)/100;
                                                    positionhamida.y=(height*0.17)+320;
                                                    positionchargui.x=(width*40)/100;
                                                    positionchargui.y=(height*0.17)+400;

                                                    positionnew_game = positionnew_game1;
                                                    positioncredits=positioncredits0;
                                                    positionhelp=positionhelp0;
                                                    positionquit=positionquit0;
                                                    positionyes=positionyes1;
                                                    positionno=positionno1;
                                                    positionmute=positionmute1;
                                                    positionfullscreen=positionfullscreen1;
                                                    positionplus=positionplus1;
                                                    positionmoin=positionmoin1;
                                                    positionback=positionback1;
                                                    screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
                                                    fullscreeeen=0;
                                                }
                                                break;
                                            case 3:
                                                if(y!=1)
                                                {
                                                    y=y-1;
                                                    Mix_VolumeMusic(MIX_MAX_VOLUME/y);
                                                }
                                                break;
                                            case 4:
                                                y=y+1;
                                                Mix_VolumeMusic(MIX_MAX_VOLUME/y);
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                                if(p==0)
                                {
                                    z=0;
                                }
                            }
                        }
                        break;
                    case 4:
                        z=1;
                        while(z)
                        {
                            int p=1,b=1;
                            positionyes.x=(width*20)/100;
                            positionyes.y=(height*0.22)+200;
                            positionno.x=(width*60)/100;
                            positionno.y=(height*0.22)+200;
                            positionyes1.x=(width*20)/100;
                            positionyes1.y=(height*0.22)+200;
                            positionno1.x=(width*60)/100;
                            positionno1.y=(height*0.22)+200;
                            yes=IMG_Load("yesan1.png");
                            no=IMG_Load("noan1.png");

                            SDL_BlitSurface(bg,NULL,screen,&positionbg);
                            SDL_BlitSurface(yes,NULL,screen,&positionyes);
                            SDL_BlitSurface(no,NULL,screen,&positionno);
                            SDL_BlitSurface(retuur,NULL,screen,&positionreturn);
                            SDL_Flip(screen);
                            while(p)
                            {
                                SDL_BlitSurface(yes,NULL,screen,&positionyes);
                                SDL_BlitSurface(no,NULL,screen,&positionno);
                                SDL_Flip(screen);
                                SDL_WaitEvent(&event);
                                switch (event.type)
                                {
                                case SDL_MOUSEBUTTONDOWN:
				 {
                                    if (((event.motion.x>(((width*20)/100)))&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<(((width*20)/100)+217))&&(event.motion.y<(height*0.22)+371)))
                                    {
                                        return 99;
                                    }
                                    else if (((event.motion.x>(((width*60)/100)))&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<(((width*60)/100)+217))&&(event.motion.y<(height*0.22)+371)))
                                    {
                                        p=0;
                                    }
                                    break;
				 }
                                case SDL_KEYDOWN:
                                    switch (event.key.keysym.sym)
                                    {
                                    case SDLK_LEFT:
                                        if(b==1)
                                        {
                                            yes=IMG_Load("Buttons/yesan2.png");
                                            no=IMG_Load("Buttons/noan1.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2;
                                            break;
                                        }
                                        else
                                        {
                                            yes=IMG_Load("Buttons/yesan1.png");
                                            no=IMG_Load("Buttons/noan2.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1;
                                            break;
                                        }
                                        break;
                                    case SDLK_RIGHT:
                                        if(b==1)
                                        {
                                            yes=IMG_Load("Buttons/yesan2.png");
                                            no=IMG_Load("Buttons/noan1.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=2;
                                            break;
                                        }
                                        else
                                        {
                                            yes=IMG_Load("Buttons/yesan1.png");
                                            no=IMG_Load("Buttons/noan2.png");
                                            positionyes=positionyes1;
                                            positionno=positionno1;
                                            if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                                            {
                                                return 1;
                                            }
                                            b=1;
                                            break;
                                        }
                                        break;
                                    case SDLK_RETURN:
                                    {
                                        switch(b)
                                        {
                                        case 1:
                                            p=0;
                                            break;
                                        case 2:
                                            return 99;
                                            break;
                                        }
                                        break;
                                    }
                                    }
                                    break;
                                }
                            }
                            if(p==0)
                            {
                                z=0;
                            }
                        }
                        break;
                    }
                    break;
                case SDLK_UP:
                    if (a==4)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest2.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game1;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=3;
                        break;
                    }
                    else if (a==1)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest2.png");
                        positionnew_game = positionnew_game1;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=4;
                        break;
                    }
                    else if (a==2)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest2.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game1;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=1;
                        break;
                    }
                    else
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest2.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game1;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=2;
                        break;
                    }
                case SDLK_DOWN:
                    if (a==1)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest2.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game0;
                        positioncredits=positioncredits;
                        positionhelp=positionhelp0;
                        positionquit=positionquit1;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=2;
                        break;
                    }
                    else if (a==4)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest2.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game0;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=1;
                        break;
                    }
                    else if (a==3)
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest.png");
                        quit = IMG_Load ("Buttons/quittest2.png");
                        positionnew_game = positionnew_game1;
                        positioncredits=positioncredits0;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=4;
                        break;
                    }
                    else
                    {
			SDL_Delay(100);
                        new_game=IMG_Load ("Buttons/playtest.png");
                        credits = IMG_Load ("Buttons/creditstest.png");
                        help = IMG_Load ("Buttons/settingstest2.png");
                        quit = IMG_Load ("Buttons/quittest.png");
                        positionnew_game = positionnew_game0;
                        positioncredits=positioncredits1;
                        positionhelp=positionhelp0;
                        positionquit=positionquit0;
                        if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                        {
                            return 1;
                        }
                        a=3;
                        break;
                    }
                }
                break;
            /*case SDL_MOUSEMOTION:
                if ((event.motion.x>(((width*40)/100)))&&(event.motion.y>(height*0.22))&&(event.motion.x<(((width*40)/100)+263))&&(event.motion.y<(height*0.22)+89))
                {
                    new_game=IMG_Load ("Buttons/playtest2.png");
                    credits = IMG_Load ("Buttons/creditstest.png");
                    help = IMG_Load ("Buttons/settingstest.png");
                    quit = IMG_Load ("Buttons/quittest.png");
                    positionnew_game = positionnew_game1;
                    positioncredits=positioncredits0;
                    positionhelp=positionhelp0;
                    positionquit=positionquit0;
                    if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                    {
                       return 1;
                    }
                    a=1;
                    break;
                }
                else if ((event.motion.x>(((width*40)/100)))&&(event.motion.y>(height*0.22)+100)&&(event.motion.x<(((width*40)/100)+263))&&(event.motion.y<(height*0.22)+189))
                {
                    new_game=IMG_Load ("Buttons/playtest.png");
                    credits = IMG_Load ("Buttons/creditstest2.png");
                    help = IMG_Load ("Buttons/settingstest.png");
                    quit = IMG_Load ("Buttons/quittest.png");
                    positionnew_game = positionnew_game0;
                    positioncredits=positioncredits0;
                    positionhelp=positionhelp0;
                    positionquit=positionquit0;
                    if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                    {
                       return 1;
                    }
                    a=2;
                    break;
                }
                else if ((event.motion.x>(((width*40)/100)))&&(event.motion.y>(height*0.22)+300)&&(event.motion.x<(((width*40)/100)+263))&&(event.motion.y<(height*0.22)+389))
                {
                    new_game=IMG_Load ("Buttons/playtest.png");
                    credits = IMG_Load ("Buttons/creditstest.png");
                    help = IMG_Load ("Buttons/settingstest.png");
                    quit = IMG_Load ("Buttons/quittest2.png");
                    positionnew_game = positionnew_game0;
                    positioncredits=positioncredits1;
                    positionhelp=positionhelp0;
                    positionquit=positionquit0;
                    if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                    {
                       return 1;
                    }
                    a=3;
                    break;
                }
                else if ((event.motion.x>(width*40)/100)&&(event.motion.y>(height*0.22)+200)&&(event.motion.x<((width*40)/100)+263)&&(event.motion.y<(height*0.22)+289))
                {
                    new_game=IMG_Load ("Buttons/playtest.png");
                    credits = IMG_Load ("Buttons/creditstest.png");
                    help = IMG_Load ("Buttons/settingstest2.png");
                    quit = IMG_Load ("Buttons/quittest.png");
                    positionnew_game = positionnew_game0;
                    positioncredits=positioncredits0;
                    positionhelp=positionhelp1;
                    positionquit=positionquit0;
                    /*if( Mix_PlayChannel( -1, bip, 0 ) == -1 )
                    {
                       return 1;
                    }
                    a=4;
                    break;
                }
                break;*/
            }
            SDL_BlitSurface(imageDeFond, NULL,screen, &positionFond);
            SDL_BlitSurface(coordinates,NULL,screen,&coordinatesposition);
            SDL_BlitSurface(new_game, NULL,screen, &positionnew_game);
            SDL_BlitSurface(credits, NULL,screen, &positioncredits);
            SDL_BlitSurface(help, NULL,screen, &positionhelp);
            SDL_BlitSurface(quit, NULL,screen, &positionquit);
            SDL_BlitSurface(texte1,NULL,screen,&texte1position);
	    SDL_BlitSurface(titlegame,NULL,screen,&positiontitle);
            SDL_Flip(screen);
        }
    }
    SDL_FreeSurface(imageDeFond);
    Mix_FreeMusic(music);
    Mix_FreeChunk( bip );
    SDL_FreeSurface(texte1);
    SDL_FreeSurface(titlegame);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_QUIT;
}


