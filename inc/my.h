/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my h
*/

#ifndef MY_H_
    #define MY_H_

    #define WIDTH   1024
    #define HEIGHT  512
    #define BPP     32
    
    #define PI      3.14159265359
    #define P2 PI/2
    #define P3 3*PI/2
    #define DR 0.0174533

typedef struct Quads_s {
    sfVertexArray *quads;
    sfVertex one;
    sfVertex two;
    sfVertex three;
    sfVertex four;
} Quads_t;

typedef struct Line_s {
    sfVertexArray *lines;
    sfVertex one;
    sfVertex two;
} Line_t;

typedef struct Map_s {
    sfColor green;
    sfColor side_green;
    
    int mapX, mapY;
    sfVector2f size;
    sfRectangleShape *tiles[64];
} Map_t;

typedef struct User_s {
    sfRectangleShape *user;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f move;
    float pdx, pdy, pa;
} User_t;

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
void drawRays(Raycasting_t *);

#endif