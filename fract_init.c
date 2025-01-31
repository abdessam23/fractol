/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/31 11:49:22 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    fract_init(t_fractol *fract)
{
    t_img   img;
    
    fract->mlx = mlx_init();
    if (fract->mlx == NULL)
        ft_error();
    fract->new_win = mlx_new_window(fract, WIDTH, HEIGHT, fract->title);
    if (fract->new_win == NULL)
    {
        mlx_destroy_display(fract);
        free(fract->mlx);
        ft_error();
    }
    fract->img.img_p = mlx_new_image(fract, WIDTH, HEIGHT);
    if (fract->img.img_p)
    {
        mlx_destroy_display(fract);
        mlx_destroy_image(fract, img.img_p);
        free(fract->mlx);
        ft_error();
    }
    fract->img.pix = mlx_get_data_addr(fract->img.img_p, &img.bits, &img.l_len, &img.endian);
    
    fract->iteration = 4;
    
}