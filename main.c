#include <stdio.h>
#include <stdlib.h>
#include "allegro.h"
#include "InitAllegro.h"
#include "CONSTANTES.h"
#include "choix.h"
#include <time.h>

int main()
{
    InitAllegro();
    ///Initialisations
    unsigned int tab[12] = { 0 };

    ///Chargement des images menus
    BITMAP *menu1, *menu1on, *menu2, *menu2on, *fond, *buffer;
    menu1 = load_bitmap("images/menu1.bmp", NULL);
    menu1on = load_bitmap("images/menu1clic.bmp", NULL);
    menu2 = load_bitmap("images/menu2.bmp", NULL);
    menu2on = load_bitmap("images/menu2clic.bmp", NULL);
    fond = load_bitmap("images/fond.bmp", NULL);
    buffer = create_bitmap(1280, 720);
    ///Fin chargement

    ///Chargement des images des jeux
    t_images images;
    images.jeu1 = load_bitmap("images/RL.bmp", NULL);
    images.jeu2 = load_bitmap("images/ETS.bmp", NULL);
    images.jeu3 = load_bitmap("images/csgo.bmp", NULL);
    images.jeu4 = load_bitmap("images/arma.bmp", NULL);
    images.jeu5 = load_bitmap("images/paladins.bmp", NULL);
    images.jeu6 = load_bitmap("images/businesstour.bmp", NULL);
    images.jeu7 = load_bitmap("images/minecraft.bmp", NULL);
    images.jeu8 = load_bitmap("images/brawl.bmp", NULL);
    images.jeu9 = load_bitmap("images/dofus.bmp", NULL);
    images.jeu10 = load_bitmap("images/payday.bmp", NULL);
    images.jeu11 = load_bitmap("images/TM.bmp", NULL);
    images.jeu12 = load_bitmap("images/trickytowers.bmp", NULL);
    ///Fin du chargement

    while(!key[KEY_ESC])
    {
        blit(fond, buffer, 0, 0, 0, 0, 1280, 720);

        if(mouse_x >= 390 && mouse_x <= 890 && mouse_y >= 200 && mouse_y <= 300)
        {
            masked_blit(menu1on, buffer, 0, 0, 390, 200, 500, 100);
            if(mouse_b & 1)     { tirage(images, tab); }
        }
        else{
            masked_blit(menu1, buffer, 0, 0, 390, 200, 500, 100);
        }
        if(mouse_x >= 390 && mouse_x <= 890 && mouse_y >= 450 && mouse_y <= 550)
        {
            masked_blit(menu2on, buffer, 0, 0, 390, 450, 500, 100);
            if(mouse_b & 1)     { choixJeux(images, tab); }
        }
        else{
            masked_blit(menu2, buffer, 0, 0, 390, 450, 500, 100);
        }

        blit(buffer, screen, 0, 0, 0, 0, 1280, 720);
    }

    return 0;
}END_OF_MAIN();
