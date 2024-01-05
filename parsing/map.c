/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:01:29 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/05 17:47:25 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void  check_map_validity(t_Map map)
{
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.data[i][j] == 'N' || map.data[i][j] == 'S' ||
				 map.data[i][j] == 'E' || map.data[i][j] == 'W')
				n +=1;
			else if(map.data[i][j] == '\n' && map.data[i][j + 1] == '\n')
				write(2, "Error : tow newlines \n", 23);
			else if(map.data[i][j] != '0' &&map.data[i][j] != '1' && 
					map.data[i][j] != ' ' && map.data[i][j] != '\n' )
					write(2,"Error : the map is not vlide \n", 31);
			j++;
		}
		i++;
	}
	if(n != 1)
		write(2, "Error : there is no (N S W E)\n", 31);
}

int check_map_delimited(t_Map map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.data[i][j] == '0' && (i == 0 || j == 0 ||
			i == map.height - 1 || j == map.width - 1 ||
			map.data[i - 1][j] == ' ' || map.data[i + 1][j] == ' ' ||
			map.data[i][j - 1] == ' ' || map.data[i][j + 1] == ' ')){
			printf("Map Delimitation Error at (%d, %d) | [%s]\n", i, j, map.data[i]);
				return 0;
			}
			j++;
		}
		i++;
	}
	return 1;
}

void check_player_pos(t_GlobaleData *gameMap)
{
    int x;
    int y;
   	int found = 0;

    y = 0;
    while (y < gameMap->map.height)
    {
        x = 0;
        while (x < gameMap->map.width)
        {
            if (gameMap->map.data[y][x] == 'N' || gameMap->map.data[y][x] == 'S' || gameMap->map.data[y][x] == 'E' || gameMap->map.data[y][x] == 'W')
            {
                found = 0;
                gameMap->playerPosition.x = x;
                gameMap->playerPosition.y = y;
                if (gameMap->map.data[y][x] == 'N')
                    gameMap->playerPosition.angle = 0;
                else if (gameMap->map.data[y][x] == 'S')
                    gameMap->playerPosition.angle = 180;
                else if (gameMap->map.data[y][x] == 'E')
                    gameMap->playerPosition.angle = 90;
                else if (gameMap->map.data[y][x] == 'W')
                    gameMap->playerPosition.angle = 270;
                gameMap->map.data[y][x] = '0';
				//printf("Player found at (%d, %d) with angle %f\n", gameMap->playerPosition.x, gameMap->playerPosition.y, gameMap->playerPosition.angle);
                return;
            }
            x++;
        }
        y++;
    }
    if (found == 1)
        write(2, "LE JOUEUR N'EST PAS TROUVE DANS LA CARTE !\n", 44);
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

void ft_map(t_GlobaleData *ptr) {
    int i;
	MapLine* current;
	
    i = 0;
	current = ptr->mapline;
	ptr->map.width = getsize_largline(ptr->mapline);
	ptr->map.height = get_number_of_rows(ptr->mapline);
	//printf("[%d | %d]\n", ptr->map.height, ptr->map.width);
    ptr->map.data = (char **)malloc(sizeof(char *) * (ptr->map.height + 1));
	if (ptr->map.data == NULL) {
    write(2, "Error: Memory allocation failed for map data\n",46);
    exit(EXIT_FAILURE);
	}
	while(i < ptr->map.height)
	{
		ptr->map.data[i] = fixline(current->content, ptr->map.width);
		//printf("current_content %s\n", current->content);
		i++;
			current = current->next;
		if(current == NULL)
			break;
	}
	check_map_validity(ptr->map);
	ptr->map.data[i] = NULL;
	//printf("fonction = %d\n", check_map_delimited(ptr->map));
    if (check_map_delimited(ptr->map) == 1) {
        check_player_pos(ptr);
    } 
	else if (check_map_delimited(ptr->map) == 0)
        write(2, "MAP DELIMITATION ERROR\n", 24);
}