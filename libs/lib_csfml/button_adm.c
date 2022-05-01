/*
** EPITECH PROJECT, 2021
** libmy_csfml
** File description:
** button_adm
*/

#include "my_csfml.h"
#include <stdlib.h>

void assign_button_text(button_infos_t infos, sfText *text, sfFont *font)
{
    sfVector2f origin;
    sfFloatRect size;

    sfText_setFillColor(text, infos.text_color);
    sfText_setFont(text, font);
    sfText_setString(text, infos.text);
    size = sfText_getLocalBounds(text);
    origin.x = size.width / 2;
    origin.y = 1.333 * size.height;
    sfText_setOrigin(text, origin);
    sfText_setScale(text, infos.text_scale);
    sfText_setPosition(text, infos.position);
    sfText_setRotation(text, infos.rotation);
}

void assign_button_rect(button_infos_t infos, sfRectangleShape *rect)
{
    sfVector2f origin = {infos.size.x / 2, infos.size.y / 2};

    sfRectangleShape_setFillColor(rect, infos.button_color);
    sfRectangleShape_setOrigin(rect, origin);
    sfRectangleShape_setPosition(rect, infos.position);
    sfRectangleShape_setSize(rect, infos.size);
    sfRectangleShape_setRotation(rect, infos.rotation);
}

button_t *create_button(button_infos_t infos, sfFont *font)
{
    button_t *button = malloc(sizeof(button_t));

    button->text = sfText_create();
    button->rect = sfRectangleShape_create();
    if (!button->text || !button->rect) {
        if (button->text)
            sfText_destroy(button->text);
        if (button->rect)
            sfRectangleShape_destroy(button->rect);
        return (NULL);
    }
    assign_button_text(infos, button->text, font);
    assign_button_rect(infos, button->rect);
    button->clicked = false;
    button->highlighted = false;
    return (button);
}

void destroy_button(button_t *button)
{
    if (button) {
        if (button->text)
            sfText_destroy(button->text);
        if (button->rect)
            sfRectangleShape_destroy(button->rect);
        free(button);
    }
}