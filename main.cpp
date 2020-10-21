#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <fmodex/fmod.h>

void random(), pause(), animation();

int main()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *bouton = NULL;
    SDL_Event event;
    SDL_Rect positionFond, positionBouton;
    int continuer = 1;

    positionFond.x = 0;
    positionFond.y = 0;
    positionBouton.x = 300;
    positionBouton.y = 125;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("icon.jpg"), NULL);

    ecran = SDL_SetVideoMode(850, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("The Mighty Game Chooser", NULL);

    imageDeFond = IMG_Load("fond.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    bouton = IMG_Load("bouton.png");
    SDL_BlitSurface(bouton, NULL, ecran, &positionBouton);
    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;

            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x > 300 && event.button.x < 550 && event.button.y > 125 && event.button.y < 375)
                {
                    random();
                }

        }

    }
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bouton);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void animation()
{
    SDL_Surface *ecran = NULL, *paragon = NULL, *paladins = NULL, *arma = NULL, *csgo = NULL, *ets = NULL, *white = NULL;
    SDL_Rect positionFond;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(850, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    paragon = IMG_Load("paragon.jpg");
    paladins = IMG_Load("paladins.jpg");
    arma = IMG_Load("arma.jpg");
    csgo = IMG_Load("csgo.jpg");
    ets = IMG_Load("ets.jpg");

    for(int i = 1; i <= 20; i++){
        if i
    }
}




void random()
{
    SDL_Surface *ecran = NULL, *paragon = NULL, *paladins = NULL, *arma = NULL, *csgo = NULL, *ets = NULL, *white = NULL;
    SDL_Rect positionFond;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(850, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    FMOD_SYSTEM *system;
    FMOD_SOUND *chose;

    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
    FMOD_System_CreateSound(system, "chose.mp2", FMOD_CREATESAMPLE, 0, &chose);

    white = IMG_Load("white.jpg");
    SDL_BlitSurface(white, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    int jeu = 0 ;


    positionFond.x = 0;
    positionFond.y = 0;

    srand(time(NULL));
    jeu = rand() % 5;

    paragon = IMG_Load("paragon.jpg");
    paladins = IMG_Load("paladins.jpg");
    arma = IMG_Load("arma.jpg");
    csgo = IMG_Load("csgo.jpg");
    ets = IMG_Load("ets.jpg");

    switch(jeu)
    {
        case 0:
            FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, chose, 0, NULL);
            SDL_Delay(4200);
            SDL_BlitSurface(paragon, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            break;
        case 1:
            FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, chose, 0, NULL);
            SDL_Delay(4200);
            SDL_BlitSurface(paladins, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            break;
        case 2:
            FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, chose, 0, NULL);
            SDL_Delay(4200);
            SDL_BlitSurface(arma, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            break;
        case 3:
            FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, chose, 0, NULL);
            SDL_Delay(4200);
            SDL_BlitSurface(csgo, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            break;
        case 4:
            FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, chose, 0, NULL);
            SDL_Delay(4200);
            SDL_BlitSurface(ets, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            break;
    }

    FMOD_Sound_Release(chose);
    FMOD_System_Close(system);
    FMOD_System_Release(system);
    SDL_FreeSurface(paragon);
    SDL_FreeSurface(paladins);
    SDL_FreeSurface(arma);
    SDL_FreeSurface(csgo);
    SDL_FreeSurface(ets);
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}
