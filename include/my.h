/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** .h
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	car_stop(void);
void	car_go(double *dist);
int	get_info(void);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_put_float(double nb);
int	my_get_nbr(char *str);
int	my_len(char *str, char c);
int	my_cmp(char *str1, char *str2);
int	my_ncmp(char *str1, char *str2, int j);
char	*my_cat(char *str1, char *str2);
char	*my_cpy(char *str);
void	stop(void);
void	start(void);
int	tab_len(char **tab);
void	free_tab(char **tab);
int	nb_lines(char *str, char c);
void	mem_alloc(char **tab, char *str, char c);
char	**str_to_array(char *str, char c);
void	drive_forward(double *dist);
void 	turn_left(double *dist);
void 	turn_right(double *dist);
int	check(void);
double	*check_lidar(void);
void	check_options(double *dist);
void	forward_option(double *dist);
void	direction_option(double *dist);