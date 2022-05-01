/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my_csfml.h"
#include "my_rpg.h"
#include <stdio.h>

void create_chainsaw_sprite(weapon_t *chainsaw)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {960, 1020};
    sfVector2f origin = {77, 89};

    chainsaw->sprite = sfSprite_create();
    chainsaw->texture =
    sfTexture_createFromFile("./assets/chainsaw_sprite.png", NULL);
    chainsaw->rect.left = 0;
    chainsaw->rect.top = 0;
    chainsaw->rect.height = 89;
    chainsaw->rect.width = 154;
    sfSprite_setTexture(chainsaw->sprite, chainsaw->texture, sfFalse);
    sfSprite_setTextureRect(chainsaw->sprite, chainsaw->rect);
    sfSprite_setOrigin(chainsaw->sprite, origin);
    sfSprite_setScale(chainsaw->sprite, scale);
    sfSprite_setPosition(chainsaw->sprite, pos);
    chainsaw->track.timer = sfClock_create();
    chainsaw->is_equipped = 0;
}

void create_minigun_sprite(weapon_t *minigun)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {960, 1020};
    sfVector2f origin = {100, 200};

    minigun->sprite = sfSprite_create();
    minigun->texture =
    sfTexture_createFromFile("./assets/minigun_sprite.png", NULL);
    minigun->rect.left = 0;
    minigun->rect.top = 0;
    minigun->rect.height = 200;
    minigun->rect.width = 200;
    sfSprite_setTexture(minigun->sprite, minigun->texture, sfFalse);
    sfSprite_setTextureRect(minigun->sprite, minigun->rect);
    sfSprite_setOrigin(minigun->sprite, origin);
    sfSprite_setScale(minigun->sprite, scale);
    sfSprite_setPosition(minigun->sprite, pos);
    minigun->track.timer = sfClock_create();
    minigun->is_equipped = 0;
}

void create_shotgun_sprite(weapon_t *shotgun)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {960, 1020};
    sfVector2f origin = {59.5, 151};

    shotgun->sprite = sfSprite_create();
    shotgun->texture =
    sfTexture_createFromFile("./assets/shotgun_sprite.png", NULL);
    shotgun->rect.left = 0;
    shotgun->rect.top = 0;
    shotgun->rect.height = 151;
    shotgun->rect.width = 119;
    sfSprite_setTexture(shotgun->sprite, shotgun->texture, sfFalse);
    sfSprite_setTextureRect(shotgun->sprite, shotgun->rect);
    sfSprite_setOrigin(shotgun->sprite, origin);
    sfSprite_setScale(shotgun->sprite, scale);
    sfSprite_setPosition(shotgun->sprite, pos);
    shotgun->track.timer = sfClock_create();
    shotgun->is_equipped = 1;
}

void create_rocket_l_sprite(weapon_t *rocket_l)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {960, 1020};
    sfVector2f origin = {50, 200};

    rocket_l->sprite = sfSprite_create();
    rocket_l->texture =
    sfTexture_createFromFile("./assets/rocket_launcher_sprite.png", NULL);
    rocket_l->rect.left = 0;
    rocket_l->rect.top = 0;
    rocket_l->rect.height = 200;
    rocket_l->rect.width = 100;
    sfSprite_setTexture(rocket_l->sprite, rocket_l->texture, sfFalse);
    sfSprite_setTextureRect(rocket_l->sprite, rocket_l->rect);
    sfSprite_setOrigin(rocket_l->sprite, origin);
    sfSprite_setScale(rocket_l->sprite, scale);
    sfSprite_setPosition(rocket_l->sprite, pos);
    rocket_l->track.timer = sfClock_create();
    rocket_l->is_equipped = 0;
}

void minigun_control(weapon_t *minigun)
{
    int ratio;

    minigun->track.time = sfClock_getElapsedTime(minigun->track.timer);
    minigun->track.seconds = minigun->track.time.microseconds / 1000000.0;
    ratio = minigun->track.seconds / 0.10;
    if (minigun->is_equipped == 1 && minigun->track.seconds > 0.10) {
        minigun->rect.left += 200 * ratio;
        minigun->rect.left = (minigun->rect.left > 200) ? 0 : minigun->rect.left;
        sfClock_restart(minigun->track.timer);
        }
    sfSprite_setTextureRect(minigun->sprite, minigun->rect);
}

void chainsaw_control(weapon_t *chainsaw)
{
    int ratio;

    chainsaw->track.time = sfClock_getElapsedTime(chainsaw->track.timer);
    chainsaw->track.seconds = chainsaw->track.time.microseconds / 1000000.0;
    ratio = chainsaw->track.seconds / 0.10;
    if (chainsaw->is_equipped == 1 && chainsaw->track.seconds > 0.10) {
        chainsaw->rect.left += 154 * ratio;
        chainsaw->rect.left = (chainsaw->rect.left > (155)) ? 0 : chainsaw->rect.left;
        sfClock_restart(chainsaw->track.timer);
        }
    sfSprite_setTextureRect(chainsaw->sprite, chainsaw->rect);
}

void rocket_l_control(weapon_t *rocket_l)
{
    int ratio;

    rocket_l->track.time = sfClock_getElapsedTime(rocket_l->track.timer);
    rocket_l->track.seconds = rocket_l->track.time.microseconds / 1000000.0;
    ratio = rocket_l->track.seconds / 0.10;
    if (rocket_l->rect.left == 0)
        sfClock_restart(rocket_l->track.timer);
    if (rocket_l->rect.left != 0 && rocket_l->track.seconds > 0.10) {
        rocket_l->rect.left += 100 * ratio;
        rocket_l->rect.left = (rocket_l->rect.left > 500) ? 0 : rocket_l->rect.left;
        sfClock_restart(rocket_l->track.timer);
        }
    sfSprite_setTextureRect(rocket_l->sprite, rocket_l->rect);
}

void shotgun_control(weapon_t *shotgun)
{
    int ratio;

    shotgun->track.time = sfClock_getElapsedTime(shotgun->track.timer);
    shotgun->track.seconds = shotgun->track.time.microseconds / 1000000.0;
    ratio = shotgun->track.seconds / 0.15;
    if (shotgun->rect.left == 0)
        sfClock_restart(shotgun->track.timer);
    if (shotgun->rect.left != 0 && shotgun->track.seconds > 0.15) {
        shotgun->rect.left += 119 * ratio;
        shotgun->rect.left = (shotgun->rect.left > (119 * 6)) ? 0 : shotgun->rect.left;
        sfClock_restart(shotgun->track.timer);
        }
    sfSprite_setTextureRect(shotgun->sprite, shotgun->rect);
}