/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:58:45 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/03 18:45:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0')
		c++;
	return ((unsigned char)(s1[c]) - (unsigned char)(s2[c]));
}

int	ft_atoi(const char *str)
{
	int	count;
	int	signo;
	int	buffer;

	count = 0;
	signo = 1;
	buffer = 0;
	while ((str[count] >= '\t' && str[count] <= '\r')
		|| str[count] == 32)
		count++;
	if (str[count] == 43 || str[count] == 45)
	{
		if (str[count] == 45)
			signo *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		buffer = (str[count] - '0') + (buffer * 10);
		count++;
	}
	return (signo * buffer);
}

long int	ft_atol(const char *str)
{
	int			count;
	int			signo;
	long int	buffer;

	count = 0;
	signo = 1;
	buffer = 0;
	while ((str[count] >= '\t' && str[count] <= '\r')
		|| str[count] == 32)
		count++;
	if (str[count] == 43 || str[count] == 45)
	{
		if (str[count] == 45)
			signo *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		buffer = (str[count] - '0') + (buffer * 10);
		count++;
	}
	return (signo * buffer);
}
