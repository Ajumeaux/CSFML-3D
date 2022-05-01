/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg_meshes
*/

#ifndef RPG_MESHES_H_
#define RPG_MESHES_H_

#include "rpg_matrix.h"
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    vector4f_t p;
    sfColor c;
    sfVector2f t;
} vert3d_t;

typedef struct {
    vert3d_t v[3];
} triangle_t;

typedef struct {
    const size_t number;
    triangle_t *triangles;
    size_t nb_tri_draw;
    triangle_t *tri_draw;
    sfVertexArray *vertex;
    sfTexture *tex;
    sfRenderStates render;
    mat4x4_t mat_world;
    sfVector3f position;
    sfVector3f scaling;
    sfVector3f rotation;
} mesh_t;

typedef struct {
    vector4f_t pos;
    vector4f_t dir;
    mat4x4_t mat;
} camera_t;

// meshes.c

void update_camera_matrix(camera_t *cam);
mesh_t empty_mesh(void);
mesh_t create_mesh(size_t nb, const triangle_t triangles[]);
void destroy_mesh(mesh_t mesh);
void update_mesh_matr(mesh_t *mesh);
bool do_tri_swap(triangle_t trii, triangle_t trij);
void sort_to_draw_triangles(triangle_t *tris, size_t nb_tri);
void update_mesh(mesh_t *mesh, proj_params_t params, camera_t cam, bool var);


//  obj_file_handling.c

int count_points_from_obj_file(char *str);
int count_triangles_from_obj_file(char *str);
mesh_t retrieve_triangles_from_obj(char const *path, sfTexture *texture);


#endif /* !RPG_MESHES_H_ */
