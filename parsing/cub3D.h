/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:36:10 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/03 14:57:04 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
#define MAX_LINE_LENGTH 256

typedef struct Texture {
  char* path; // Path to the texture image file
  int width;  // Width of the texture in pixels
  int height; // Height of the texture in pixels
  void *img; // pointer to the image
}t_Texture;

typedef struct Position {
  int x;          // X-coordinate (integer)
  int y;          // Y-coordinate (integer)
  float angle; // Direction in degrees (0-360)
}t_Position ;

typedef struct Map {
  char** data;           // 2D array of characters representing the map layout
  int width;            // Width of the map in characters
  int height;           // Height of the map in characters
  t_Position playerPosition; // Player's position and orientation
}t_Map;


 typedef struct Color {
  int red;   // Red component (0-255)
  int green; // Green component (0-255)
  int blue;  // Blue component (0-255)
}t_Color;

  typedef struct GlobaleData {
  t_Texture* north; // Pointer to the North wall texture
  t_Texture* south; // Pointer to the South wall texture
  t_Texture* east; // Pointer to the East wall texture
  t_Texture* west;// Pointer to the West wall texture
  void* mlx; 
  void* win;    // Pointeur vers MLX
  char **file_content;
  t_Color floorColor;   // Floor color
  t_Color ceilingColor; // Ceiling color
  t_Map map;            // The game map with additional player data
  t_Position playerPosition;  // Player's position and orientation
}t_GlobaleData;

void nit_game(t_GlobaleData *game);
void check_map_elements(char *map, t_GlobaleData *gameMap);
char	*fixline(char *line, int maxlen);
int check_name_cub(char *str);
int  is_valid_rgb(int r, int g, int b);
 int get_number_of_rows(char **map);
 int	getsize_largline(char **map);
 int	count_vergules(char *str);
 int set_fl_color_hpl(char *str , int *r, int *g, int *b);
 void set_floor_color(t_GlobaleData *data, char *line);
 void format_F_eror(char *line);
 int set_CE_color_hpl(char *str , int *r, int *g, int *b);
 void format_C_eror(char *line);
 void set_ceiling_color(t_GlobaleData *data, char *line);
 int is_space(int c);
 int in_set(char c);
 int	getsize_largline(char **map);
 int	nbr_of_lines(char *filename);
 void get_file_content(t_GlobaleData *ptr, char *filename);
 void parse(int ac, char **av, t_GlobaleData *ptr);
 void	fill_textures(t_GlobaleData *data, char *ptr);
 void	west_texture(t_GlobaleData *data, char *ptr);
 void	north_texture(t_GlobaleData *data, char *ptr);
 void	east_texture(t_GlobaleData *data, char *ptr);
 void	south_texture(t_GlobaleData *data, char *ptr);
 int check_map_delimited(t_Map* map);

# endif
