/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:46:30 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/05 10:54:30 by bbendiou         ###   ########.fr       */
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
 int get_number_of_rows(MapLine *map) {
    int count = 0;
    // printf("%s\n", map->content);
    while (map) {
      // printf("Debuuuug\n");
      map = map->next;
        count++;
    }
    return count;
}

int	getsize_largline(MapLine *map)
{
	size_t	max;
  
   if (map == NULL)
        return 0;
	max = ft_strlen(map->content);
	while (map->next ){
		if (ft_strlen(map->next->content) > max)
			max = ft_strlen(map->next->content);
    map = map->next;
  }
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