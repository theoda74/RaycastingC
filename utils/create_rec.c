/*
** EPITECH PROJECT, 2022
** create_rec.c
** File description:
** Create rec
*/

#include <SFML/Graphics.h>

sfRectangleShape *create_rec(sfVector2f pos, sfVector2f size, sfColor color,
sfTexture *texture)
{
    sfRectangleShape *rec = sfRectangleShape_create();

    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setFillColor(rec, color);
    sfRectangleShape_setTexture(rec, texture, sfFalse);
    return (rec);
}
