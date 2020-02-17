/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:14:40 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/14 17:28:18 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** not the best variation of checking valid newlines
** but working
*/

int		valid_newlines(char *tetri_buff)
{
	int	i;

	i = -1;
	while (tetri_buff[++i])
	{
		if (i == 0 && tetri_buff[i] == NEWLINE)
			return (0);
		if (i && tetri_buff[i] == NEWLINE &&
				tetri_buff[i - 1] == NEWLINE &&
				tetri_buff[i + 1] == NEWLINE)
			return (0);
		if ((i + 1) % 21 == 0 && tetri_buff[i] != NEWLINE)
			return (0);
		else if ((i + 1) % 21 == 0 && tetri_buff[i] == NEWLINE)
			if (tetri_buff[i - 1] != NEWLINE)
				return (0);
	}
	--i;
	if (tetri_buff[i] == NEWLINE &&
			tetri_buff[i - 1] == NEWLINE)
		return (0);
	return (1);
}

int		valid_symbol(char c)
{
	if (!(c == NEWLINE || c == EMPTY || c == TETRI))
		return (0);
	return (1);
}

int		valid_rows(int inb_nl, int symbols)
{
	if ((symbols > T_SIZE && !inb_nl) ||
			(((symbols - inb_nl) % T_SIZE != 0) &&
			((symbols - inb_nl) / T_SIZE != (inb_nl + 1))))
		return (0);
	return (1);
}

int		four_letter(char *tetri_buff)
{
	int		cnt;
	int		i;
	char	letter;

	i = -1;
	cnt = 0;
	letter = 'A';
	while (tetri_buff[++i])
	{
		if (tetri_buff[i] == letter)
			++cnt;
		if (cnt > 4 && tetri_buff[i] == letter)
			return (0);
		else if (tetri_buff[i] != letter && ft_isalpha(tetri_buff[i]) &&
				cnt == 4)
		{
			letter++;
			cnt = 0;
		}
	}
	return (1);
}
