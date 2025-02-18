/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:43:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/18 08:44:22 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	ft_error_arg(void)
{
	ft_putstr_fd("Usage: \n./fractol_bonus burning_ship\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	vars;

	if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
	{
		vars.height = 800;
		vars.width = 800;
		vars.title = argv[1];
		fract_init(&vars);
		b_fract_render(&vars);
		ft_hook(&vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_error_arg();
	return (0);
}
