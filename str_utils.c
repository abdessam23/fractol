/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:35 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/31 09:59:00 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t ft_strlen(char   *str)
{
    size_t  i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}
int ft_strncmp(char *s1, char *s2, int l)
{
    int i;

    i = 0;
    while (s1[i] && i < l)
    {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void    ft_putstr_fd(char  *s, int fd)
{
    if (!s || fd < 0)
        return;
    while(*s)
    {
        write(fd, s, 1);
        s++;
    }
}

void   ft_error()
{
    perror("problem of allocation");
    exit(1);
}
