/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main file for Raycasting
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/raycasting.h"

char map[] = {
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,1,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,1,1,1,1,1,1,1,
};

float dist(float ax, float ay, float bx, float by, float ang)
{
    return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void create_line(Raycasting_t *ray)
{
    ray->line.lines = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(ray->line.lines, sfLines);
    sfVertexArray_resize(ray->line.lines, 2);

    sfVertexArray_append(ray->line.lines, ray->line.one);
    sfVertexArray_append(ray->line.lines, ray->line.two);

    ray->line2.lines = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(ray->line2.lines, sfLines);
    sfVertexArray_resize(ray->line2.lines, 2);
    sfVertexArray_append(ray->line2.lines, ray->line2.one);
    sfVertexArray_append(ray->line2.lines, ray->line2.two);


}

void create_map(Raycasting_t *ray)
{
    ray->map.mapX = 8;
    ray->map.mapY = 8;
    ray->map.size.x = 64;
    ray->map.size.y = 64;
    ray->map.green = sfColor_fromRGB(43, 255, 82);
    ray->map.side_green = sfColor_fromRGB(0, 209, 39);

    sfVector2f initialized_pos = {0, 0};

    // Create tiles as rectangles;
    for (int i = 0; i < 64; i++)
        ray->map.tiles[i] = create_rec(initialized_pos, ray->map.size, sfRed, NULL);

    int xo, yo = 0;
    sfVector2f o_pos = {xo, yo};

    for (int y = 0; y < ray->map.mapY; y++) {
        for (int x = 0; x < ray->map.mapX; x++) {
            xo = x * 64;
            yo = y * 64;
            o_pos.x = xo;
            o_pos.y = yo;
            
            // set tile position
            sfRectangleShape_setPosition(ray->map.tiles[y * ray->map.mapX + x], o_pos);

            // set tile color
            if (map[y * ray->map.mapX + x] == 1)
                sfRectangleShape_setFillColor(ray->map.tiles[y * ray->map.mapX + x], sfBlack);
            else
                sfRectangleShape_setFillColor(ray->map.tiles[y * ray->map.mapX + x], sfWhite);
        }
    }
}

void create_user(Raycasting_t *ray)
{
    ray->user.size.x = 10;
    ray->user.size.y = 10;
    ray->user.pos.x = 300;
    ray->user.pos.y = 300;
    ray->user.move.x = 10;
    ray->user.move.y = 0;
    ray->user.user = create_rec(ray->user.pos, ray->user.size, sfRed, NULL);
}

void create_all(Raycasting_t *ray)
{
    ray->window = create_renderwindow(WIDTH, HEIGHT, BPP, "Raycasting");
    ray->color = sfColor_fromRGB(150, 150, 150);

    create_user(ray);
    create_map(ray);
    create_line(ray);
}

int main(void)
{
    Raycasting_t ray;
    
    create_all(&ray);
    while (sfRenderWindow_isOpen(ray.window)) {
        error_handler(&ray);
        loop(&ray);
        draw(ray);
    }
    destroy(ray);
    return (0);
}
