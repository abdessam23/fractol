/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:31:52 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/17 16:45:29 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close(t_fractol *fract)
{
	if (fract)
	{
		ft_destroy(fract);
		exit(0);
	}
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractol *fract)
{
	double	m_x;
	double	m_y;
	double	z_factor;

	m_x = (double)x / fract->width * (2.0 -(-2.0)) + (-2.0);
	m_y = (double)y / fract->height * (2.0 - (-2.0)) + (-2.0);
	if (button == 4)
	{
		z_factor = 1.05;
	}
	else if (button == 5)
	{
		z_factor = 0.85;
	}
	else
		z_factor = 1.0;
	if (z_factor != 1.0)
	{
		fract->offset_x = (fract->offset_x - m_x) * z_factor + m_x;
		fract->offset_y = (fract->offset_y - m_y) * z_factor + m_y;
		fract->zoom *= z_factor;
		fract_render(fract);
	}
	return (0);
}

int	ft_key(int key, t_fractol *fract)
{
	if (!fract)
		return (1);
	if (key == 65362)
		fract->offset_y -= 0.1 * fract->zoom;
	else if (key == 65364)
		fract->offset_y += 0.1 * fract->zoom;
	else if (key == 65361)
		fract->offset_x -= 0.1 * fract->zoom;
	else if (key == 65363)
		fract->offset_x += 0.1 * fract->zoom;
	else if (key == 65451 && fract->iteration < 256)
		fract->iteration += 1;
	else if (key == 65453 && fract->iteration > 10)
		fract->iteration -= 1;
	else if (key == 65307)
	{
		ft_destroy(fract);
	}
	fract_render(fract);
	return (0);
}

void	ft_hook(t_fractol *fract)
{
	mlx_hook(fract->new_win, 17, 0, handle_close, fract);
	mlx_key_hook(fract->new_win, ft_key, fract);
	mlx_mouse_hook(fract->new_win, mouse_handle, fract);
}

int	ft_isvalid(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if ((s[i - 1] >= '0' && s[i - 1] <= '9') && s[i] == '\0')
		return (1);
	else
		return (0);
}
