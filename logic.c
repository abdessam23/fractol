/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:51:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/30 15:49:02 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    handel_pixel(double x, double y, t_vars *fract)
{
    t_compx z;
    t_compx c;
    int i;

    i = 0;
    z.x = 0;
    z.y = 0;
    c.x = scale_map(x,-2, 2, 0, WIDTH) * fract->zoom + fract->offset_x;
    c.y = scale_map(y, 2, -2, 0, HEIGHT) * fract->zoom + fract->offse_y;
    while (i < iteration)
    {
        z = ft_sum_compx(ft_square_compx(z), c);
        if ((z.x * z.x) - (z.y * z.y) < 4)
        {
            mlx_put_image_to_window        
        }
    }
}
void    fract_rendr(t_vars fract)
{
    int x;
    int y;
    
    y = 0;
    while (y < HIGHT)
    {
        x = 0;
        while (x < WITH)
        {
            handel_pixel(x,y, &fract);
            x++;
        }
        y++;
    }
    mlx_disp_imag_win(fract->img, fract->win,);
}