/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg_vectors
*/

#ifndef RPG_VECTORS_H_
#define RPG_VECTORS_H_

typedef struct {
    float x;
    float y;
    float z;
    float w;
} vector4f_t;

// vectors_simple.c

vector4f_t vector_add(vector4f_t v1, vector4f_t v2);
vector4f_t vector_sub(vector4f_t v1, vector4f_t v2);
vector4f_t vector_mul(vector4f_t v, float k);
vector4f_t vector_div(vector4f_t v, float k);


// vectors_lee_simple.c

float vector_dot_prod(vector4f_t v1, vector4f_t v2);
float vector_lenght(vector4f_t v);
vector4f_t vector_normalize(vector4f_t v);
vector4f_t vector_cross_prod(vector4f_t v1, vector4f_t v2);


#endif /* !RPG_VECTORS_H_ */
