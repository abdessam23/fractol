/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:31:52 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/13 12:10:55 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	m_x = (double)x / WIDTH * (2.0 -(-2.0)) + (-2.0);
	m_y = (double)y / HEIGHT * (-2.0 - (2.0)) + (2.0);
	if (button == MOUSE_SCROLL_UP)
	{
		z_factor = ZOOM_F;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		z_factor = 1 / ZOOM_F;
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
	if (key == KEY_DOWN)
		fract->offset_y -= 0.1 * fract->zoom;
	else if (key == KEY_UP)
		fract->offset_y += 0.1 * fract->zoom;
	else if (key == KEY_RIGHT)
		fract->offset_x -= 0.1 * fract->zoom;
	else if (key == KEY_LEFT)
		fract->offset_x += 0.1 * fract->zoom;
	else if (key == KEY_PLUS && fract->iteration < 256)
		fract->iteration += 1;
	else if (key == KEY_MINUS && fract->iteration > 10)
		fract->iteration -= 1;
	else if (key == KEY_ESC)
	{
		ft_destroy(fract);
	}
	fract_render(fract);
	return (0);
}

void	ft_hook(t_fractol *fract)
{
	mlx_hook(fract->new_win, DestroyNotify, StructureNotifyMask, handle_close,
		fract);
	mlx_key_hook(fract->new_win, ft_key, fract);
	mlx_mouse_hook(fract->new_win, mouse_handle, fract);
}
