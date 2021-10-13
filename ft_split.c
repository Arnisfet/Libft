/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:26:26 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:26:29 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция итерируется по строке, подсчитывая слова при нахождении
разделительного символа с. Создает массив указателей куда записывается
каждое слово по отдельности.

return: Указатель на начало массива arr_2 (arr_2 - massiv) сделано для
возрата к нулевому указателю, так как запись идет по адресам.

Use function: ft_count_words - подсчет слов; ft_strndup - выделение памяти
для н символов.*/


#include "libft.h"

static size_t		word_count(char const *s, char c)
{
	size_t		ret;
	int			i;

	ret = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			ret++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (ret);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	if (tab)
		free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char		**tab;
	char		*curr;
	char		*delim;
	size_t		i;

	i = 0;
	if (!s || (tab = ft_calloc(word_count(s, c) + 1, sizeof(char *))) == NULL)
		return (NULL);
	curr = (char *)s;
	while (*curr == c)
		curr++;
	while ((delim = ft_strchr(curr, c)) && i < word_count(s, c))
	{
		if ((tab[i] = ft_substr(curr, 0, delim - curr)) == NULL)
			return (free_tab(tab));
		i++;
		curr = delim;
		while (*curr == c)
			curr++;
	}
	if (delim == NULL && *curr != '\0')
		if ((tab[i] = ft_substr(curr, 0, ft_strlen(curr))) == NULL)
			return (free_tab(tab));
		return (tab);
}
