/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** main.c
*/

#include "../include/my.h"

int	my_cmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i] && str1[i] && str2[i])
		++i;
	if (!(str1[i] && str2[i]))
		return (0);
	return (-1);
}

int	main(void)
{
	double *dist = check_lidar();

	start();
	if (check() != 1)
		return (84);
	car_go(dist);
	while (get_info() == 0) {
		dist = check_lidar();
		drive_forward(dist);
		if (dist[1] > 1000)
			car_go(dist);
		else
			check_options(dist);
	}
	car_stop();
	stop();
	return (0);
}
