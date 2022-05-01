/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** tests_vectors1
*/

#include <criterion/criterion.h>
#include "rpg_vectors.h"
#include <math.h>

Test(vectors, simple)
{
    vector4f_t vec1 = {2, 5, 6, 1};
    vector4f_t vec2 = {-5, 9, 0, 1};
    vector4f_t vec_add = vector_add(vec1, vec2);
    vector4f_t vec_sub = vector_sub(vec1, vec2);
    vector4f_t vec_mul = vector_mul(vec1, -3);
    vector4f_t vec_div = vector_div(vec1, 2);

    cr_assert(vec_add.x == -3 && vec_add.y == 14
    && vec_add.z == 6 && vec_add.w == 1);
    cr_assert(vec_sub.x == 7 && vec_sub.y == -4
    && vec_sub.z == 6 && vec_sub.w == 1);
    cr_assert(vec_mul.x == -6 && vec_mul.y == -15
    && vec_mul.z == -18 && vec_mul.w == 1);
    cr_assert(vec_div.x == 1 && vec_div.y == 2.5
    && vec_div.z == 3 && vec_div.w == 1);
}

Test(vectors, less_simple)
{
    vector4f_t vec1 = {2, 8, -4, 1};
    vector4f_t vec2 = {-1, 4, 7, 1};
    float dot = vector_dot_prod(vec1, vec2);
    vector4f_t vec_cross = vector_cross_prod(vec1, vec2);
    float lenght = vector_lenght(vec1);
    vector4f_t norm = vector_normalize(vec1);

    cr_assert(dot == 2);
    cr_assert(vec_cross.x == 72 && vec_cross.y == -10
    && vec_cross.z == 16 && vec_cross.w == 1);
    cr_assert(lenght == 2 * sqrtf(21));
    cr_assert(norm.x == 0.21821787953376770 && norm.y == 0.87287151813507080
    && norm.z == -0.43643575906753540039 && norm.w == 1);
}