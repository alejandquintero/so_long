/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:04:21 by aquinter          #+#    #+#             */
/*   Updated: 2024/02/03 11:47:40 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	len_number(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(long n, char *str)
{
	long	p;
	long	aux;
	int		i;

	p = 1;
	aux = n;
	while (aux > 0)
	{
		aux /= 10;
		p *= 10;
	}
	p /= 10;
	i = 0;
	while (p > 0)
	{
		str[i] = ((n / p) % 10) + '0';
		p /= 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	if (n == 0)
		return (NULL);
	nbr = n;
	str = malloc((len_number(nbr) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		nbr *= -1;
		i++;
	}
	fill_str(nbr, str + i);
	return (str);
}
