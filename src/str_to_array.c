/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** str_to_array
*/

#include "../include/my.h"

int	tab_len(char **tab)
{
	int i = -1;

	if (!tab)
		return (-1);
	while (tab[++i]);
	return (i);
}

void	free_tab(char **tab)
{
	int i = -1;

	if (!tab)
		return;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	count_lines(char *str, char c)
{
	int i = 0;
	int lines = 1;

	if (!str || !str[0])
		return (84);
	while (str[i])
		if (str[i++] == c)
			lines++;
	return (lines);
}

void	my_realloc(char **tab, char *str, char c)
{
	int i = -1;
	int j = 0;
	int k = 0;

	if (!str || !str[0])
		return;
	while (str[++i] != '\0') {
		if (str[i] == c) {
			tab[k++] = malloc((i - j) + 2);
			tab[k] = NULL;
			j = i;
		}
	}
	tab[k] = malloc((i - j) + 2);

}

char	**str_to_array(char *str, char c)
{
	int i = -1;
	int j = 0;
	int k = -1;
	char **tab = malloc(sizeof(char *) * (count_lines(str, c) + 1));

	my_realloc(tab, str, c);
	tab[count_lines(str, c)] = NULL;
	while (str[++i] != '\0' && str[i + 1] != '\0') {
		if (str[i] != c) {
			tab[j][++k] = str[i];
			tab[j][k + 1] = '\0';
		} else {
			tab[j][++k] = '\0';
			++j;
			k = -1;
		}
	}
	free(tab[count_lines(str, c) - 1]);
	tab[count_lines(str, c) - 1] = NULL;
	return (tab);
}