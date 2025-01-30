/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/30 09:31:51 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fract_init(char **argv)
{
    t_fractol *fract;
    fract->mlx = mlx_init();
    fract->new_win = mlx_new_window(fract, 600, 600, argv[1])
}