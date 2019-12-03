/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** simulation.c
*/

#include "../include/my.h"

void	stop(void)
{
	char *buf = NULL;
	long unsigned int n = 0;

	write(1, "STOP_SIMULATION\n", 16);
	getline(&buf, &n, stdin);
	free(buf);
}

void	start(void)
{
	char *buf = NULL;
	long unsigned int n = 0;

	write(1, "START_SIMULATION\n", 17);
	getline(&buf, &n, stdin);
	free(buf);
}
