/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/17 16:53:54 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_error_arg(void)
{
	ft_putstr_fd("Usage:\n\n./fractol mandelbrot\n\n", 2);
	ft_putstr_fd("./fractol julia x y\n\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	vars;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10))) || (argc == 4
			&& (!ft_strncmp(argv[1], "julia", 5) && ft_isvalid(argv[2])
				&& ft_isvalid(argv[3]))))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			vars.julia_x = ft_atodbl(argv[2]);
			vars.julia_y = ft_atodbl(argv[3]);
		}
		vars.height = 800;
		vars.width = 800;
		vars.title = argv[1];
		fract_init(&vars, argv);
		fract_render(&vars);
		ft_hook(&vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_error_arg();
	return (0);
}
