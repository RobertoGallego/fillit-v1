/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:27:11 by groberto          #+#    #+#             */
/*   Updated: 2019/01/11 17:12:23 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "stdio.h" // eliminar

// lee 21 char desde el f, cada pieza valida consiste en 21 char incluyendo
// newline, despues las piezas buenas son checkeadas y convertidas a un struct
// o un error.

int		read_tetriminos(int fd, t_tetro **arr)
{
	char	buff[21]; // 16 char contando los  4 newlines y la 1 separacion.
	char	letter; // letra de los tetriminos
	int		count; // valor de 1 bloque
	int		i; 

	i = 0;
	letter = 'A' - 1;
	while (((count = read(fd, buff, 21)) >= 20) && i < 26)
	{
		if (count == 20) // cuando es valido tomo los primeros 20 valores 0 a 20 = 21
			buff[20] = '\0'; // pone el ultimo es fin de la str quita el final new line
		if (!(check_format(buff) && check_count(buff) && check_connect(buff))) // checkeo todo los tipos del maps y si no son validos return 0
			return (0);
		arr[i] = get_piece(buff, letter++);
		arr[i]->addr = letter;
		++i;
	}
	if (count != 0 || buff[20] != '\0' || !arr[0]) // checkeo que este correcto
		return (0);
//	printf("%d\n %d\n", addr, count);
	return (1);
}

// entrada del programa.

int		main(int argc, char **argv)
{
	t_tetro				*arr[27]; // 26 tetriminos + 1 de 0 a 26 = 27
	//unsigned short int	map[16]; // 16 diferentes tetriminos
	int					fd;

	if (argc != 2)
	{
		ft_putendl("./fillit [input_file]"); // en caso de no poner el fd
		return (-1);
	}
	ft_bzero(arr, sizeof(arr));
	if (!(fd = open(argv[1], O_RDONLY))) // en caso de no lectura
	{
		ft_putendl("error");
		return (-1);
	}
	//ft_bzero(map, sizeof(map));
	if (!(read_tetriminos(fd, arr))) // es indiferente o 0 return error. si el fd es y el array es indiferente error.
	{
		ft_putendl("error");
		return (-1);
	}
	// solver
	printf("%p\n", arr[0]);
	printf("%p\n", arr[1]);
	printf("%p\n", arr[2]);
//	printf("%d %d\n", addr, count);
//	solver(arr, map);
	return (0);
}
