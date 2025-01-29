/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:49 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/29 11:41:23 by abhimi           ###   ########.fr       */
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
t_compx ft_sum_compx(t_compx z)
{
    t_compx sum;
    
    sum.x = z.x + z.x;
    sum.y = z.y + z.y;
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
    return ((new_max - new_max) * (unscale - old_min) /(old_max - old_min) + new_min);
}
 static double  ft_helper()
double  ft_atodbl(char *str)
{
    int i;
    int sign;
    double result;
    double pow;


    result = 0.0;
    i = 0;
    pow = 1.0;
    sign = 1;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    if (str[i] == '.')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    if (str[i] == '.')
    {
        i++
        while (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + str[i] - '0';
            pow *= 10;
            i++;
        }
    }
    return (sign * result / pow);
}
