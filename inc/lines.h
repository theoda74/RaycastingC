/*
** EPITECH PROJECT, 2022
** lines.h
** File description:
** lines h
*/

#ifndef LINES_H_
    #define LINES_H_

    #include <SFML/Graphics.h>

    #define P2      PI/2
    #define P3      3*PI/2

typedef struct Line_s {
    sfVertexArray *lines;
    sfVertex one;
    sfVertex two;
} Line_t;

#endif