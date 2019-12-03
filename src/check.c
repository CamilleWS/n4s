/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** check
*/

#include "../include/my.h"

int	check(void)
{
	long unsigned int n = 0;
	char *buf = NULL;
	char *error = "ERROR: The simulation has not been launched\n";

	write(1, "GET_INFO_SIMTIME\n", 17);
	getline(&buf, &n, stdin);
	if (buf[0] == '0') {
		write(2, error, strlen(error));
		free(buf);
		return (84);
	}
	return (1);
}

double	*check_lidar(void)
{
	char *buf = NULL;
	long unsigned int n = 0;
	char **tab = NULL;
	double *table = malloc(sizeof(double *) * 3);

	write(1, "GET_INFO_LIDAR\n", 15);
	getline(&buf, &n, stdin);
	tab = str_to_array(buf, ':');
	if (tab[35] && my_cmp("Track Cleared", tab[35]) == 0) {
		car_stop();
		stop();
	}
	if (tab_len(tab) > 33) {
		table[0] = my_get_nbr(tab[3]);
		table[1] = my_get_nbr(tab[17]);
		table[2] = my_get_nbr(tab[34]);
	}
	free_tab(tab);
	free(buf);
	return (table);
}