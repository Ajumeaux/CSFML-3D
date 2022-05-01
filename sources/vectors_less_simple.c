/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** vectors_less_simple
*/

#include "rpg_vectors.h"
#include "math.h"

float vector_dot_prod(vector4f_t v1, vector4f_t v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float vector_lenght(vector4f_t v)
{
    return (sqrtf(vector_dot_prod(v, v)));
}

vector4f_t vector_normalize(vector4f_t v)
{
    float l = vector_lenght(v);

    return ((vector4f_t){v.x / l, v.y / l, v.z / l, 1});
}

vector4f_t vector_cross_prod(vector4f_t v1, vector4f_t v2)
{
    vector4f_t v0;

    v0.x = v1.y * v2.z - v1.z * v2.y;
    v0.y = v1.z * v2.x - v1.x * v2.z;
    v0.z = v1.x * v2.y - v1.y * v2.x;
    v0.w = 1;
    return (v0);
}