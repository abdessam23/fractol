/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/28 16:55:17 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   *vars;
    
    if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) )||
            argc == 4 && (!ft_strncmp(argv[1], "julia", 5)))
    {
        vars->mlx = mlx_init();
        vars->new_win = mlx_new_window(vars, 600, 600, argv[1]);
               
            
    }
    else
        ft_error("ERROR\n");
    return (0);
}