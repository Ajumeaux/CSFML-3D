/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** matrix_defs2
*/

#include <math.h>
#include "rpg_matrix.h"

mat4x4_t matrix_crea_rota_x(float rad)
{
    return ((mat4x4_t){{{1, 0, 0, 0},
    {0, cosf(rad), -sinf(rad), 0},
    {0, sinf(rad), cosf(rad), 0},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_rota_y(float rad)
{
    return ((mat4x4_t){{{cosf(rad), 0, sinf(rad), 0},
    {0, 1, 0, 0},
    {-sinf(rad), 0, cosf(rad), 0},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_rota_z(float rad)
{
    return ((mat4x4_t){{{cosf(rad), -sinf(rad), 0, 0},
    {sinf(rad), cosf(rad), 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_proj(proj_params_t par)
{
    float fov_rad = 1 / tanf(par.fov * (M_PI / 180) * 0.5);
    float aspect_ratio = ((float)par.res.y / (float)par.res.x);

    return ((mat4x4_t){{{aspect_ratio * fov_rad, 0, 0, 0},
    {0, fov_rad, 0, 0}, {0, 0, par.ffar / (par.ffar - par.fnear), 1},
    {0, 0, (-par.ffar * par.fnear) / (par.ffar - par.fnear), 0}}});
}