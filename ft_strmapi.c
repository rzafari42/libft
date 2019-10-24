/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:18:29 by rzafari           #+#    #+#             */
/*   Updated: 2019/10/21 00:27:30 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		j;
	char				*res;

	j = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (s[j])
	{
		res[j] = f(j, s[j]);
		j++;
	}
	res[j] = '\0';
	return (res);
}
