/*
** EPITECH PROJECT, 2022
** loop.c
** File description:
** Main file for loop
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/my.h"

void loop(Raycasting_t *ray)
{

    ray->user.pdx = cos(ray->user.pa) * 5;
    ray->user.pdy = sin(ray->user.pa) * 5;
    drawRays(ray);
    sfRectangleShape_setPosition(ray->user.user, ray->user.pos);

}
