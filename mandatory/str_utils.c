/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:35 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/17 16:45:33 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

static	double	ft_dot(char *str, double result, int i)
{
	double	pow;

	pow = 1.0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		pow *= 10;
		i++;
	}
	return (result / pow);
}

double	ft_atodbl(char *str)
{
	int		i;
	int		sign;
	double	result;

	result = 0.0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		result = ft_dot(str, result, i);
	return (sign * result);
}
