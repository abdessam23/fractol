/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:51:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/31 11:46:58 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y,t_img *img, int color)
{
    int offset;

    offset = (y * img->l_len) + (x * img-> / 8);
    (unsigned int *)(offset * img->pix) = color;
} 
void    handel_pixel(int x, int y, t_fractol *fract)
{
    t_compx z;
    t_compx c;
    int i;
    int  color;

    i = 0;
    z.x = 0;
    z.y = 0;
    c.x = scale_map(x,-2, 2, 0, WIDTH) //* fract->zoom + fract->offset_x;
    c.y = scale_map(y, 2, -2, 0, HEIGHT) //* fract->zoom + fract->offse_y;
    while (i < fract->iteration)
    {
        z = ft_sum_compx(ft_square_compx(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fract->escape)
        {
            color = scale_map(i, BLACK, WHITE, 0, fract->iteration);
            my_pixel_put(x, y, &fract->img, color); 
        }
    }
     my_pixel_put(x, y, &fract->img, BLACK);
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