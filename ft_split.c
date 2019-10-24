/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:45:18 by rzafari           #+#    #+#             */
/*   Updated: 2019/10/21 00:46:29 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char			*ft_strcrea(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[j] != '\0' && s[j] != c)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static	int				ft_calcnbwords(char const *s, char c)
{
	int tot;
	int i;

	tot = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tot++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (tot);
}

static	char			**freefunc(char **s)
{
	int	i;

	i = 0;
	while (s)
	{
		free(s);
		s++;
	}
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_calcnbwords(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			if (!(res[j] = ft_strcrea(s + i, c)))
				return (freefunc(res));
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	res[j] = NULL;
	return (res);
}
