/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** car_movement.c
*/

#include "../include/my.h"

void	car_stop(void)
{
	char *buf = NULL;
	long unsigned int n = 0;

	write(1, "CAR_FORWARD:-1\n", 15);
	getline(&buf, &n, stdin);
	free(buf);
}

void	car_go(double *dist)
{
	char *buf = NULL;
	long unsigned int n = 0;
	char **tab;

	write(1, "CAR_FORWARD:1\n", 14);
	getline(&buf, &n, stdin);
	tab = str_to_array(buf, ':');
	if (tab[3] && my_cmp("Track Cleared", tab[3]) == 0){
		car_stop();
		stop();
	}
	free(buf);
	n = 0;
	buf = NULL;
	drive_forward(dist);
}
