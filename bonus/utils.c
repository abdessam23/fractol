/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:49 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/17 16:44:26 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

t_compx	ft_square_compx(t_compx z)
{
	t_compx	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * (z.x) * (z.y);
	return (res);
}

t_compx	ft_sum_compx(t_compx c1, t_compx c2)
{
	t_compx	sum;

	sum.x = c1.x + c2.x;
	sum.y = c1.y + c2.y;
	return (sum);
}

t_compx	ft_abs_compx(t_compx z)
{
	t_compx	abs;

	abs.x = fabs(z.x);
	abs.y = fabs(z.y);
	return (abs);
}

double	scale_map(double unscale, double n_min, double n_max, double o_max)
{
	return (unscale * (n_max - n_min) / o_max + n_min);
}

void	ft_error(void)
{
	perror("problem of allocation.");
	exit(1);
}
