/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** my_base.h
*/

#ifndef MY_BASE_H_
#define MY_BASE_H_

#include <stdbool.h>

/* Absolute value of x.*/
#define ABS(x) (x < 0) ? -(x) : x

/* 1 if input is positive, -1 if negative.*/
#define IS_NEG(x) (x < 0) ? -1 : 1

/* True if c is a tab or space or end.*/
#define IS_SPC(c) (c == '\t' || c == ' ' || c == '\0')

/* True if c is a digit.*/
#define IS_NUM(c) (c <= '9' && c >= '0')

/* True if c is lowercase.*/
#define IS_LOWC(c) (c <= 'z' && c >= 'a')

/* True if c is uppercase.*/
#define IS_UPPC(c) (c <= 'Z' && c >= 'A')

/* True if c is a letter.*/
#define IS_ALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))

/* Give lowercase values of letter c.*/
#define T_ALPH(c) (c >= 'A' && c <= 'Z') ? c + 32 : c;

/* Perimeter / radius ratio of a circle.*/
#define PI  3.14159

/* True if the file_type correspond to a normal file.*/
#define IS_FILE(file_type) (file_type)


/* Struct used to store simple file informations.*/
typedef struct loaded_file_s {
    char *content;
    unsigned int size;
    int type;
} lfile_t;


// array1.c

/* Gives the lenght of the array.*/
int my_arrlen(char **arr);

/* Returns a duplicate of the given array, while not duplicating its content.*/
char **my_arrdup(char **arr);

/* Free the given char ** and its content.*/
void free_arr(char ** const arr);

/* Return the emplacement of str in the array.
If it is not found, return -1.*/
int where_str_on_arr(char const * const str, char const * const *arr);

/* Sort an array in alphabetical order.*/
void alpha_sort_arr(char **arr);


// array2.c

/* Adds an row at n_rk containing added in arr.
Return a newly allocated array.*/
char **add_to_arr(char **arr, char *added, int n_rk);

/* Remove the row n_rk in arr.
Return a newly allocated array.*/
char **rm_in_arr(char **arr, int n_rk);


// errors.c

/* Print the given string in error output and return 84.*/
int int_err_msg(char const *msg);

/* Print the given string in error output and return false.*/
bool bool_err_msg(char const *msg);

/* Print the given string in error output and return NULL.*/
void *null_err_msg(char const *msg);


// math1.c

/* Change the base of nb from basf to bast.
If the result has more than 8 digits, returns 0.*/
int base_change(int nb, unsigned const char basf, unsigned const char bast);

/* Return the result of p power q.*/
int our_pow(int p, int q);

// nbr_tests.c

/* Check if the string is only composed of digits.
There can be one minus at the start of the string.
Return 1 if all is good, 0 else.*/
bool is_int(char const *str);

/* Checks if the string can be a float
Return 1 if all good, 0 else.*/
// NOT FUNCTIONNAL
bool is_float(char const *str);

/* Give the lenght of the given int, without the '-'.*/
unsigned int int_len(int);


// prints1.c

/* Print one given character.*/
void my_putchar(char const c);

/* Print the given string.
Return the number of char written, or -1 if str is NULL*/
int show_str(char const *str);

/* Print digit by digit the given int.*/
int show_int(int);


// str_comps.c

/* Give the lenght of the given string.
Return 0 if string is NULL.*/
unsigned int my_strlen(char const *str);

/* Compare s1 to s2.
Return the first difference between s1 and s2, or 0 if they are identical.*/
int my_strcmp(char const *s1, char const *s2);

/* Compare s1 to s2 for a maximum of n characters.
Return the first difference between s1 and s2, or 0 if they are identical.*/
int my_strncmp(char const *s1, char const *s2, unsigned int const n);

/* Compare s1 to s2, but 'uppercase char' == 'lowercase char'.*/
int my_strcomp_alpha(char const *s1, char const *s2);

/* Search for the second string inside the first one.
Return a pointer to the first occurrence.
Return NULL if not found.*/
char *my_strstr(char * const str, char const *to_find);


// str_manip1.c

/* Reverse the characters of the given string.*/
char *rev_str(char * const str);

/* Copy the content of src in dest, regardless of the sizes.*/
void my_strcpy(char *dest, char const *src);

/* Copy n bytes of src in dest.*/
void my_strncpy(char const *src, char *dest, unsigned int const n);

/* Return an newly allocated string identcal to the one given.*/
char *my_strdup(char const *str);


// str_manip2.c

/* Swap the *s1 with *s2.*/
void swap_str(char **s1, char **s2);

/* Return an int by reading given string for numbers.
Stop after 999999999.
Can handle multiple '-' and '+'.*/
int str_to_int(char const *str);

/* Return an allocated string representing the given int.*/
char *int_to_str(int const nb);

/* Contatenate two strings and returns it.*/
char *my_strcat2(char const *str1, char const *str2);

/* Contatenate tree strings and returns it.*/
char *my_strcat3(char const *str1, char const *str2, char const *str3);

// str_to_array.c

/* Checks if the char c is found inside delim.*/
bool is_delim(char c, char const *delim);

/* Counts for args separated by a char of delim.*/
int args_nb(char const *str, char const *delim);

/* Counts for the numbers of character before the first char of delim.*/
int arg_len(char const *str, char const *delim);

/* Create an array from str by separating what's between chars of delim.*/
char **str_to_arr(char const *str, char const *delim);


// sys1.c

/* Return true if the file exists, false either.*/
bool do_file_exists(char const *fpath);

/* Return a lfile_t structure from the given filepath.
If anything went wrong, content field is set to NULL.
Use open, close, stat, read, malloc and free.*/
lfile_t my_file_reader(char const * const fpath);

/* Wait for the user to enter a newline and returns it.
If getline returned -1, returns NULL.*/
char *getline_full(void);

#endif /* !MY_BASE_H_ */