/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciafe2 <luciafe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:28:06 by luciafe2          #+#    #+#             */
/*   Updated: 2023/10/23 16:43:26 by luciafe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It divides an string using char 'c' as delimiter.

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
			i++;
		}	
	}
	return (count);
}

static void	ft_free(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(*(str + i));
	}
	free(str);
}

static char	*extract_word(char const *s, char c, size_t *start)
{
	size_t	end;
	char	*word;

	while (s[*start] && s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	word = ft_substr(s, *start, end - *start);
	if (!word)
	{
		return (NULL);
	}
	*start = end;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	words;
	size_t	start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (i < words)
	{
		array[i] = extract_word(s, c, &start);
		if (!array[i])
		{
			ft_free(i, array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
