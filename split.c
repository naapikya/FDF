/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:05:51 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/29 16:05:52 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_wc(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wl(char const *s, char c)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
		length++;
	}
	return (length);
}

void	norm(char const *s, char c)
{
	while (*s == c)
		s++;
}

static char	**ft_m(char const *s, char c, char **res, int wordcount)
{
	int	i;
	int	j;
	int	word_len;

	norm(s, c);
	i = -1;
	while (++i < wordcount)
	{
		while (*s == c)
			s++;
		j = 0;
		word_len = ft_wl(s, c);
		res[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!(res[i]))
			return (NULL);
		while (j < word_len)
		{
			res[i][j] = *s;
			s++;
			j++;
		}
		res[i][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_wc(s, c);
	res = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!res)
		return (NULL);
	res = ft_m(s, c, res, wordcount);
	return (res);
}
