/*
** EPITECH PROJECT, 2021
** libmy_csfml
** File description:
** my_csfml.h
*/

#ifndef MY_CSFML_H_
#define MY_CSFML_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdbool.h>

#define BPP     32

/* Informations needed to create a window.*/
typedef struct screen_params_s {
    unsigned char refresh_rate;
    sfVector2u resolution;
    char *win_name;
} screen_params_t;

/* Framebuffer containing pixels.*/
typedef struct framebuffer_s {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
} fbuffer_t;

/* Understandable infos requiered to create a button object.*/
typedef struct button_infos_s {
    sfVector2f size;
    sfVector2f position;
    float rotation;
    sfColor button_color;
    sfColor text_color;
    sfVector2f text_scale;
    char const *text;
} button_infos_t;

/* Button structure.*/
typedef struct button_s {
    sfRectangleShape *rect;
    sfText *text;
    bool clicked;
    bool highlighted;
} button_t;

// button_adm.c

/* Text-part of button creation.*/
void assign_button_text(button_infos_t infos, sfText *text, sfFont *font);

/* Rect-part of button creation.*/
void assign_button_rect(button_infos_t infos, sfRectangleShape *rect);

/* Main-part of button creation.*/
button_t *create_button(button_infos_t infos, sfFont *font);

/* Destroy a button object.*/
void destroy_button(button_t *button);


// button_use.c

/* Display a button object.*/
void display_button(sfRenderWindow *window, button_t *button);

/* Returns true if coos are inside the button hitbox.*/
bool is_on_button(button_t *button, sfVector2f coos);


// screen_pixel.c

/* Create a render window with to-be-defined parameters like header model.*/
sfRenderWindow *create_window(screen_params_t params);

/* Puts a pixel of color at xy in the framebuffer.*/
int my_pixel(fbuffer_t fbuffer, sfVector2u xy, sfColor color);

/* Create a framebuffer of size width * height.*/
fbuffer_t framebuffer_create(unsigned int width, unsigned int height);

/* Sets the buffer's pixels to black.*/
void clear_fbuffer(fbuffer_t fbuffer);

/* Refresh the window.*/
void refresh(sfRenderWindow *window);

#endif /* !MY_CSFML_H_ */
