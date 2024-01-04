/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:01:29 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/04 17:24:15 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int check_map_delimited(t_Map* map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == '0' && (i == 0 || j == 0 ||
			i == map->height - 1 || j == map->width - 1 ||
			map->data[i - 1][j] == ' ' || map->data[i + 1][j] == ' ' ||
			map->data[i][j - 1] == ' ' || map->data[i][j + 1] == ' '))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void check_player_pos(t_Map *gameMap)
{
    int x ;
    int y;
	int found = 0;

    y = 0;
    while(y < gameMap->height)
    {
        x = 0;
        while(x < gameMap->width)
        {
            if (gameMap->data[x][y] == 'N' || gameMap->data[x][y] == 'S' || gameMap->data[x][y] == 'E' || gameMap->data[x][y] == 'W')
            {
				found = 1;
                gameMap->playerPosition.x = x;
                gameMap->playerPosition.y = y;
                if (gameMap->data[x][y] == 'N')
                    gameMap->playerPosition.angle = 0;
                else if (gameMap->data[x][y] == 'S')
                    gameMap->playerPosition.angle = 180;
                else if (gameMap->data[x][y] == 'E')
                    gameMap->playerPosition.angle = 90;
                else if (gameMap->data[x][y] == 'W')
                    gameMap->playerPosition.angle = 270;
                gameMap->data[x][y] = '0';
                return;
            }
            x++;
        }
        y++;
    }
	if (found == 0)
    	write(2, "LE JOUEUR N'EST PAS TROUVE DANS LA CARTE !\n", 47);
}


char	*fixline(char *line, int maxlen)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), (maxlen + 1));
	if (!new)
		return (NULL);
	while (line[i])
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

void ft_map(char *str_map) {
	t_Map *map = malloc(sizeof(t_Map));
    int i;

    i = 0;
	printf("DEBUG\n");
    map->data = (char **)malloc(sizeof(char *) * (map->width+ 1));

    if (!map->data)
        write(2, "ERROR ALLOCATION\n", 16);

    while (str_map[i]) {
		
       	map->data[i] = fixline(str_map, map->width);
        i++;
    }

    if (check_map_delimited(map)) {
        check_player_pos(map);
    } else {
        write(2, "MAP DELIMITATION ERROR\n", 23);
    }
}