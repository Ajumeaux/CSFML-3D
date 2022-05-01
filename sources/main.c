/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my_csfml.h"
#include "my_rpg.h"
#include <stdio.h>

void update_test_mesh(mesh_t *mesh, float time)
{
    mesh->rotation.x = time;
    mesh->rotation.z = time / 2.5;
}

void my_events(sfRenderWindow *window, sfEvent event, bool *var, camera_t *cam, arsenal_t *weapons)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased) {
            if (event.key.code == sfKeyM)
                *var = (*var ? false : true);
            if (event.key.code == sfKeyZ)
                cam->pos.z += 1;
            if (event.key.code == sfKeyS)
                cam->pos.z -= 1;
            if (event.key.code == sfKeyQ)
                cam->pos.x += 1;
            if (event.key.code == sfKeyD)
                cam->pos.x -= 1;
            if (event.key.code == sfKeySpace)
                cam->pos.y += 1;
            if (event.key.code == sfKeyLShift)
                cam->pos.y -= 1;
            if (event.key.code == sfKeyRight)
                cam->dir.y += 0.3;
            if (event.key.code == sfKeyLeft)
                cam->dir.y -= 0.3;
            if (event.key.code == sfKeyNum1) {
                weapons->shotgun.is_equipped = 1;
                weapons->chainsaw.is_equipped = 0;
                weapons->minigun.is_equipped = 0;
                weapons->rocket_l.is_equipped = 0;
            }
            if (event.key.code == sfKeyNum2) {
                weapons->shotgun.is_equipped = 0;
                weapons->chainsaw.is_equipped = 1;
                weapons->minigun.is_equipped = 0;
                weapons->rocket_l.is_equipped = 0;
            }
            if (event.key.code == sfKeyNum3) {
                weapons->shotgun.is_equipped = 0;
                weapons->chainsaw.is_equipped = 0;
                weapons->minigun.is_equipped = 1;
                weapons->rocket_l.is_equipped = 0;
            }
            if (event.key.code == sfKeyNum4) {
                weapons->shotgun.is_equipped = 0;
                weapons->chainsaw.is_equipped = 0;
                weapons->minigun.is_equipped = 0;
                weapons->rocket_l.is_equipped = 1;
            }
        }
        if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && weapons->shotgun.is_equipped == 1 && weapons->shotgun.rect.left == 0)
            weapons->shotgun.rect.left += 119;
        if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && weapons->rocket_l.is_equipped == 1 && weapons->rocket_l.rect.left == 0)
            weapons->rocket_l.rect.left += 100;
        if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && weapons->chainsaw.is_equipped == 1 && weapons->chainsaw.rect.top == 0)
            weapons->chainsaw.rect.top = 89;
        if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft
        && weapons->chainsaw.is_equipped == 1 && weapons->chainsaw.rect.top == 89)
            weapons->chainsaw.rect.top = 0;
        if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && weapons->minigun.is_equipped == 1 && weapons->minigun.rect.top == 0)
            weapons->minigun.rect.top = 200;
        if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft
        && weapons->minigun.is_equipped == 1 && weapons->minigun.rect.top == 200)
            weapons->minigun.rect.top = 0;
    }
}

void start_loop(sfRenderWindow *window, mesh_t cube)
{
    sfEvent event;
    timestruct_t track;
    user_params_t params = {90, (sfVector2u){1920, 1080}, 0};
    bool var = false;
    camera_t cam = {{0, 0, -1, 1}, {0, 0, 1, 1}, matrix_crea_identity()};
    proj_params_t proj_params;
    arsenal_t weapons;

    create_shotgun_sprite(&weapons.shotgun);
    create_chainsaw_sprite(&weapons.chainsaw);
    create_minigun_sprite(&weapons.minigun);
    create_rocket_l_sprite(&weapons.rocket_l);
    track.timer = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        proj_params = (proj_params_t){params.fov, params.res, 0.1, 1000};
        my_events(window, event, &var, &cam, &weapons);
        shotgun_control(&weapons.shotgun);
        chainsaw_control(&weapons.chainsaw);
        minigun_control(&weapons.minigun);
        rocket_l_control(&weapons.rocket_l);
        track.time = sfClock_getElapsedTime(track.timer);
        track.seconds = track.time.microseconds / 1000000.0;
        update_camera_matrix(&cam);
        update_test_mesh(&cube, track.seconds);
        update_mesh_matr(&cube);
        update_mesh(&cube, proj_params, cam, var);
        sfRenderWindow_drawVertexArray(window, cube.vertex, &cube.render);
        if (weapons.shotgun.is_equipped == 1)
            sfRenderWindow_drawSprite(window, weapons.shotgun.sprite, NULL);
        if (weapons.chainsaw.is_equipped == 1)
            sfRenderWindow_drawSprite(window, weapons.chainsaw.sprite, NULL);
        if (weapons.minigun.is_equipped == 1)
            sfRenderWindow_drawSprite(window, weapons.minigun.sprite, NULL);
        if (weapons.rocket_l.is_equipped == 1)
            sfRenderWindow_drawSprite(window, weapons.rocket_l.sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(track.timer);
}

int main(void)
{
    screen_params_t params = {60, {1920, 1080}, "Test_mesh"};
    sfRenderWindow *window = create_window(params);
    mesh_t obj = retrieve_triangles_from_obj("./assets/bowser.obj", sfTexture_createFromFile("./assets/bowser_grp.png", NULL));
    obj.position.z = 20;

    start_loop(window, obj);
    destroy_mesh(obj);
    sfRenderWindow_destroy(window);
    return (0);
}