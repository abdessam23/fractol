/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/03 16:17:05 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_destroy(t_fractol *fract)
{
    if(fract->img.img_p)
        mlx_destroy_image(fract->mlx, fract->img.img_p);
    if(fract->new_win)
        mlx_destroy_window(fract->mlx, fract->new_win);
    if(fract->mlx)
        mlx_destroy_display(fract->mlx);
    if(fract->mlx)
        free(fract->mlx);
    exit (0);
    return (0);
}

void    fract_init(t_fractol *fract)
{
    if (fract == NULL)
        return ;
    fract->mlx = mlx_init();
    if (fract->mlx == NULL)
        ft_error();
    fract->new_win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->title);
    if (fract->new_win == NULL)
    {
        ft_destroy(fract);
        ft_error();
    }
    fract->img.img_p = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    if (fract->img.img_p == NULL)
    {
        ft_destroy(fract);
        ft_error();
    }
    fract->img.pix = mlx_get_data_addr(fract->img.img_p, &fract->img.bits, &fract->img.l_len, &fract->img.endian);
    fract->iteration = 42;
    fract->escape_v =  4;
    fract->zoom =1;
    fract->offset_x =0.0;
    fract->offset_y = 0.0;
}
