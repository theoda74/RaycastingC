/*
** EPITECH PROJECT, 2022
** event_handler.c
** File description:
** Event handler main file
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/my.h"
#include <math.h>

void error_handler(Raycasting_t *ray)
{
    while (sfRenderWindow_pollEvent(ray->window, &ray->event)) {
        if (ray->event.type == sfEvtClosed)
            sfRenderWindow_close(ray->window);
        
        if (ray->event.type == sfEvtKeyPressed && ray->event.key.code == sfKeyEscape)
            sfRenderWindow_close(ray->window);

        if (ray->event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyQ)) {
                ray->user.pa -= 0.1;
                if (ray->user.pa < 0)
                    ray->user.pa += 2 * PI;
                ray->user.pdx = cos(ray->user.pa) * 5;
                ray->user.pdy = sin(ray->user.pa) * 5;
            }
            if (sfKeyboard_isKeyPressed(sfKeyD)) {
                ray->user.pa += 0.1;
                if (ray->user.pa > (2 * PI))
                    ray->user.pa -= 2 * PI;
                ray->user.pdx = cos(ray->user.pa) * 5;
                ray->user.pdy = sin(ray->user.pa) * 5;
            }
            if (sfKeyboard_isKeyPressed(sfKeyZ)) {
                ray->user.pos.x += ray->user.pdx;
                ray->user.pos.y += ray->user.pdy;
            }
            if (sfKeyboard_isKeyPressed(sfKeyS)) {
                ray->user.pos.x -= ray->user.pdx;
                ray->user.pos.y -= ray->user.pdy;
            }

        }
    }
}