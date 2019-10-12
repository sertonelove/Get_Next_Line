/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:33:00 by cpataki           #+#    #+#             */
/*   Updated: 2019/10/12 20:46:31 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_rest(char *rest, char **line)
{
	char			*pointer_n;

	pointer_n = NULL;
	if (rest)
		if ((pointer_n = ft_strchr(rest, '\n')))
		{
			*pointer_n = '\0';
			*line = ft_strdup(rest);
			ft_strcpy(rest, ++pointer_n);
		}
		else
		{
			*line = ft_strdup(rest);
			ft_strclr(rest);
		}
	else
		*line = ft_strnew(1);
	return (pointer_n);
}

int		get_line(const int fd, char **line, char **rest)
{
	char			buf[BUFF_SIZE + 1];
	int				read_bytes;
	char			*pointer_n;
	char			*tmp;

	pointer_n = check_rest(*rest, line);
	while (!pointer_n && (read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_bytes] = '\0';
		if ((pointer_n = ft_strchr(buf, '\n')))
		{
			*pointer_n = '\0';
			*rest = ft_strdup(++pointer_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || read_bytes < 0)
			return (GNL_ERROR);
		free(tmp);
	}
	return ((read_bytes || ft_strlen(*line))
		? GNL_OK : GNL_FINISH);
}

t_gnl	*new_list(const int fd)
{
	t_gnl			*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->rest = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == NULL)
		return (GNL_ERROR);
	if (head == NULL)
		head = new_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->rest));
}
