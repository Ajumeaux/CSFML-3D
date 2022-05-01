/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** matrix1
*/

#include "rpg_matrix.h"

vector4f_t vector_mul_matrix(mat4x4_t m, vector4f_t v)
{
    vector4f_t res;

    res.x = v.x * m.v[0][0] + v.y * m.v[0][1] +
    v.z * m.v[0][2] + v.w * m.v[0][3];
    res.y = v.x * m.v[1][0] + v.y * m.v[1][1] +
    v.z * m.v[1][2] + v.w * m.v[1][3];
    res.z = v.x * m.v[2][0] + v.y * m.v[2][1] +
    v.z * m.v[2][2] + v.w * m.v[2][3];
    res.w = v.x * m.v[3][0] + v.y * m.v[3][1] +
    v.z * m.v[3][2] + v.w * m.v[3][3];
    return (res);
}

mat4x4_t matrix_mul_matrix(mat4x4_t m1, mat4x4_t m2)
{
    mat4x4_t m0;

    for (int col = 0; col < 4; ++col)
        for (int row = 0; row < 4; ++row)
            m0.v[row][col] = m1.v[row][0] * m2.v[0][col] +
            m1.v[row][1] * m2.v[1][col] + m1.v[row][2] *
            m2.v[2][col] + m1.v[row][3] * m2.v[3][col];
    return (m0);
}