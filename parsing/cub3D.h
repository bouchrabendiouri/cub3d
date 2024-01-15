/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:01:30 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/15 15:20:41 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
//# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define MAX_LINE_LENGTH 256

typedef struct MapLine
{
	char			*content;
	struct MapLine	*next;
}	t_MapLine;

typedef struct Texture
{
	char	*path;
	int		width;
	int		height;
	void	*img;
}	t_Texture;

typedef struct Position
{
	int		x;
	int		y;
	float	angle;
}	t_Position;

typedef struct Map
{
	char		**data;
	int			width;
	int			height;
}	t_Map;

typedef struct Color
{
	int	red;
	int	green;
	int	blue;
}	t_Color;

typedef struct GlobaleData
{
	t_Texture	*north;
	t_Texture	*south;
	t_Texture	*east;
	t_Texture	*west;
	void		*mlx;
	void		*win;
	char		**file_content;
	t_Color		floorcolor;
	t_Color		ceilcolor;
	t_Map		map;
	t_MapLine	*mapline;
	t_Position	playerposition;
}	t_GlobaleData;

void	check_player_pos(t_GlobaleData *gameMap);
void	remove_extra_spaces(char *str);
int		checkcolor(char *str);
int		check_map_delimited(t_Map map);
char	*fixline(char *line, int maxlen);
void	init_textures(t_GlobaleData *game);
void	ft_map(t_GlobaleData *ptr);
void	check_map_validity(t_Map map);
void	add_to_list(t_GlobaleData *mapList, char *line);
int		check_name_cub(char *str);
int		is_valid_rgb(int r, int g, int b);
int		get_number_of_rows(t_MapLine *map);
int		getsize_largline(t_MapLine *map);
int		cnt_vrgls(char *str);
int		set_fl_color_hpl(char *str, int *r, int *g, int *b);
void	set_floor_color(t_GlobaleData *data, char *line);
void	format_f_eror(char *line);
int		set_ce_color_hpl(char *str, int *r, int *g, int *b);
void	format_c_eror(char *line);
void	set_ceiling_color(t_GlobaleData *data, char *line);
int		is_space(int c);
int		in_set(char c);
int		nbr_of_lines(char *filename);
void	get_file_content(t_GlobaleData *ptr, char *filename);
void	parse(int ac, char **av, t_GlobaleData *ptr);
void	fill_textures(t_GlobaleData *data, char *ptr);
void	west_texture(t_GlobaleData *data, char **ptr);
void	north_texture(t_GlobaleData *data, char **ptr);
void	east_texture(t_GlobaleData *data, char **ptr);
void	south_texture(t_GlobaleData *data, char **ptr);
char	**split_after_space_reduction(char *line);
void	ft_free_split(char **words);
void	check_err(char *ptr);
void	print_error(char *error, int exit_code);
void	check_player_pos_help(t_GlobaleData *gameMap, int x, int y);
char	**ft_split_and_trim(char *line);
int		ft_count_words(const char *str, char c);
char	*ft_concat_split(char **split);
void	ft_free_concat(char *concat);
#endif
