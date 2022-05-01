/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "rpg_meshes.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    sfClock* timer;
    sfTime time;
    float seconds;
} timestruct_t;

typedef struct {
    float fov;
    sfVector2u res;
    float el_time;
} user_params_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    timestruct_t track;
    int is_equipped;
} weapon_t;

typedef struct {
    weapon_t shotgun;
    weapon_t minigun;
    weapon_t chainsaw;
    weapon_t rocket_l;
} arsenal_t;

// main.c

void print_triangle(vector4f_t vec[3], unsigned long int index, char *str);
void print_matrix(mat4x4_t m, char *str);
void update_test_mesh(mesh_t *mesh, float time);
void my_events(sfRenderWindow *window, sfEvent event, bool *var, camera_t *cam, arsenal_t *weapons);
void start_loop(sfRenderWindow *window, mesh_t cube);
int main(void);

// sprites
void create_shotgun_sprite(weapon_t *shotgun);
void create_chainsaw_sprite(weapon_t *chainsaw);
void create_minigun_sprite(weapon_t *minigun);
void create_rocket_l_sprite(weapon_t *rocket_l);
void shotgun_control(weapon_t *shotgun);
void chainsaw_control(weapon_t *chainsaw);
void minigun_control(weapon_t *minigun);
void rocket_l_control(weapon_t *rocket_l);

// my_strtok.c

char *strtoked(char *str, const char *delims, int len);
char *our_strtok(char *str, const char *delims);
float str_to_float(char *str);


#endif /* !MY_RPG_H_ */
