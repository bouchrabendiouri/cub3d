/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:46:30 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/04 15:24:31 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_space(int c) {
    if(c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return(1);
    return(0);
}

int in_set(char c){
  if(c == '.' || c == '-' || c == ';' || c == ':' 
              || c == '\'' || c == '\"' || c == '`' )
  {
    return 1;
  }
  return 0;
}

int  is_valid_rgb(int r, int g, int b) {
  if(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
    return(1);
  return(0);
}
 int get_number_of_rows(char *map) {
    int count = 0;
    while (map[count]) {
        count++;
    }
    return count;
}

int	getsize_largline(char *map)
{
	int	i;
	size_t	max;

	i = -1;
	max = ft_strlen(&map[0]);
	while (map[++i])
		if (ft_strlen(&map[i]) > max)
			max = ft_strlen(&map[i]);
	return (max);
}

int	getsizemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}