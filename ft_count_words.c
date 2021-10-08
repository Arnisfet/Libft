/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:16:42 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:16:52 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция счета слов*/

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int		len;
	size_t	j;

	j = 0;
	len = 0;
	while (s[len])
	{
		while (s[len] == c && s[len] != '\0')
			len++;
		if (s[len] != c && s[len])
			j++;
		while (s[len] != c && s[len])
			len++;
	}
	return (j);
}
