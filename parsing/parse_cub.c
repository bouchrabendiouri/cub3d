/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:55:15 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/24 16:28:32 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_split_result(char **split_result)
{
	size_t	i;

	i = 0;
	while (split_result[i] != NULL)
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

int	check_name_cub_core(char **spt_rs)
{
	if (spt_rs[0] == NULL || spt_rs[1] == NULL)
	{
		free_split_result(spt_rs);
		return (0);
	}
	if (ft_strncmp(spt_rs[1], "cub", 3) != 0 || ft_strlen(spt_rs[1]) != 3)
	{
		free_split_result(spt_rs);
		return (0);
	}
	if (spt_rs[2] != NULL
		&& (ft_strncmp(spt_rs[2], "cub", 3) != 0 || ft_strlen(spt_rs[2]) != 3))
	{
		free_split_result(spt_rs);
		return (0);
	}
	free_split_result(spt_rs);
	return (1);
}

int	check_name_cub(char *str)
{
	char	**spt_rs;
	int		result;

	if (str != NULL)
	{
		spt_rs = ft_split(str, '.');
		if (spt_rs == NULL)
			return (0);
		result = check_name_cub_core(spt_rs);
		return (result);
	}
	return (0);
}

char	*fixline(char *line, int maxlen)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), (maxlen + 1));
	if (!new)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	while (i < maxlen)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}
