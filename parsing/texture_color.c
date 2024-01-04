/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:23:24 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/04 15:17:15 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
#define MAX_LINE_LENGTH 256


void	north_texture(t_GlobaleData *data, char *ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (ptr[2] != ' ')
  {
		write(2,"THE PATH IS NOT VALID (nourth)!\n",40);
    exit(1);
  }
	//if (data->nourth)
		//write(0,"THE TEXTURE DUPLICATE !\n",40);
	while (ptr[i] != '\n')
		i++;
	ptr++;
  data->north = malloc(sizeof(t_Texture));
	data->north->path = malloc((i + 1) * sizeof(char));

	i = 0;
	while (*ptr != '\n')
	{
    data->north->path[i++] = *ptr;
		(*ptr)++;
	}
	data->north->path[i] = '\0';
	//int fd = open(data->north->path, O_RDONLY);
	//if (fd < 0)
		//write(0,"Error: open image (north)\n", 40);
}

void	south_texture(t_GlobaleData *data, char *ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (ptr[2] != ' '){
    
		write(2,"THE PATH IS NOT VALID (south)!\n",34);
    exit(1);
  }
	//if (data->south)
		//write(0,"THE TEXTURE DUPLICATE !\n",40);
	while (ptr[i] != '\n')
		i++;
	ptr++;
  data->south = malloc(sizeof(t_Texture));
	data->south->path = malloc((i + 1) * sizeof(char));

	i = 0;
	while (*ptr != '\n')
	{
    data->south->path[i++] = *ptr;
		(*ptr)++;
  }
	data->south->path[i] = '\0';
	//int fd = open(data->south->path, O_RDONLY);
	//if (fd < 0)
		//write(0,"Error: open image (south)\n", 40);
    
}

void	east_texture(t_GlobaleData *data, char *ptr)
{
int	i;

	i = 0;
	(*ptr) += 2;
	if (ptr[2] != ' ')
  {
		write(2,"THE PATH IS NOT VALID (east) !\n",40);
    exit(1);
  }
	//if (data->south)
		//write(0,"THE TEXTURE DUPLICATE !\n",40);
	while (ptr[i] != '\n')
		i++;
	ptr++;
  data->east = malloc(sizeof(t_Texture));
	data->east->path = malloc((i + 1) * sizeof(char));

	i = 0;
	while (*ptr != '\n')
	{
    data->east->path[i++] = *ptr;
		(*ptr)++;
	}
	data->east->path[i] = '\0';
	//int fd = open(data->east->path, O_RDONLY);
	//if (fd < 0)
		//write(0,"Error: open image (east)\n", 40);
}

void	west_texture(t_GlobaleData *data, char *ptr)
{
	int	i;

	i = 0;
	(*ptr) += 2;
	if (ptr[2] != ' ')
  {
		write(2,"THE PATH IS NOT VALID (west)!\n",40);
    exit(1);
  }
	//if (data->south)
		//write(0,"THE TEXTURE DUPLICATE !\n",40);
	while (ptr[i] != '\n')
		i++;
	ptr++;
  data->west = malloc(sizeof(t_Texture));
	data->west->path = malloc((i + 1) * sizeof(char));

	i = 0;
	while (*ptr != '\n')
	{
    data->west->path[i++] = *ptr;
		(*ptr)++;
	}
	data->west->path[i] = '\0';
	//int fd = open(data->south->path, O_RDONLY);
	//if (fd < 0)
		//write(0,"Error: open image (west)\n", 40);
}

void fill_textures(t_GlobaleData *data, char *ptr)
{
    while (*ptr)
    {
        if (ptr[0] == 'N' && ptr[1] == 'O')
        {
            north_texture(data,ptr);
        }
        else if (ptr[0] == 'S' && ptr[1] == 'O')
        {
            south_texture(data, ptr);
        }
        else if (ptr[0] == 'W' && ptr[1] == 'E')
        {
            west_texture(data, ptr);
        }
        else if (ptr[0] == 'E' && ptr[1] == 'A')
        {
            east_texture(data, ptr);
        }
        else if (ptr[0] == 'F' && ptr[1] && ptr[1] == ' ')
        {
            set_floor_color(data, ptr);
        }
        else if (ptr[0] == 'C' && ptr[1] && ptr[1] == ' ')
        {
            set_ceiling_color(data, ptr);
        }
        else if ((*ptr == ' ' || *ptr == '1'))
		    {
			      ft_map(ptr);
			      break ;
		    }
        /*else if((ptr[0] != 'N' && ptr[1] != 'O') || (ptr[0] != 'S' && ptr[1] != 'O') || 
        (ptr[0] != 'W' && ptr[1] != 'E') || (ptr[0] != 'E' && ptr[1] != 'A') || 
        (ptr[0] != 'C' && ptr[1] != ' ') || (ptr[0] != 'F' && ptr[1] != ' ')
        || (ptr[0] != 0))
        {
            write(2, "error in file\n", 15);
            break;
        }*/
        ptr++;
    }
}
int	count_vergules(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == ',')
			count++;
	return (count);
}

