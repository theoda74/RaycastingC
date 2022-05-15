/*
** EPITECH PROJECT, 2022
** map.h
** File description:
** map h
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>

typedef struct Map_s {
    sfColor green;
    sfColor side_green;
    
    int mapX;
    int mapY;
    sfVector2f size;
    sfRectangleShape *tiles[64];
} Map_t;

#endif