/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_col_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:02 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/15 17:05:25 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**split_after_space_reduction(char *line)
{
	remove_extra_spaces(line);
	return (ft_split(line, ' '));
}

void	ft_free_split(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return ;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	printf("DEBUG\n");
}

int	cnt_vrgls(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == ',')
			count++;
	}
	return (count);
}

int	checkcolor(char *str)
{
	while (*str != '\0' && *str != '\n')
	{
		if (!ft_isdigit(*str) && *str != ',')
			return (0);
		str++;
	}
	return (1);
}