int set_fl_color_hpl(char *str , int *r, int *g, int *b)
{
  int read_value;
  read_value = 0;
   while (*str && read_value < 3) {
    if (ft_isdigit(*str) && !in_set(*str)) {
            if (read_value == 0)
                *r = atoi(str);
            else if (read_value == 1)
                *g = atoi(str);
            else if (read_value == 2)
                *b = atoi(str);
            read_value++;
            while (*str && (ft_isdigit(*str)))
                str++;
    } else if ((*str == ',' && !in_set(*str)) || is_space(*str)) 
            str++;
     else 
    {
      write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 60);
      exit(1);
    }
  }
  return(read_value);
}
void format_F_eror(char *line){
  if (ft_strncmp(line, "F ", 1) != 0) {
    write(STDERR_FILENO, "Erreur : format de ligne invalide (sol) !\n", 60);
    exit(1);
  }
}

void set_floor_color(t_GlobaleData *data, char *line) {
  char *rgb_str;
  int values_read;
  int r ;
  int g;
  int b;
  r = 0; 
  g = 0; 
  b = 0;
  values_read = 0;
 format_F_eror(line);
  rgb_str = line + 2;
  while ((*rgb_str && is_space(*rgb_str)))
      rgb_str++;
  values_read = set_fl_color_hpl(rgb_str,&r , &g ,&b);
  if (values_read != 3 || count_vergules(rgb_str) !=2) {
    write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 60);
    exit(1);
  }
  if (!is_valid_rgb(r, g, b) ) {
    write(STDERR_FILENO, "Erreur : valeur RGB invalide (sol) !\n", 60);
    exit(1);
  }
  data->floorColor.red = r;
  data->floorColor.green = g;
  data->floorColor.blue = b;
}

int set_CE_color_hpl(char *str , int *r, int *g, int *b)
{
  int read_value;
  read_value = 0;
   while (*str && read_value < 3) {
    if (ft_isdigit(*str) && !in_set(*str)) {
            if (read_value == 0)
                *r = atoi(str);
            else if (read_value == 1)
                *g = atoi(str);
            else if (read_value == 2)
                *b = atoi(str);
            read_value++;
            while (*str && (ft_isdigit(*str)))
                str++;
    } else if ((*str == ',' && !in_set(*str)) || is_space(*str)) 
            str++;
     else 
    {
      write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 60);
      exit(1);
    }
  }
  return(read_value);
}

void format_C_eror(char *line){
  if (ft_strncmp(line, "C", 1) != 0) {
    write(STDERR_FILENO, "Erreur : format de ligne invalide (ceil) !\n", 60);
    exit(1);
  }
}

void set_ceiling_color(t_GlobaleData *data, char *line) {
  char *rgb_str;
  int values_read;
  int r ;
  int g;
  int b;
  r = 0; 
  g = 0; 
  b = 0;
  values_read = 0;
 format_C_eror(line);
  rgb_str = line + 2;
  while ((*rgb_str && is_space(*rgb_str)))
      rgb_str++;
  values_read = set_CE_color_hpl(rgb_str,&r , &g ,&b);
  if (values_read != 3) {
    write(STDERR_FILENO, "Erreur : format de couleur invalide (ceil) !\n", 60);
    exit(1);
  }
  if (!is_valid_rgb(r, g, b) ) {
    write(STDERR_FILENO, "Erreur : valeur RGB invalide (ceil) !\n", 48);
    exit(1);
  }
  data->ceilingColor.red = r;
  data->ceilingColor.green = g;
  data->ceilingColor.blue = b;
}
