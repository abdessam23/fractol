/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/02 18:36:57 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fract_init(t_fractol *fract)
{
    fract->mlx = mlx_init();
    if (fract->mlx == NULL)
        ft_error();
    printf("mlx pointer: %p\n", fract->mlx);
    printf("fract->title: %s\n", fract->title);

    fract->new_win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->title);
    if (fract->new_win == NULL)
    {
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        ft_error();
    }
    fract->img = malloc(sizeof(t_img));
    if (!fract->img)
    {
        mlx_destroy_window(fract->mlx, fract->new_win);
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        free(fract->img);  // Free the allocated img structure as well
        ft_error();
    }
    fract->img->img_p = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    if (!fract->img->img_p)
    {
        mlx_destroy_window(fract->mlx, fract->new_win);
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        free(fract->img);  // Free the allocated img structure as well
        ft_error();
    }
    fract->img->pix = mlx_get_data_addr(fract->img->img_p, &fract->img->bits, &fract->img->l_len, &fract->img->endian);
    
    fract->iteration = 1000;
    fract->escape_v =  4;
}
