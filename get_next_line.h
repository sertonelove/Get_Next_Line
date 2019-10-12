/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:33:15 by cpataki           #+#    #+#             */
/*   Updated: 2019/10/12 22:53:20 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 30

# define GNL_ERROR -1
# define GNL_FINISH 0
# define GNL_OK 1

typedef struct				s_gnl
{
	int						fd;
	char					*rest;
	struct s_gnl			*next;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
