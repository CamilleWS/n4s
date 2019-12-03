/*
** EPITECH PROJECT, 2017
** Lem_in
** File description:
** basics functions on strings
*/

#include "../include/my.h"

void	forward_option(double *dist)
{
	if (dist[1] < 600 && dist[0] < 600 && dist[2] < 600)
		my_put_float(-1.0);
	else if (dist[1] < 1000)
		my_put_float((float)((dist[1] + dist[2] + dist[0]) / 9000.0));
	else
		my_put_float((float)((dist[1] + dist[2] + dist[0]) / 4500.0));
}

void	direction_option(double *dist)
{
	if (dist[0] > (dist[2] + 50) || (dist[2] < 200 && dist[0] > 400))
		turn_left(dist);
	if (dist[2] > (dist[0] + 50) || (dist[0] < 200 && dist[2] > 400))
		turn_right(dist);
}

void	check_options(double *dist)
{
	char *buf = NULL;
	long unsigned int n = 0;
	char **tab;

	write(1, "CAR_FORWARD:", 12);
	forward_option(dist);
	my_putchar('\n');
	getline(&buf, &n, stdin);
	tab = str_to_array(buf, ':');
	if (tab[3] && my_cmp("Track Cleared", tab[3]) == 0){
		car_stop();
		stop();
	}
	free(buf);
	buf = NULL;
	direction_option(dist);
}