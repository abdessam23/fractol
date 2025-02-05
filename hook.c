/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:31:52 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/05 16:19:56 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_handle(int button, int x, int y, t_fractol *fract)
{
    double  m_x;
    double  m_y;
    if (button == MOUSE_SCROLL_DOWN)
    {
        m_x = (x - WIDTH / 2.0) / (0.5 * WIDTH * fract->zoom) + fract->offset_x;
        m_y = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * fract->zoom) + fract->offset_y;
        fract->zoom *= ZOOM_OUT;
        fract->offset_x = m_x - (x - WIDTH / 2.0) / (0.5 * WIDTH * fract->zoom);
        fract->offset_y = m_y - (y - HEIGHT / 2.0) / (0.5 * HEIGHT * fract->zoom);
    }
    else if (button == MOUSE_SCROLL_UP)
    {
        m_x = (x - WIDTH / 2.0) / (0.5 * WIDTH * fract->zoom) + fract->offset_x;
        m_y = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * fract->zoom) + fract->offset_y;
        fract->zoom *= ZOOM_IN;
        fract->offset_x = m_x - (x - WIDTH / 2.0) / (0.5 * WIDTH * fract->zoom);
        fract->offset_y = m_y - (y - HEIGHT / 2.0) / (0.5 * HEIGHT * fract->zoom);
    }
    fract_render(fract);
    return (0);
}

int ft_key(int key,t_fractol *fract)
{
    if (!fract)
        return (1);
    if (key == KEY_UP)
        fract->offset_y -= 0.1 / fract->zoom;
    if (key == KEY_DOWN)
        fract->offset_y += 0.1 / fract->zoom;
    if (key == KEY_LEFT)
        fract->offset_x -= 0.1 / fract->zoom;
    if (key == KEY_RIGHT)
        fract->offset_x += 0.1 / fract->zoom;
    if (key == KEY_ESC)
    {
        ft_destroy(fract);
    }
    fract_render(fract);
    return (0);
    
}
