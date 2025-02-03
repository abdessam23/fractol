/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/03 17:01:51 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_close(int key,t_fractol *fract)
{
    printf("%d\n", key);
    if (key == KEY_UP)
        fract->offset_y -= 0.1 / fract->zoom;
    if (key == KEY_DOWN)
        fract->offset_y += 0.1 / fract->zoom;
    if (key == KEY_LEFT)
        fract->offset_x -= 0.1 / fract->zoom;
    if (key == KEY_RIGHT)
        fract->offset_x += 0.1 / fract->zoom;
    if (key == KEY_PLUS)
        fract->zoom *= 1.1;
    if (key == KEY_MINUS)
        fract->zoom /= 1.1;
    if (key == KEY_ESC)
    {
        ft_destroy(fract);
    }
    fract_render(fract);
    return (0);
    
}

int main(int argc, char **argv)
{
    t_fractol   vars;
    
    if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)))|| (argc == 4 && (!ft_strncmp(argv[1], "julia", 5))))
    {
        if (!ft_strncmp(argv[1], "mandelbrot", 10))
            vars.set = 0;
        else
        {
            vars.set = 1;
            vars.julia_x = ft_atodbl(argv[2]);
            vars.julia_y = ft_atodbl(argv[3]);
        }
        vars.title = argv[1];
        fract_init(&vars);
        fract_render(&vars);
        mlx_hook(vars.new_win, 2, 1L<<0, ft_close, &vars);
        mlx_key_hook(vars.new_win, ft_close, &vars);
        mlx_loop(vars.mlx);       
    }
    else
        ft_error();
    return (0);
}
