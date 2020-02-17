/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_buff2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:03:42 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/14 15:32:45 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** hack for validation if there's an empty tetromino
**
** I'm pretty sure that I have another function with same functionality
** inside it but I don't want to check it out
**
** just for sure we count newlines and tetri '#'
** every 4 newlines we check if we have also 4 tetri
** if everything is alright we reset counters to zero
*/

int		empty_tetromino(char *tetri_buff)
{
	int	i;
	int	n;
	int	t;

	i = -1;
	n = 0;
	t = 0;
	while (tetri_buff[++i])
	{
		if (tetri_buff[i] == NEWLINE)
			++n;
		if (tetri_buff[i] == TETRI)
			++t;
		if (n == 4 && t != 4)
			return (1);
		if (n == 4)
		{
			n = 0;
			t = 0;
		}
	}
	return (0);
}

/*
** nice function to find number of shapes for single letter
**
** we check if there's something on the left, right,
** top, and bottom of our letter equal to it
** if we find a connection we add it to all letter's connections' number
** 'cause previously we transform all tetrominoes from '#'-view to
** 'unique-letter'-view we can be sure that
** we don't count wrong connections
*/

int		get_letter_shapes(char *tetri_buff, int i, char letter)
{
	int	shapes;

	shapes = 0;
	if (i && tetri_buff[i - 1] == letter)
		++shapes;
	if (tetri_buff[i + 1] && tetri_buff[i + 1] == letter)
		++shapes;
	if (i >= T_COLS && tetri_buff[i - T_COLS] == letter)
		++shapes;
	if (tetri_buff[i + T_COLS] && tetri_buff[i + T_COLS] == letter)
		++shapes;
	return (shapes);
}

/*
** this function checks if there's invalid tetrominoes with wrong
** number of shapes. every tetromino must have 6 or 8 connections between
** its' minoes. so we find a letter and than check it for connections.
** when tetromino ends we check final number of connections
** if it's not 6 or 8 - we have invalid tetromino
*/

int		valid_shapes(char *tetri_buff)
{
	int		i;
	char	letter;
	int		shapes;

	i = -1;
	letter = 'A';
	shapes = 0;
	while (tetri_buff[++i])
	{
		if (tetri_buff[i] == letter)
			shapes += get_letter_shapes(tetri_buff, i, letter);
		if (tetri_buff[i] != letter && ft_isalpha(tetri_buff[i]))
		{
			if (!(shapes == 6 || shapes == 8))
				return (0);
			--i;
			letter++;
			shapes = 0;
		}
	}
	if (!(shapes == 6 || shapes == 8))
		return (0);
	return (1);
}
