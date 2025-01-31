/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/31 09:28:53 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   vars;
    
    if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) )||
            argc == 4 && (!ft_strncmp(argv[1], "julia", 5)))
    {
        vars.title = argv[1];
        fract_init(&vars);
        fractol_render(&vars);
        mlx_loop(vars.mlx);       
            
    }
    else
        ft_error("ERROR\n");
    return (0);
}