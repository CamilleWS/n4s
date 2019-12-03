/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** weels_dir
*/

#include "../include/my.h"

void	drive_forward(double *dist)
{
	char *buf = NULL;
	long unsigned int n = 0;
	char **tab;

	if (dist[2] > (dist[0] + 100) || (dist[0] < 200 && dist[2] > 400))
		write(1, "WHEELS_DIR:-0.05\n", 17);
	else if (dist[0] > (dist[2] + 100) || (dist[2] < 200 && dist[0] > 400))
		write(1, "WHEELS_DIR:0.05\n", 16);
	else
		write(1, "WHEELS_DIR:0.0\n", 15);
	getline(&buf, &n, stdin);
	tab = str_to_array(buf, ':');
	if (tab[3] && my_cmp("Track Cleared", tab[3]) == 0){
		car_stop();
		stop();
	}
	free(buf);
}
////////////////////////////////////////////////////////////////////////////

void 	turn_left(double *dist)
{
	char *buf = NULL;
	unsigned long int n = 0;

	if (dist[1] < 400)
		write(1, "WHEELS_DIR:0.8\n", 15);
	else if (dist[1] < 500)
		write(1, "WHEELS_DIR:0.6\n", 15);
	else {
		if (dist[1] < 600)
			write(1, "WHEELS_DIR:0.4\n", 15);
		else
			write(1, "WHEELS_DIR:0.2\n", 15);
	}
	getline(&buf, &n, stdin);
	free(buf);
}

void 	turn_right(double *dist)
{
	char *buf = NULL;
	unsigned long int n = 0;

	if (dist[1] < 400)
		write(1, "WHEELS_DIR:-0.8\n", 16);
	else if (dist[1] < 500)
		write(1, "WHEELS_DIR:-0.6\n", 16);
	else {
		if (dist[1] < 600)
			write(1, "WHEELS_DIR:-0.4\n", 16);
		else
			write(1, "WHEELS_DIR:-0.2\n", 16);
	}
	getline(&buf, &n, stdin);
	free(buf);
}
