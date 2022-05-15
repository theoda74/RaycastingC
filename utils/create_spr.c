/*
** EPITECH PROJECT, 2022
** create_spr.c
** File description:
** Create spr
*/

#include <SFML/Graphics.h>

sfSprite *create_sprite(sfVector2f pos, sfVector2f scale, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}
