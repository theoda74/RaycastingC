/*
** EPITECH PROJECT, 2022
** quads.h
** File description:
** quads h
*/

#ifndef QUADS_H_
    #define QUADS_H_

    #include <SFML/Graphics.h>

typedef struct Quads_s {
    sfVertexArray *quads;
    sfVertex one;
    sfVertex two;
    sfVertex three;
    sfVertex four;
} Quads_t;

#endif