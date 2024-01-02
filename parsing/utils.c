/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:46:30 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/02 17:45:24 by bbendiou         ###   ########.fr       */
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
 int get_number_of_rows(char **map) {
    int count = 0;
    while (map[count] != NULL) {
        count++;
    }
    return count;
}

int	getsize_largline(char **map)
{
	int	i;
	size_t	max;

	i = -1;
	max = ft_strlen(map[0]);
	while (map[++i])
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
	return (max);
}


void	north_texture(t_GlobaleData *data, char **ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (**ptr != ' ')
		write(0,"THE PATH IS NOT VALID !\n",40);
	//if (data->north)
		//write(0,"THE TEXTURE DUPLICATE !\n",40);
	(*ptr)++;
	while (ptr[0][i] != '\n')
		i++;
	data->north = malloc((i + 1) * sizeof(char));
	i = 0;
	while (**ptr != '\n')
	{
    data->north->path[i++] = **ptr;
		(*ptr)++;
	}
	data->north->path[i] = '\0';
	i = open(data->north->path, O_RDONLY);
	if (i < 0)
		write(0,"Error: open image (north)\n", 40);
}

void	south_texture(t_GlobaleData *data, char **ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (**ptr != ' ')
		write(0,"THE PATH IS NOT VALID !\n",40);
	if (data->south)
		write(0,"THE TEXTURE DUPLICATE !\n",40);
	(*ptr)++;
	while (ptr[0][i] != '\n')
		i++;
	data->south = malloc((i + 1) * sizeof(char));
	i = 0;
	while (**ptr != '\n')
	{
    data->south->path[i++] = **ptr;
		(*ptr)++;
	}
	data->south->path[i] = '\0';
	i = open(data->south->path, O_RDONLY);
	if (i < 0)
		write(0,"Error: open image (north)\n", 40);
}

void	east_texture(t_GlobaleData *data, char **ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (**ptr != ' ')
		write(0,"THE PATH IS NOT VALID !\n",40);
	if (data->east)
		write(0,"THE TEXTURE DUPLICATE !\n",40);
	(*ptr)++;
	while (ptr[0][i] != '\n')
		i++;
	data->east = malloc((i + 1) * sizeof(char));
	i = 0;
	while (**ptr != '\n')
	{
    data->east->path[i++] = **ptr;
		(*ptr)++;
	}
	data->east->path[i] = '\0';
	i = open(data->east->path, O_RDONLY);
	if (i < 0)
		write(0,"Error: open image (north)\n", 40);
}

void	west_texture(t_GlobaleData *data, char **ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (**ptr != ' ')
		write(0,"THE PATH IS NOT VALID !\n",40);
	if (data->west)
		write(0,"THE TEXTURE DUPLICATE !\n",40);
	(*ptr)++;
	while (ptr[0][i] != '\n')
		i++;
	data->west = malloc((i + 1) * sizeof(char));
	i = 0;
	while (**ptr != '\n')
	{
    data->west->path[i++] = **ptr;
		(*ptr)++;
	}
	data->west->path[i] = '\0';
	i = open(data->west->path, O_RDONLY);
	if (i < 0)
		write(0,"Error: open image (north)\n", 40);
}

void	fill_textures(t_GlobaleData *data, char *ptr)
{
	while (*ptr)
	{
		if (*ptr == 'N' && ptr[1] == 'O')
			north_texture(data, &ptr);
		else if (*ptr == 'S' && ptr[1] == 'O')
			south_texture(data, &ptr);
		else if (*ptr == 'W' && ptr[1] == 'E')
			west_texture(data, &ptr);
		else if (*ptr == 'E' && ptr[1] == 'A')
			east_texture(data, &ptr);
		else if (*ptr == 'F' && ptr[1] && ptr[1] == ' ')
			set_floor_color(data, ptr);
		else if (*ptr == 'C' && ptr[1] && ptr[1] == ' ')
			set_ceiling_color(data, ptr);
}
}