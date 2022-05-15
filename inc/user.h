/*
** EPITECH PROJECT, 2022
** user.h
** File description:
** user h
*/

#ifndef USER_H_
    #define USER_H_

    #include <SFML/Graphics.h>

typedef struct User_s {
    sfRectangleShape *user;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f move;
    float pdx, pdy, pa;
} User_t;

#endif