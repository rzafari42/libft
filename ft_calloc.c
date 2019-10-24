/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:59:31 by rzafari           #+#    #+#             */
/*   Updated: 2019/10/20 18:03:48 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*str;
	size_t		mult;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	mult = count * size;
	if (!(str = malloc(mult)))
		return (NULL);
	ft_bzero(str, mult);
	return (str);
}
