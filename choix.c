#include <stdio.h>
#include <stdlib.h>
#include "CONSTANTES.h"
#include "choix.h"
#include <time.h>

void choixJeux(t_images images, unsigned int* tab)
{
    BITMAP* fond, *buffer, *question, *tick;
    int verifDeclic = 1;
    int sourisX = -1, sourisY = -1; //Permet la vérification de la position du clic

    buffer = create_bitmap(1280, 720);
    question = load_bitmap("images/question.bmp", NULL);
    fond = load_bitmap("images/fond2.bmp", NULL);
    tick = load_bitmap("images/tick.bmp", NULL);


    masked_blit(question, fond, 0, 0, 75, 50, 1000, 60);
    stretch_blit(images.jeu1, fond, 0, 0, 1280, 720, 85, 150, 213, 120);
    stretch_blit(images.jeu2, fond, 0, 0, 1280, 720, 384, 150, 213, 120);
    stretch_blit(images.jeu3, fond, 0, 0, 1280, 720, 682, 150, 213, 120);
    stretch_blit(images.jeu4, fond, 0, 0, 1280, 720, 981, 150, 213, 120);
    stretch_blit(images.jeu5, fond, 0, 0, 1280, 720, 85, 330, 213, 120);
    stretch_blit(images.jeu6, fond, 0, 0, 1280, 720, 384, 330, 213, 120);
    stretch_blit(images.jeu7, fond, 0, 0, 1280, 720, 682, 330, 213, 120);
    stretch_blit(images.jeu8, fond, 0, 0, 1280, 720, 981, 330, 213, 120);
    stretch_blit(images.jeu9, fond, 0, 0, 1280, 720, 85, 510, 213, 120);
    stretch_blit(images.jeu10, fond, 0, 0, 1280, 720, 384, 510, 213, 120);
    stretch_blit(images.jeu11, fond, 0, 0, 1280, 720, 682, 510, 213, 120);
    stretch_blit(images.jeu12, fond, 0, 0, 1280, 720, 981, 510, 213, 120);

    while((!key[KEY_ENTER])&&(!key[KEY_ENTER_PAD]))
    {
        blit(fond, buffer, 0, 0, 0, 0, 1280, 720);

        if((mouse_b & 1)&&(verifDeclic == 0)) //Si clic gauche avec la souris
        {
            verifDeclic++;
            if(mouse_x >= 85 && mouse_x <= 298)             { sourisX = 0; }
            else if(mouse_x >= 384 && mouse_x <= 597)       { sourisX = 1; }
            else if(mouse_x >= 682 && mouse_x <= 895)       { sourisX = 2; }
            else if(mouse_x >= 981 && mouse_x <= 1194)      { sourisX = 3; }
            else                                            { sourisX = -1; }

            if(mouse_y >= 150 && mouse_y <= 270)            { sourisY = 0; }
            else if(mouse_y >= 330 && mouse_y <= 450)       { sourisY = 1; }
            else if(mouse_y >= 510 && mouse_y <= 630)       { sourisY = 2; }
            else                                            { sourisY = -1; }

            if((sourisX != -1)&&(sourisY != -1))
            {
                if(tab[sourisX + 4*sourisY] == 0)           { tab[sourisX + 4*sourisY]++; }
                else if(tab[sourisX + 4*sourisY] == 1)      { tab[sourisX + 4*sourisY]--; }
            }
        }

        if((!(mouse_b & 1)) && verifDeclic == 1)      { verifDeclic--; }

        if(tab[0] == 1)     masked_blit(tick, buffer, 0, 0, 280, 250, 40, 40);
        if(tab[1] == 1)     masked_blit(tick, buffer, 0, 0, 579, 250, 40, 40);
        if(tab[2] == 1)     masked_blit(tick, buffer, 0, 0, 877, 250, 40, 40);
        if(tab[3] == 1)     masked_blit(tick, buffer, 0, 0, 1171, 250, 40, 40);
        if(tab[4] == 1)     masked_blit(tick, buffer, 0, 0, 280, 430, 40, 40);
        if(tab[5] == 1)     masked_blit(tick, buffer, 0, 0, 579, 430, 40, 40);
        if(tab[6] == 1)     masked_blit(tick, buffer, 0, 0, 877, 430, 40, 40);
        if(tab[7] == 1)     masked_blit(tick, buffer, 0, 0, 1171, 430, 40, 40);
        if(tab[8] == 1)     masked_blit(tick, buffer, 0, 0, 280, 610, 40, 40);
        if(tab[9] == 1)     masked_blit(tick, buffer, 0, 0, 579, 610, 40, 40);
        if(tab[10] == 1)     masked_blit(tick, buffer, 0, 0, 877, 610, 40, 40);
        if(tab[11] == 1)     masked_blit(tick, buffer, 0, 0, 1171, 610, 40, 40);

        blit(buffer, screen, 0, 0, 0, 0, 1280, 720);

    }

    destroy_bitmap(buffer); destroy_bitmap(question); destroy_bitmap(fond); destroy_bitmap(tick);
}


