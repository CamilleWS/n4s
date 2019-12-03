/*
** EPITECH PROJECT, 2017
** n4s
** File description:
** my_put
*/

#include "../include/my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int i = -1;

	while (str && str[++i])
		my_putchar(str[i]);
}

void	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		my_put_nbr(-nb);
	} else if (nb > 9) {
		my_put_nbr(nb / 10);
		my_putchar((nb % 10) + '0');
	} else
		my_putchar(nb + '0');
}

void	my_put_float(double nb)
{
	int tmp;

	if (nb <= 0) {
		my_putchar('-');
		nb *= -1;
	}
	tmp = (int)nb;
	my_put_nbr(tmp);
	nb -= (tmp < nb) ? tmp : (tmp - 1);
	my_putchar('.');
	nb *= 1000;
	my_put_nbr((int)nb);
}

int	my_get_nbr(char *str)
{
	int neg = 1;
	int nb = 0;
	int i = -1;

	while (str[++i] == '-')
		neg *= -1;
	--i;
	while (str[++i] <= '9' && str[i] >= '0')
		nb = (nb * 10) + (str[i] - '0');
	return (nb * neg);
}
