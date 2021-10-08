/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:51:35 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:51:37 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Тот же стрдап с выделением и копированием но не больше н символов*/

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_mystrncpy(str, s, n);
	return (str);
}
