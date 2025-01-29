/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:03:30 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/28 12:46:09 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 600
# define WIDTH 600
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_img
{
    void    *img_p;
    char    *pix;
    int     l_len;
    int     endian;
    int     bits;
} t_img;

typedef struct s_compx
{
    double  x;
    double  y;
} t_compx;

typedef struct s_fractol
{
    void    *mlx;
    void    *new_win;
}  t_fractol;

//string utils
void        ft_putstr_fd(char  *s, int fd);
size_t      ft_strlen(char   *str);
int         ft_strncmp(char *s1, char *s2, int l);
void        ft_error(char    *str);
double  scale_map(double unscale, double new_min, double new_max, double old_min,double old_max);


#endif

