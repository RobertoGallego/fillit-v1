/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:26:29 by groberto          #+#    #+#             */
/*   Updated: 2019/01/11 17:20:57 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef unsigned long long int	t_64;

typedef struct					s_tetro
{
	t_64			count;
	char			addr;
	unsigned int	width;
	unsigned int	height;
	unsigned int	x;
	unsigned int	y;
	struct t_tetro			*last;
}								t_tetro;


int								check_count(char *buff);
int								check_format(char *buff);
int								check_connect(char *buff);
void							min_max(const char *str, char *m);
t_tetro							*get_piece(const char *str, const char addr);

#endif
