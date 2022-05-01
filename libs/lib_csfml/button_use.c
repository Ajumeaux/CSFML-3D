/*
** EPITECH PROJECT, 2021
** libmy_csfml
** File description:
** button_use
*/

#include "my_csfml.h"

void display_button(sfRenderWindow *window, button_t *button)
{
    sfVector2f rect_scale = {1.03, 1.03};
    sfVector2f rect_ori_scale = {1, 1};
    sfVector2f text_ori_scale = sfText_getScale(button->text);
    sfVector2f text_scale = {text_ori_scale.x * 1.03, text_ori_scale.y * 1.03};

    if (button->highlighted)
        sfText_setStyle(button->text, sfTextUnderlined);
    if (button->clicked) {
        sfRectangleShape_setScale(button->rect, rect_scale);
        sfText_setScale(button->text, text_scale);
    }
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
    if (button->highlighted)
        sfText_setStyle(button->text, sfTextRegular);
    if (button->clicked) {
        sfRectangleShape_setScale(button->rect, rect_ori_scale);
        sfText_setScale(button->text, text_ori_scale);
    }
}

bool is_on_button(button_t *button, sfVector2f mouse)
{
    float rotation = sfRectangleShape_getRotation(button->rect);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width &&
    mouse.y >= rect.top && mouse.y <= rect.top + rect.height)
        return (true);
    return (false);
}