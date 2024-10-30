/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:34:17 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/23 15:44:18 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_parts(const char *s, char c);
static char		**ft_splitstr(char const *s, char c, char **strs, size_t segs);
static size_t	ft_partslen(char const *s, char sep);
static char		**ft_free(char **strs, size_t seg);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	count_parts;

	if (s == NULL)
		return (NULL);
	count_parts = ft_count_parts(s, c);
	strs = malloc(sizeof(char *) * (count_parts + 1));
	if (strs == NULL)
		return (NULL);
	strs[count_parts] = 0;
	if (count_parts > 0)
	{
		ft_splitstr(s, c, strs, count_parts);
	}
	return (strs);
}

static size_t	ft_count_parts(const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	boolean;

	boolean = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && !boolean)
		{
			boolean = 1;
			++count;
		}
		if (s[i] == c && boolean)
			boolean = 0;
		i++;
	}
	return (count);
}

static char	**ft_splitstr(char const *s, char c, char **strs, size_t segs)
{
	size_t	segment;
	size_t	i;
	size_t	j;

	i = 0;
	segment = 0;
	while (segment < segs)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		strs[segment] = malloc(sizeof(char) * (ft_partslen(&s[i], c) + 1));
		if (strs[segment] == NULL)
			return (ft_free(strs, segment));
		while (s[i] && s[i] != c)
		{
			strs[segment][j] = s[i];
			j++;
			i++;
		}
		strs[segment][j] = '\0';
		segment++;
	}
	return (strs);
}

static size_t	ft_partslen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **strs, size_t seg)
{
	size_t	i;

	i = 0;
	while (i < seg)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}
/*
int main(int argc, char **argv)
{
	char **idk;
	size_t	i = 0;
	if(argc >= 3)
	{	
		idk = ft_split(argv[1], *argv[2]);
		while (idk[i] != 0)
		{
			printf("%s\n", idk[i]);	
			free(idk[i]);
			i++;
		}
		free(idk);
	}
	else
		printf("Not enough arguments");
}*/
