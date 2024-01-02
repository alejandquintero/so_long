/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:32 by aquinter          #+#    #+#             */
/*   Updated: 2024/01/02 18:09:52 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s;
	while (*s != '\0')
	{
		if (*s == (char)c)
			pos = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (*pos == (char)c)
		return (pos);
	return (NULL);
}
