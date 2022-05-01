/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** sys1
*/

#include "my_base.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool do_file_exists(char const *fpath)
{
    struct stat stats;
    int is_ok = stat(fpath, &stats);

    return ((!is_ok) ? true : false);
}

lfile_t my_file_reader(char const * const fpath)
{
    lfile_t file = {.content = NULL, .size = 0};
    struct stat stats;
    int fd = open(fpath, O_RDONLY);

    if (fd == -1 || stat(fpath, &stats) == -1)
        return (file);
    file.size = stats.st_size;
    file.type = (S_ISREG(stats.st_mode) ? 1 : 0);
    file.content = malloc(sizeof(char) * (file.size + 1));
    if (file.content == NULL)
        return (file);
    if (read(fd, file.content, file.size) == -1) {
        free(file.content);
        file.content = NULL;
        return (file);
    }
    file.content[file.size] = '\0';
    close(fd);
    return (file);
}

char *getline_full(void)
{
    char *res = NULL;
    size_t n = 0;
    int cck = getline(&res, &n, stdin);

    if (cck == -1) {
        if (res)
            free(res);
        return (NULL);
    }
    res[my_strlen(res) - 1] = 0;
    return (res);
}