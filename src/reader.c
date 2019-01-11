/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:03:10 by groberto          #+#    #+#             */
/*   Updated: 2019/01/11 15:52:02 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// esta funcion encuentra la locacion del minimo y el maximo de cada pieza en la malla o el grid.
// obtiene el min y el max del valor de cada pieza.
// cuatro dimensiones array: xmin 0, xmax 1, ymin 2, ymax3

void	min_max(const char *str, char *m) 
{
	unsigned char i;

	i = 0;
	m[0] = 3;
	m[1] = 0;
	m[2] = 3;
	m[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i % 5 > m[1])
				m[1] = i % 5;
			if (i / 5 < m[2])
				m[2] = i / 5;
			if (i / 5 > m[3])
				m[3] = i / 5;
		}
		i++;
	}
}

// esta funcion verifica que las piezas tengan una forma valida si tenemos 6 o 8 connecciones
// el tetrimino es valido. asumiendo que el tetriminio tiene 4 bloques.

int		check_connect(char *buff)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if ((i + 1) < 20 && buff[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && buff[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && buff[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && buff[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

// esta funcion checkea para ver si el buff de las piezas tiene el formato correcto entre char y si es valido.

int			check_format(char *buff)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19) //vamos a checkear todos los newline.
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (!(buff[i] == '.' || buff[i] == '#'))
			return (0);
		++i;
	}
	if (!(buff[20] == '\n' || buff[20] == '\0')) //si buff termina en newline o fin de la str esta bien y sale
		return (0);
	return (1);
}

// esta funcion va a verificar que la pieza en el buffer tiene el correcto numero de
// gatos y puntos.

int			check_count(char *buff)
{
	int	i;
	int	space;
	int	sharp;

	i = 0;
	space = 0;
	sharp = 0;
	while (i < 20)
	{
		if (buff[i] == '.')
			++space;
		else if (buff[i] == '#')
			++sharp;
		++i;
	}
	if ((sharp == 4) && (space == 12)) // en total son 4 gatos y 12 puntos.
		return (1);
	else
		return (0);
}

//lee las piezas de un trozo valido y las pone en la estructura.
//esta funcion convierte las piezas en el struct element 

t_tetro     *get_piece(const char *str, const char addr)
{
	t_tetro	*tetris;
	char	m[4];
	unsigned int		x;
	unsigned int		y;

	min_max(str, m);
	tetris = (t_tetro *)malloc(sizeof(t_tetro));
	ft_bzero(tetris, sizeof(t_tetro));
	tetris->width = m[1] - m[0] + 1;
	tetris->height = m[3] - m[2] + 1;
	tetris->addr = addr;
	tetris->count = 0;
	tetris->last = NULL;
	y = 0;
	while (y < tetris->height)
	{
		x = 0;
		while (x < tetris->width)
		{
			if (str[(m[0] + x) + (m[2] + y) * 5] == '#')
				tetris->count |= (1L << (16 * (y + 1) - 1 - x));
			x++;
		}
		y++;
	}
	return (tetris);
}
