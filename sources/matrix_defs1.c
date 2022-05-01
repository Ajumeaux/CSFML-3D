/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** matrix2
*/

#include "rpg_matrix.h"

mat4x4_t matrix_crea_identity(void)
{
    return ((mat4x4_t){{{1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_translation(float x, float y, float z)
{
    return ((mat4x4_t){{{1, 0, 0, x},
    {0, 1, 0, y},
    {0, 0, 1, z},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_scaling(float x, float y, float z)
{
    return ((mat4x4_t){{{x, 0, 0, 0},
    {0, y, 0, 0},
    {0, 0, z, 0},
    {0, 0, 0, 1}}});
}

mat4x4_t matrix_crea_pointat(vector4f_t pos, vector4f_t targ, vector4f_t up)
{
    vector4f_t new_forw = vector_normalize(vector_sub(targ, pos));
    vector4f_t new_up = vector_normalize(vector_sub(up, vector_mul(new_forw, vector_dot_prod(up, new_forw))));
    vector4f_t new_right = vector_cross_prod(new_up, new_forw);

    return ((mat4x4_t){{{new_right.x, new_right.y, new_right.z, 0}, {new_up.x, new_up.y, new_up.z, 0}, {new_forw.x, new_forw.y, new_forw.z, 0}, {pos.x, pos.y, pos.z, 1}}});
}
// uninverted
// return ((mat4x4_t){{{new_right.x, new_right.y, new_right.z, 0}, {new_up.x, new_up.y, new_up.z, 0}, {new_forw.x, new_forw.y, new_forw.z, 0}, {pos.x, pos.y, pos.z, 1}}});

// inverted
// return ((mat4x4_t){{{new_right.x, new_up.x, new_forw.x, pos.x}, {new_right.y, new_up.y, new_forw.y, pos.y}, {new_right.z, new_up.z, new_forw.z, pos.z}, {0, 0, 0, 1}}});

mat4x4_t matrix_pointat_inv(mat4x4_t mat)
{
    return ((mat4x4_t){{{mat.v[0][0], mat.v[1][0], mat.v[2][0], 0},
    {mat.v[0][1], mat.v[1][1], mat.v[2][1], 0},
    {mat.v[0][2], mat.v[1][2], mat.v[2][2], 0},
    {-(mat.v[0][3] * mat.v[0][0] + mat.v[1][3] * mat.v[1][0] + mat.v[2][3] * mat.v[2][0]),
    - (mat.v[0][3] * mat.v[0][1] + mat.v[1][3] * mat.v[1][1] + mat.v[2][3] * mat.v[2][1]),
    - (mat.v[0][3] * mat.v[0][2] + mat.v[1][3] * mat.v[1][2] + mat.v[2][3] * mat.v[2][2]),
    1}}});
}
// uninverted
/* return ((mat4x4_t){{{mat.v[0][0], mat.v[1][0], mat.v[2][0], 0},
    {mat.v[0][1], mat.v[1][1], mat.v[2][1], 0},
    {mat.v[0][2], mat.v[1][2], mat.v[2][2], 0},
    {-(mat.v[0][3] * mat.v[0][0] + mat.v[1][3] * mat.v[1][0] + mat.v[2][3] * mat.v[2][0]),
    - (mat.v[0][3] * mat.v[0][1] + mat.v[1][3] * mat.v[1][1] + mat.v[2][3] * mat.v[2][1]),
    - (mat.v[0][3] * mat.v[0][2] + mat.v[1][3] * mat.v[1][2] + mat.v[2][3] * mat.v[2][2]),
    1}}});*/

// inverted (?)
/* return ((mat4x4_t){{{mat.v[0][0], mat.v[0][1], mat.v[0][2],
    -(mat.v[0][3] * mat.v[0][0] + mat.v[1][3] * mat.v[1][0] + mat.v[2][3] * mat.v[2][0])},
    {mat.v[1][0], mat.v[1][1], mat.v[1][2],
    - (mat.v[0][3] * mat.v[0][1] + mat.v[1][3] * mat.v[1][1] + mat.v[2][3] * mat.v[2][1])},
    {mat.v[2][0], mat.v[2][1], mat.v[2][2],
    - (mat.v[0][3] * mat.v[0][2] + mat.v[1][3] * mat.v[1][2] + mat.v[2][3] * mat.v[2][2])},
    {0 ,0 , 0, 1}}});*/