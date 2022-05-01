/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** vectors
*/

#include "rpg_vectors.h"

vector4f_t vector_add(vector4f_t v1, vector4f_t v2)
{
    return ((vector4f_t){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, 1});
}

vector4f_t vector_sub(vector4f_t v1, vector4f_t v2)
{
    return ((vector4f_t){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 1});
}

vector4f_t vector_mul(vector4f_t v, float k)
{
    return ((vector4f_t){v.x * k, v.y * k, v.z * k, 1});
}

vector4f_t vector_div(vector4f_t v, float k)
{
    return ((vector4f_t){v.x / k, v.y / k, v.z / k, 1});
}

