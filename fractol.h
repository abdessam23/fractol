/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:03:30 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/05 15:40:11 by abhimi           ###   ########.fr       */
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
# define ZOOM_IN 1.2
# define ZOOM_OUT 0.8

#define BLACK         0x000000    
#define GRAY          0x808080 
#define WHITE         0xFFFFFF
#define LIGHT_GRAY    0xD3D3D3  
#define SILVER        0xC0C0C0   
#define LIGHT_BLUE    0xADD8E6    
#define LIGHT_RED     0xFF6347   
#define LIGHT_GREEN   0x90EE90   
#define YELLOW        0xFFFF00 
#define LIGHT_PURPLE  0x800080

#define KEY_ESC 65307
#define KEY_UP 65364
#define KEY_DOWN 65362
#define KEY_LEFT 65363
#define KEY_RIGHT 65361
#define KEY_PLUS 65453
#define KEY_MINUS 65451

#define MOUSE_LEFT_BUTTON 1
#define MOUSE_MIDDLE_BUTTON 2
#define MOUSE_RIGHT_BUTTON 3
#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

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
    t_img   img;
    int     iteration;
    double  escape_v;
    double  offset_x;
    double  offset_y;
    double  zoom;
    double  julia_x;
    double  julia_y;
    double  set;
    
}  t_fractol;

//string utils
int         ft_destroy(t_fractol *fract);
void        ft_putstr_fd(char  *s, int fd);
size_t      ft_strlen(char   *str);
int         ft_strncmp(char *s1, char *s2, int l);
int         mouse_handle(int button, int x, int y, t_fractol *param);
int         ft_key(int key,t_fractol *fract);
void        ft_error(void);
double      scale_map(double unscale, double new_min, double new_max, double old_min,double old_max);
void        fract_init(t_fractol *fract);
void        fract_render(t_fractol *fract);
t_compx     ft_abs_compx(t_compx z);
t_compx     ft_sum_compx(t_compx z1, t_compx z2);
t_compx     ft_square_compx(t_compx z);
double      ft_atodbl(char *str);

#endif

