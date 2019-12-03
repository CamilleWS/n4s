/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** main.c
*/

#include "../include/my.h"

int	get_info(void)
{
	long unsigned int n = 0;
	char *buf = NULL;
	char **tab;

	write(1, "GET_INFO_SIMTIME\n", 17);
	getline(&buf, &n, stdin);
	tab = str_to_array(buf, ':');
	if (tab_len(tab) == 5 && my_cmp("Track Cleared", tab[4]) == 0)
		return (1);
	free_tab(tab);
	free(buf);
	return (0);
}
