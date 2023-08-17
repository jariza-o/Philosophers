/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:58:45 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/17 16:24:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0')
		c++;
	return ((unsigned char)(s1[c]) - (unsigned char)(s2[c]));
}
