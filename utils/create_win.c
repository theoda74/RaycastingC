/*
** EPITECH PROJECT, 2022
** create_win.c
** File description:
** Create win
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_renderwindow(int x, int y, int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose,
    NULL));
}