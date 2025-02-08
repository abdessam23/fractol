/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:49 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/06 16:26:03 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_compx    ft_square_compx(t_compx z)
{
    t_compx res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * (z.x) * (z.y);
    return (res);
}

t_compx ft_sum_compx(t_compx c1, t_compx c2)
{
    t_compx sum;
    
    sum.x = c1.x + c2.x;
    sum.y = c1.y + c2.y;
    return (sum);
}

t_compx     ft_abs_compx(t_compx z)
{
    t_compx abs;

    abs.x = fabs(z.x);
    abs.y = fabs(z.y);
    return (abs);
}

double  scale_map(double unscale, double new_min, double new_max, double old_min,double old_max)
{
    return ((new_max - new_min) * (unscale - old_min) /(old_max - old_min) + new_min);
}

void   ft_error()
{
    perror("problem of allocation");
    exit(1);
}
