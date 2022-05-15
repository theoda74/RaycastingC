/*
** EPITECH PROJECT, 2022
** rays_walls.c
** File description:
** Rays & Wall display
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/raycasting.h"

char map_w[] = {
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,1,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,1,1,1,1,1,1,1,
};

void drawRays(Raycasting_t *ray)
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo, disT;
    
    ra = ray->user.pa - DR * 30;
    if (ra < 0)
        ra += 2 * PI;

    if (ra > 2 * PI)
        ra -= 2 * PI;

    for (r = 0; r < 60; r++) {
        
        // HORIZONTAL
        dof = 0;
        float disH = 1000000;
        float hx = ray->user.pos.x;
        float hy = ray->user.pos.y;
        float aTan = -1/tan(ra);
        if (ra > PI) {
            ry = (((int)ray->user.pos.y>>6)<<6) - 0.0001;
            rx = (ray->user.pos.y - ry) * aTan + ray->user.pos.x;
            yo = -64;
            xo = -yo*aTan;
        }
        if (ra < PI) {
            ry = (((int)ray->user.pos.y>>6)<<6) + 64;
            rx = (ray->user.pos.y - ry) * aTan + ray->user.pos.x;
            yo = 64;
            xo = -yo*aTan;
        }
        if (ra == 0 || ra == PI) {
            rx = ray->user.pos.x;
            ry = ray->user.pos.y;
            dof = 8;
        }
        while (dof < 8) {
            mx = (int)rx>>6;
            my = (int)ry>>6;
            mp = my * ray->map.mapX + mx;
            if (mp > 0 && mp < ray->map.mapX * ray->map.mapY && map_w[mp] == 1) {
                hx = rx;
                hy = ry;
                disH = dist(ray->user.pos.x, ray->user.pos.y, hx, hy, ra);
                dof = 8;
            } else {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }

        // VERTICAL
        dof = 0;
        float disV = 1000000;
        float vx = ray->user.pos.x;
        float vy = ray->user.pos.y;
        float nTan = -tan(ra);
        if (ra > P2 && ra < P3) {
            rx = (((int)ray->user.pos.x>>6)<<6) - 0.0001;
            ry = (ray->user.pos.x - rx) * nTan + ray->user.pos.y;
            xo = -64;
            yo = -xo*nTan;
        }
        if (ra < P2 || ra > P3) {
            rx = (((int)ray->user.pos.x>>6)<<6) + 64;
            ry = (ray->user.pos.x - rx) * nTan + ray->user.pos.y;
            xo = 64;
            yo = -xo*nTan;
        }
        if (ra == 0 || ra == PI) {
            rx = ray->user.pos.x;
            ry = ray->user.pos.y;
            dof = 8;
        }
        while (dof < 8) {
            mx = (int)rx>>6;
            my = (int)ry>>6;
            mp = my * ray->map.mapX + mx;
            if (mp > 0 && mp < ray->map.mapX * ray->map.mapY && map_w[mp] == 1) {
                vx = rx;
                vy = ry;
                disV = dist(ray->user.pos.x, ray->user.pos.y, vx, vy, ra);
                dof = 8;
            } else {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        if (disV < disH) {   // vertical hit
            rx = vx;
            ry = vy;
            disT = disV;
            ray->quads[r].one.color = ray->map.green;
            ray->quads[r].two.color = ray->map.green;
            ray->quads[r].three.color = ray->map.green;
            ray->quads[r].four.color = ray->map.green;
        }
        if (disH < disV) {  // horizontal hit
            rx = hx;
            ry = hy;
            disT = disH;
            ray->quads[r].one.color = ray->map.side_green;
            ray->quads[r].two.color = ray->map.side_green;
            ray->quads[r].three.color = ray->map.side_green;
            ray->quads[r].four.color = ray->map.side_green;
        }

        // DRAW RAY
        ray->line3[r].lines = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(ray->line3[r].lines, sfLines);
        sfVertexArray_resize(ray->line3[r].lines, 2);
        ray->line3[r].one.color = sfGreen;
        ray->line3[r].one.position.x = ray->user.pos.x + 5;
        ray->line3[r].one.position.y = ray->user.pos.y + 5;
        ray->line3[r].two.color = sfGreen;
        ray->line3[r].two.position.x = rx;
        ray->line3[r].two.position.y = ry;
        sfVertexArray_append(ray->line3[r].lines, ray->line3[r].one);
        sfVertexArray_append(ray->line3[r].lines, ray->line3[r].two);
        ray->r = r;

        // DRAW WALLS

        float ca = ray->user.pa - ra;
        if (ca < 0)
            ca += 2 * PI;
        if (ca > 2 * PI) {
            ca -= 2 * PI;
            disT = disT * cos(ca);
        }

        float lineH = (64 * 320) / disT;
        float lineO = 160 - lineH / 2;
        if (lineH > 320)
            lineH = 320;

        ray->quads[r].quads = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(ray->quads[r].quads, sfQuads);
        sfVertexArray_resize(ray->quads[r].quads, 4);

        ray->quads[r].one.position.x = r * 8 + 530;
        ray->quads[r].one.position.y = 70;

        ray->quads[r].two.position.x = r * 8 + 530;
        ray->quads[r].two.position.y = lineH + lineO;

        ray->quads[r].three.position.x = r * 8 + 530 + 8;
        ray->quads[r].three.position.y = lineH + lineO;

        ray->quads[r].four.position.x = r * 8 + 530 + 8;
        ray->quads[r].four.position.y = 70;
    
        sfVertexArray_append(ray->quads[r].quads, ray->quads[r].one);
        sfVertexArray_append(ray->quads[r].quads, ray->quads[r].two);
        sfVertexArray_append(ray->quads[r].quads, ray->quads[r].three);
        sfVertexArray_append(ray->quads[r].quads, ray->quads[r].four);

        ra += DR;
        if (ra < 0)
            ra += 2 * PI;
        if (ra > 2 * PI)
            ra -= 2 * PI;
    }
}