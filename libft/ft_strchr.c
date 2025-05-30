/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:31:46 by bbendiou          #+#    #+#             */
/*   Updated: 2022/11/13 17:48:10 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = c;
	while (*s != '\0')
	{
		if (*s == c1)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (NULL);
}
