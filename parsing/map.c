/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:01:29 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/02 14:17:32 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void check_if_ValidMap(char *map, t_GlobaleData *gameMap)
{
    int i;
    int n;

    n = 0;
    i = -1;
    while (map[++i])
    {
        if(map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
        {
            n += 1;
            gameMap->playerPosition.x = i % gameMap->map.width;
            gameMap->playerPosition.y = i / gameMap->map.width;
            if (map[i] == 'N')
                gameMap->playerPosition.angle = 0;
            else if (map[i] == 'S')
                gameMap->playerPosition.angle = 180;
            else if (map[i] == 'E') 
                gameMap->playerPosition.angle = 90;
            else if (map[i] == 'W')
                gameMap->playerPosition.angle = 270;
        }
        else if (map[i] == '\n' && map[i + 1] == '\n')
            write(0,"DEUX SAUTS DE LIGNE CONSECUTIFS !\n",40);
        else if (map[i] != '0' && map[i] != '1' && map[i] != ' ' && map[i] != '\n')
            write(0,"IL Y A AUTRE CHOSE QUE (1 0 N S E W) DANS LA CARTE !\n", 55);
    }
    if (n != 1)
        write(0,"LA CARTE N'EST PAS VALIDE (N S E W) !\n", 40); 
}

int	horizontal_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
				{
					write(1, "map n'est pas valide (h)\n", 23);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	verticale_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
				{
					write(1, "map n'est pas valide (v)\n", 23);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
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

void parse_map_full()
{}