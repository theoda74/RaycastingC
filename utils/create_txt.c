/*
** EPITECH PROJECT, 2022
** create_txt.c
** File description:
** Create txt
*/

#include <SFML/Graphics.h>

sfText *create_txt(sfVector2f pos, sfFont *font, sfColor color, char *string)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setFillColor(text, color);
    sfText_setString(text, string);
    sfText_setPosition(text, pos);
}
