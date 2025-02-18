/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:03:30 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/18 08:39:11 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_p;
	char	*pix;
	int		l_len;
	int		endian;
	int		bits;
}			t_img;

typedef struct s_compx
{
	double	x;
	double	y;
}			t_compx;

typedef struct s_fractol
{
	void	*mlx;
	void	*new_win;
	char	*title;
	t_img	img;
	int		height;
	int		width;
	int		iteration;
	double	escape_v;
	double	offset_x;
	double	offset_y;
	double	zoom;
}			t_fractol;

// string utils
int			ft_destroy(t_fractol *fract);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, int l);

// utils
void		ft_error(void);
t_compx		ft_abs_compx(t_compx z);
t_compx		ft_sum_compx(t_compx z1, t_compx z2);
t_compx		ft_square_compx(t_compx z);
double		scale_map(double unscale, double n_min, double n_max, double o_max);
int			ft_key(int key, t_fractol *fract);
void		ft_hook(t_fractol *fract);
// main
void		fract_init(t_fractol *fract);
void		b_fract_render(t_fractol *fract);
void		ft_hook(t_fractol *fract);

#endif