void tirage(t_images images, unsigned int* tab)
{
    int i, j = 0;
    unsigned int comptage = 0, * tirage;

    for(i = 0; i<12; i++)
    {
        if(tab[i] == 1)     { comptage++; }
    }


    tirage = (unsigned int*)malloc(comptage * sizeof(unsigned int));

    for(i = 0; i<comptage; i++)
    {
        while(tab[j]!=1)
        {
            j++;
        }
        tirage[i] = j;
        j++;
    }
    animation(images, tirage, comptage);
    free(tirage);
}

int animation(t_images images, unsigned int* tirage, unsigned int comptage)
{
    if(comptage == 0)   { return 0; }
    SAMPLE* clic;
    clic = load_sample("sons/clic.wav"); // On charge le son
    int i, random = -1, tours;
    BITMAP ** roulette, *buffer;
    buffer = create_bitmap(1280, 720);
    roulette = (BITMAP**)malloc(comptage*sizeof(BITMAP*));

    for(i = 0; i<comptage; i++)
    {
        roulette[i] = create_bitmap(1280,720);
        switch(tirage[i])
        {
            case 0:
                blit(images.jeu1, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 1:
                blit(images.jeu2, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 2:
                blit(images.jeu3, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 3:
                blit(images.jeu4, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 4:
                blit(images.jeu5, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 5:
                blit(images.jeu6, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 6:
                blit(images.jeu7, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 7:
                blit(images.jeu8, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 8:
                blit(images.jeu9, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 9:
                blit(images.jeu10, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 10:
                blit(images.jeu11, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
            case 11:
                blit(images.jeu12, roulette[i], 0, 0, 0, 0, 1280, 720);
                break;
        }
    }
    if(comptage > 8)
    {
        for(tours=0; tours<3; tours++)
        {
            for(i = 0; i<comptage; i++)
            {
                blit(roulette[i], buffer, 0, 0, 0, 0, 1280, 720);
                blit(buffer, screen, 0, 0, 0, 0, 1280, 720);
                play_sample(clic, 255, 127, 1000, 0);
                rest(100);
            }
        }
    }
    else{
        for(tours=0; tours<3; tours++)
        {
            for(i = 0; i<comptage; i++)
            {
                blit(roulette[i], buffer, 0, 0, 0, 0, 1280, 720);
                blit(buffer, screen, 0, 0, 0, 0, 1280, 720);
                play_sample(clic, 255, 127, 1000, 0);
                rest(150);
            }
        }
    }
    random = rand()%comptage;
    blit(roulette[random], buffer, 0, 0, 0, 0, 1280, 720);
    if(random != comptage-1)      { play_sample(clic, 255, 127, 1000, 0); }
    blit(buffer, screen, 0, 0, 0, 0, 1280, 720);
    while((!key[KEY_ENTER]) && (!key[KEY_ENTER_PAD]) && (!key[KEY_ESC]))
    {
    }

    for(i = 0; i < comptage; i++)
    {
        destroy_bitmap(roulette[i]);
    }
    destroy_bitmap(buffer); destroy_sample(clic); free(roulette);
    return 0;

}
