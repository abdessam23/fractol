/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:03:30 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/03 13:24:21 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# define HEIGHT 800
# define WIDTH 800

#define BLACK         0x000000  
#define DARK_GRAY     0x404040  
#define GRAY          0x808080 
#define WHITE         0xFFFFFF
#define LIGHT_GRAY    0xD3D3D3  
#define SILVER        0xC0C0C0  
#define DARK_BLUE     0x00008B  
#define LIGHT_BLUE    0xADD8E6  
#define DARK_RED      0x8B0000  
#define LIGHT_RED     0xFF6347  
#define DARK_GREEN    0x006400  
#define LIGHT_GREEN   0x90EE90  
#define DARK_YELLOW   0x9B870C  
#define LIGHT_YELLOW  0xFFFFE0  
#define DARK_PURPLE   0x4B0082  
#define LIGHT_PURPLE  0xD8B0FF
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
    char    *title;
    t_img   *img;
    int     iteration;
    double  escape_v;
    double  offset_x;
    double  offset_y;
    double  zoom;
    
}  t_fractol;

//string utils
void        ft_putstr_fd(char  *s, int fd);
size_t      ft_strlen(char   *str);
int         ft_strncmp(char *s1, char *s2, int l);
void        ft_error(void);
double      scale_map(double unscale, double new_min, double new_max, double old_min,double old_max);
void        fract_init(t_fractol *fract);
void        fract_render(t_fractol *fract);
t_compx     ft_abs_compx(t_compx z);
t_compx     ft_sum_compx(t_compx z1, t_compx z2);
t_compx     ft_square_compx(t_compx z);

#endif

