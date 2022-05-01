/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg_matrix
*/

#ifndef RPG_MATRIX_H_
#define RPG_MATRIX_H_

#include "rpg_vectors.h"
#include <SFML/Graphics.h>

typedef struct {
    float fov;
    sfVector2u res;
    float fnear;
    float ffar;
} proj_params_t;

typedef struct {
    float v[4][4];
} mat4x4_t;

// matrix_calcs.c

vector4f_t vector_mul_matrix(mat4x4_t m, vector4f_t v);
mat4x4_t matrix_mul_matrix(mat4x4_t m1, mat4x4_t m2);


// matrix_defs1.c

mat4x4_t matrix_crea_identity(void);
mat4x4_t matrix_crea_translation(float x, float y, float z);
mat4x4_t matrix_crea_scaling(float x, float y, float z);
mat4x4_t matrix_crea_pointat(vector4f_t pos, vector4f_t targ, vector4f_t up);
mat4x4_t matrix_pointat_inv(mat4x4_t mat);

// matrix_defs2.c

mat4x4_t matrix_crea_rota_x(float rad);
mat4x4_t matrix_crea_rota_y(float rad);
mat4x4_t matrix_crea_rota_z(float rad);
mat4x4_t matrix_crea_proj(proj_params_t par);



#endif /* !RPG_MATRIX_H_ */
