/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:42:19 by jkarren           #+#    #+#             */
/*   Updated: 2020/08/30 15:43:21 by ugla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this func locate str delimited by '\n'
** and place this str into fd stack arr
**
** you can easily find each fd with its
** actual line pointer 'cause func use fd as
** stack arr index
*/

int		catch_line(char **stack, char *subline, int fd)
{
	int		rst;
	char	*tmp;

	while ((rst = read(fd, subline, BUFF_SIZE)) > 0)
	{
		subline[rst] = '\0';
		if (!(stack[fd]))
			stack[fd] = ft_strdup(subline);
		else
		{
			tmp = ft_strjoin(stack[fd], subline);
			free(stack[fd]);
			stack[fd] = tmp;
		}
		if (ft_isinarr('\n', stack[fd]))
			break ;
	}
	return (rst);
}

/*
** this func update line pointer to actual place lurking
** to actual subline placed into fd stack arr earlier
**
** there's no another return than (1) 'cause if you do
** this step you already doing right things
**
** func just update actual data
*/

int		upd_line(char **line, char **stack)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((*stack)[i]) && (*stack)[i] != '\n')
		++i;
	if ((*stack)[i])
	{
		*line = ft_strsub(*stack, 0, i);
		tmp = ft_strdup(&((*stack)[i + 1]));
		free(*stack);
		*stack = tmp;
		if (!((*stack)[0]))
			ft_strdel(stack);
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		subline[BUFF_SIZE + 1];
	int			rst;

	if (fd < 0 || line == NULL)
		return (-1);
	rst = catch_line(stack, subline, fd);
	if (!rst && !stack[fd])
		return (0);
	else if (rst < 0)
		return (-1);
	else
		return (upd_line(line, &stack[fd]));
}
