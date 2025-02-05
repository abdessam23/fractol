/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/05 16:29:42 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_close(t_fractol *fract)
{
    if (fract)
    {
        ft_destroy(fract);
        exit (0);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_fractol   vars;
    
    if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)))|| (argc == 4 && (!ft_strncmp(argv[1], "julia", 5))) || 
        !ft_strncmp(argv[1], "burning_ship", 12))
    {
        if (!ft_strncmp(argv[1], "mandelbrot", 10))
            vars.set = 0;
        else if (argc == 4 && (!ft_strncmp(argv[1], "julia", 5))) 
        {
            vars.set = 1;
            vars.julia_x = ft_atodbl(argv[2]);
            vars.julia_y = ft_atodbl(argv[3]);
        }
        vars.title = argv[1];
        fract_init(&vars);
        fract_render(&vars);
        mlx_hook(vars.new_win, DestroyNotify, StructureNotifyMask, handle_close, &vars);
        mlx_key_hook(vars.new_win, ft_key, &vars);
        mlx_mouse_hook(vars.new_win, mouse_handle, &vars);
        mlx_loop(vars.mlx);
        ft_destroy(&vars);      
    }
    else
    {    
        ft_putstr_fd(" -------------Usage:---------- \n || ./fractol mandelbrot    || \n || ./fractol julia x y     || \n || ./fractol burning_ship  ||\n", 2);
        ft_putstr_fd(" -----------------------------\n", 2);
        exit(1);
    }
    return (0);
}
