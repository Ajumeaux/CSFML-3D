/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meshes
*/

#include "rpg_meshes.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>

void update_camera_matrix(camera_t *cam)
{
    vector4f_t target = {0, 0, 1, 1};
    mat4x4_t cam_rot = matrix_mul_matrix(matrix_crea_rota_z(cam->dir.z),
    matrix_mul_matrix(matrix_crea_rota_y(cam->dir.y), matrix_crea_rota_x(cam->dir.x)));

    target = vector_add(cam->pos, vector_mul_matrix(cam_rot, target));
    cam->mat = matrix_pointat_inv(matrix_crea_pointat(cam->pos, target, (vector4f_t){0, 1, 0, 1}));
}

mesh_t empty_mesh(void)
{
    return ((mesh_t){0, NULL, 0, NULL, NULL, NULL, {sfBlendAlpha, sfTransform_Identity,
    NULL, NULL}, matrix_crea_identity(), {0, 0, 0}, {1, 1, 1}, {0, 0, 0}});
}

void destroy_mesh(mesh_t mesh)
{
    free(mesh.triangles);
    free(mesh.tri_draw);
    sfVertexArray_destroy(mesh.vertex);
    sfTexture_destroy(mesh.tex);
}

void update_mesh_matr(mesh_t *mesh)
{
    mat4x4_t matrix = matrix_crea_identity();

    matrix = matrix_mul_matrix(matrix, matrix_crea_translation(
    mesh->position.x, mesh->position.y, mesh->position.z));
    matrix = matrix_mul_matrix(matrix, matrix_crea_rota_x(mesh->rotation.x));
    matrix = matrix_mul_matrix(matrix, matrix_crea_rota_y(mesh->rotation.y));
    matrix = matrix_mul_matrix(matrix, matrix_crea_rota_z(mesh->rotation.z));
    matrix = matrix_mul_matrix(matrix, matrix_crea_scaling(
    mesh->scaling.x, mesh->scaling.y, mesh->scaling.z));
    mesh->mat_world = matrix;
}

bool do_tri_swap(triangle_t trii, triangle_t trij)
{
    float zi = (trii.v[0].p.z + trii.v[1].p.z + trii.v[2].p.z) / 3;
    float zj = (trij.v[0].p.z + trij.v[1].p.z + trij.v[2].p.z) / 3;

    return (zj > zi ? true : false);
}

void sort_to_draw_triangles(triangle_t *tris, size_t nb_tri)
{
    triangle_t tmp;

    for (unsigned long int i = 0; i < nb_tri - 1; ++i)
        for (unsigned long int j = i + 1; j < nb_tri; ++j)
            if (do_tri_swap(tris[i], tris[j])) {
                tmp = tris[j];
                tris[j] = tris[i];
                tris[i] = tmp;
            }
}

void update_mesh(mesh_t *mesh, proj_params_t params,
camera_t cam, __attribute__((unused)) bool var)
{
    mat4x4_t mat_proj = matrix_crea_proj(params);
    vector4f_t normal;
    vector4f_t screen_offset = {1, 1, 0, 1};
    vector4f_t light = vector_normalize((vector4f_t){0, 0, -1, 1});
    float lumin;

    mesh->nb_tri_draw = 0;
    sfVertexArray_clear(mesh->vertex);
    for (size_t i = 0; i < mesh->number; ++i) {
        mesh->tri_draw[mesh->nb_tri_draw] = mesh->triangles[i];
        mesh->tri_draw[mesh->nb_tri_draw].v[0].p = vector_mul_matrix(mesh->mat_world, mesh->tri_draw[mesh->nb_tri_draw].v[0].p);
        mesh->tri_draw[mesh->nb_tri_draw].v[1].p = vector_mul_matrix(mesh->mat_world, mesh->tri_draw[mesh->nb_tri_draw].v[1].p);
        mesh->tri_draw[mesh->nb_tri_draw].v[2].p = vector_mul_matrix(mesh->mat_world, mesh->tri_draw[mesh->nb_tri_draw].v[2].p);
        mesh->tri_draw[mesh->nb_tri_draw].v[0].p = vector_mul_matrix(cam.mat, mesh->tri_draw[mesh->nb_tri_draw].v[0].p);
        mesh->tri_draw[mesh->nb_tri_draw].v[1].p = vector_mul_matrix(cam.mat, mesh->tri_draw[mesh->nb_tri_draw].v[1].p);
        mesh->tri_draw[mesh->nb_tri_draw].v[2].p = vector_mul_matrix(cam.mat, mesh->tri_draw[mesh->nb_tri_draw].v[2].p);
        normal = vector_normalize(vector_cross_prod(vector_sub(mesh->tri_draw[mesh->nb_tri_draw].v[1].p, mesh->tri_draw[mesh->nb_tri_draw].v[0].p), vector_sub(mesh->tri_draw[mesh->nb_tri_draw].v[2].p, mesh->tri_draw[mesh->nb_tri_draw].v[0].p)));
        if (vector_dot_prod(normal, vector_sub(mesh->tri_draw[mesh->nb_tri_draw].v[1].p, cam.pos)) < 0.0) {
            lumin = vector_dot_prod(normal, light);
            for (int j = 0; j < 3; ++j) {
                mesh->tri_draw[mesh->nb_tri_draw].v[j].c.r *= lumin;
                mesh->tri_draw[mesh->nb_tri_draw].v[j].c.g *= lumin;
                mesh->tri_draw[mesh->nb_tri_draw].v[j].c.b *= lumin;
            }
            ++mesh->nb_tri_draw;
        }
    }
    sort_to_draw_triangles(mesh->tri_draw, mesh->nb_tri_draw);
    for (size_t j = 0; j < mesh->nb_tri_draw; ++j)
        for (int i = 0; i < 3; ++i) {
            mesh->tri_draw[j].v[i].p = vector_mul_matrix(mat_proj, mesh->tri_draw[j].v[i].p);
            mesh->tri_draw[j].v[i].p = vector_normalize(mesh->tri_draw[j].v[i].p);
            mesh->tri_draw[j].v[i].p = vector_add(mesh->tri_draw[j].v[i].p, screen_offset);
            mesh->tri_draw[j].v[i].p.x *= 0.5 * (float)params.res.x;
            mesh->tri_draw[j].v[i].p.y *= 0.5 * (float)params.res.y;
        }
    for (size_t i = 0; i < mesh->nb_tri_draw; ++i) {
        sfVertexArray_append(mesh->vertex, (sfVertex){(sfVector2f){mesh->tri_draw[i].v[0].p.x, mesh->tri_draw[i].v[0].p.y}, mesh->tri_draw[i].v[0].c, mesh->tri_draw[i].v[0].t});
        sfVertexArray_append(mesh->vertex, (sfVertex){(sfVector2f){mesh->tri_draw[i].v[1].p.x, mesh->tri_draw[i].v[1].p.y}, mesh->tri_draw[i].v[1].c, mesh->tri_draw[i].v[1].t});
        sfVertexArray_append(mesh->vertex, (sfVertex){(sfVector2f){mesh->tri_draw[i].v[2].p.x, mesh->tri_draw[i].v[2].p.y}, mesh->tri_draw[i].v[2].c, mesh->tri_draw[i].v[2].t});
    }
}