/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:51:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/05 16:18:09 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    
    if (!img || !img->pix)
        return;
    offset = (y * img->l_len) + (x * (img->bits / 8));
    *(unsigned int *)(img->pix + offset) = color;
}
void init_mandelbrot(int x, int y, t_compx *z, t_compx *c, t_fractol *fract)
{
    if (!fract)
        return;
    z->x = 0.0;
    z->y = 0.0;
    c->x = scale_map(x, -2, 2, 0, WIDTH) * fract->zoom + fract->offset_x;
    c->y = scale_map(y, -2, 2, 0, HEIGHT) * fract->zoom + fract->offset_y;
}

void init_julia(int x, int y, t_compx *z, t_compx *c, t_fractol *fract)
{
    if (!fract)
        return;
    z->x = scale_map(x, -2, 2, 0, WIDTH) * fract->zoom + fract->offset_x;
    z->y = scale_map(y, -2, 2, 0, HEIGHT) * fract->zoom + fract->offset_y;
    c->x = fract->julia_x;
    c->y = fract->julia_y;
}
void handel_pixel(int x, int y, t_fractol *fract)
{
    t_compx z;
    t_compx c;
    int i;
    int color;

    if (!fract || !fract->img.img_p || !fract->img.pix || 
        x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    i = 0;
    if (fract->set == 0 || !ft_strncmp(fract->title, "burning_ship", 12))
        init_mandelbrot(x, y, &z, &c, fract);
    else
        init_julia(x, y, &z, &c, fract);
    while (i < fract->iteration)
    {
        if (!ft_strncmp(fract->title, "burning_ship", 12))
            z = ft_abs_compx(z);
        z = ft_sum_compx(ft_square_compx(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fract->escape_v)
        {
            color = scale_map(i, BLACK, LIGHT_RED, 0, fract->iteration);
            my_pixel_put(x, y, &fract->img, color);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &fract->img, BLACK);
}

void fract_render(t_fractol *fract)
{
    int x;
    int y;
   
    if (!fract)
        return;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handel_pixel(x, y, fract);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fract->mlx, fract->new_win, fract->img.img_p, 0, 0);
}