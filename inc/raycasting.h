/*
** EPITECH PROJECT, 2022
** raycasting.h
** File description:
** raycasting h
*/

#ifndef RAY_H_
    #define RAY_H_

    #define WIDTH   1024
    #define HEIGHT  512
    #define BPP     32
    
    #define PI      3.14159265359
    #define DR      0.0174533

    #include "quads.h"
    #include "lines.h"
    #include "map.h"
    #include "user.h"

typedef struct Raycasting_s {
    sfRenderWindow *window;
    sfEvent event;
    sfColor color;
    User_t user;
    Map_t map;
    Line_t line;
    Line_t line2;
    Line_t line3[60];
    Line_t line4[60];
    Quads_t quads[60];
    int r;
} Raycasting_t;

void drawRays(Raycasting_t *);
float dist(float, float, float, float, float);
sfRectangleShape *create_rec(sfVector2f, sfVector2f, sfColor,sfTexture *);
sfSprite *create_sprite(sfVector2f, sfVector2f, sfTexture *);
sfText *create_txt(sfVector2f, sfFont *, sfColor, char *);
sfRenderWindow *create_renderwindow(int, int, int, char *);

void error_handler(Raycasting_t *);
void draw(Raycasting_t);
void destroy(Raycasting_t);
void loop(Raycasting_t *);

#endif