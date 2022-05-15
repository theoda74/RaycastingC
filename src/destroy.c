/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** Main file for destroy
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/my.h"

void destroy(Raycasting_t ray)
{
    sfRectangleShape_destroy(ray.user.user);
    for (int i = 0; i < 64; i++)
        sfRectangleShape_destroy(ray.map.tiles[i]);

    sfRenderWindow_destroy(ray.window);
}