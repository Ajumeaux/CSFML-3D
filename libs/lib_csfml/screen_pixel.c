/*
** EPITECH PROJECT, 2021
** libmy_csfml
** File description:
** screen_pixel
*/

#include <stdlib.h>
#include <string.h>
#include "my_csfml.h"

void refresh(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void clear_fbuffer(fbuffer_t fbuffer)
{
    memset(fbuffer.pixels, 0, fbuffer.width * fbuffer.height * (BPP / 8));
}

fbuffer_t framebuffer_create(unsigned int width, unsigned int height)
{
    fbuffer_t fbuffer;

    fbuffer.width = width;
    fbuffer.height = height;
    fbuffer.pixels = malloc(width * height * BPP / 8);
    return (fbuffer);
}

int my_pixel(fbuffer_t fbuffer, sfVector2u xy, sfColor color)
{
    if (xy.x >= fbuffer.width || xy.y >= fbuffer.height)
        return (84);
    fbuffer.pixels[(fbuffer.width * xy.y + xy.x) * 4] = color.r;
    fbuffer.pixels[(fbuffer.width * xy.y + xy.x) * 4 + 1] = color.g;
    fbuffer.pixels[(fbuffer.width * xy.y + xy.x) * 4 + 2] = color.b;
    fbuffer.pixels[(fbuffer.width * xy.y + xy.x) * 4 + 3] = color.a;
    return (0);
}

sfRenderWindow *create_window(screen_params_t params)
{
    sfVideoMode video_mode = {params.resolution.x, params.resolution.y, BPP};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
    params.win_name, sfClose | sfResize, NULL);

    if (!window)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, params.refresh_rate);
    return (window);
}