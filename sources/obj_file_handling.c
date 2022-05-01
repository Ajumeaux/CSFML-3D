/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** obj_file_handling
*/

#include "rpg_meshes.h"
#include "my_rpg.h"
#include "my_base.h"
#include <stdlib.h>
#include <string.h>

int count_points_from_obj_file(char *str)
{
    int points = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == 'v' && str[i - 1] == '\n' && str[i + 1] != 't')
            ++points;
    return points;
}

int count_texpoints_from_obj_file(char *str)
{
    int points = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == 'v' && str[i - 1] == '\n' && str[i + 1] == 't')
            ++points;
    return points;
}

int count_triangles_from_obj_file(char *str)
{
    int triangles = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == 'f' && str[i - 1] == '\n')
            ++triangles;
    return triangles;
}

mesh_t retrieve_triangles_from_obj(char const *path, sfTexture *texture)
{
    lfile_t obj = my_file_reader(path);
    int points = count_points_from_obj_file(obj.content);
    int triangle_nb = count_triangles_from_obj_file(obj.content);
    int tex_points = count_texpoints_from_obj_file(obj.content);
    vector4f_t verts[points];
    sfVector2f tex_p[tex_points];
    mesh_t mesh = {triangle_nb, malloc(sizeof(triangle_t) * triangle_nb), 0,
    malloc(sizeof(triangle_t) * triangle_nb), sfVertexArray_create(), texture,
    {sfBlendAlpha, sfTransform_Identity, texture, NULL},
    matrix_crea_identity(), {0, 0, 0}, {1, 1, 1}, {0, 0, 0}};
    sfVector2u text_size = sfTexture_getSize(texture);
    char *tmp;

    if (!obj.content)
        return empty_mesh();
    tmp = our_strtok(obj.content, "\n");
    for (int i = 0, j = 0, k = 0; tmp != NULL; tmp = our_strtok(NULL, " \n")) {
        if (tmp[0] == 'v' && tmp[1] == '\0') {
            verts[i].x = str_to_float(our_strtok(NULL, " "));
            verts[i].y = str_to_float(our_strtok(NULL, " "));
            verts[i].z = str_to_float(our_strtok(NULL, "\n"));
            verts[i].w = 1;
            ++i;
        } else if (tmp[0] == 'v' && tmp[1] == 't' && tmp[2] == '\0') {
            tex_p[k].x = str_to_float(our_strtok(NULL, " ")) * (int)text_size.x;
            tex_p[k].y = str_to_float(our_strtok(NULL, "\n")) * (int)text_size.y;
            k++;
        } else if (tmp[0] == 'f' && tmp[1] == '\0') {
            mesh.triangles[j].v[0].p = verts[str_to_int(our_strtok(NULL, " /")) - 1];
            mesh.triangles[j].v[0].t = tex_p[str_to_int(our_strtok(NULL, "/ ")) - 1];
            mesh.triangles[j].v[1].p = verts[str_to_int(our_strtok(NULL, " /")) - 1];
            mesh.triangles[j].v[1].t = tex_p[str_to_int(our_strtok(NULL, "/ ")) - 1];
            mesh.triangles[j].v[2].p = verts[str_to_int(our_strtok(NULL, " /")) - 1];
            mesh.triangles[j].v[2].t = tex_p[str_to_int(our_strtok(NULL, "/\n")) - 1];
            mesh.triangles[j].v[0].c = (sfColor){255, 255, 255, 255};
            mesh.triangles[j].v[1].c = (sfColor){255, 255, 255, 255};
            mesh.triangles[j].v[2].c = (sfColor){255, 255, 255, 255};
            ++j;
        }
    }
    if (!mesh.vertex)
        return (empty_mesh());
    free(obj.content);
    sfVertexArray_setPrimitiveType(mesh.vertex, sfTriangles);
    return (mesh);
}