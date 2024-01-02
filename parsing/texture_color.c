/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:23:24 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/02 15:49:28 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
#define MAX_LINE_LENGTH 256


void set_texture_hlp(t_GlobaleData* data, t_Texture *texture , char identifier){
   if (identifier == 'N') {
         data->north = texture;
    } else if (identifier == 'S') {
         data->south = texture;
    } else if (identifier == 'W') {
          data->west = texture;
    } else if (identifier == 'E') {
         data->east = texture;
    } else {
          write(0, "Erreur : identifiant de texture invalide !\n", 46);
          exit(1);
    }
}

//Définit la textures
void set_texture(t_GlobaleData* data, char* line, char identifier) {
    t_Texture *texture;
    char* texture_path = line;
    texture = malloc(sizeof(t_Texture));
    texture->path = malloc(ft_strlen(line) + 1);
    while (*texture_path == ' ') 
      texture_path++;
    set_texture_hlp(data, texture, identifier);
    ft_strcpy(texture->path, texture_path);
      texture->img = mlx_xpm_file_to_image(data->mlx, texture->path, &texture->width, &texture->height);
    if (texture->img == NULL) {
         write(0, "Erreur : ouverture de l'image !\n", 51);
         exit(1);
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
      write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 48);
      exit(1);
    }
  }
  return(read_value);
}
void format_F_eror(char *line){
  if (ft_strncmp(line, "F ", 1) != 0) {
    write(STDERR_FILENO, "Erreur : format de ligne invalide (sol) !\n", 48);
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
    write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 48);
    exit(1);
  }
  if (!is_valid_rgb(r, g, b) ) {
    write(STDERR_FILENO, "Erreur : valeur RGB invalide (sol) !\n", 48);
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
      write(STDERR_FILENO, "Erreur : format de couleur invalide (sol) !\n", 48);
      exit(1);
    }
  }
  return(read_value);
}

void format_C_eror(char *line){
  if (ft_strncmp(line, "C", 1) != 0) {
    write(STDERR_FILENO, "Erreur : format de ligne invalide (ceil) !\n", 48);
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
    write(STDERR_FILENO, "Erreur : format de couleur invalide (ceil) !\n", 48);
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
