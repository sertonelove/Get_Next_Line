/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:17:43 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/05 16:12:42 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isupper(int c)
{
	if (ft_ischar(c))
	{
		if (c >= 'A' && c <= 'Z')
			return (1);
	}
	return (0);
}
