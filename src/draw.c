/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** Main file for draw
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/raycasting.h"

void draw(Raycasting_t ray)
{
    sfRenderWindow_clear(ray.window, sfCyan);

    // Draw tiles
    for (int i = 0; i < 64; i++)
        sfRenderWindow_drawRectangleShape(ray.window, ray.map.tiles[i], NULL);
    // Draw user & rays
    sfRenderWindow_drawRectangleShape(ray.window, ray.user.user, NULL);
    sfRenderWindow_drawVertexArray(ray.window, ray.line.lines, NULL);
    sfRenderWindow_drawVertexArray(ray.window, ray.line2.lines, NULL);
    // Draw map
    for (int i = 0; i < ray.r; i++) {
        sfRenderWindow_drawVertexArray(ray.window, ray.line3[i].lines, NULL);
        sfRenderWindow_drawVertexArray(ray.window, ray.quads[i].quads, NULL);
    }
    sfRenderWindow_display(ray.window);
}