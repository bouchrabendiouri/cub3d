/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:46:58 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/05 15:51:25 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int nbr_of_lines(char *filename)
{
	int i = 0;
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(0, "Error opening file \n", 20);
		exit(EXIT_FAILURE);
	}

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}

	close(fd);
	return i;
}

void get_file_content(t_GlobaleData *ptr, char *filename) {
    int len;
    int fd;

    len = nbr_of_lines(filename);
    ptr->file_content = malloc((len + 1) * sizeof(char*)); // Allouez un tableau de pointeurs de char
    if (!ptr->file_content)
        write(2, "Allocation error\n", 20);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "Error opening file\n", 20);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < len) {
       
            ptr->file_content[i] = get_next_line(fd);
        
        i++;
    }

    ptr->file_content[i] = NULL;

    close(fd);
}
void add_to_List(t_GlobaleData *mapList, char *line) {
    MapLine *newLine = malloc(sizeof(MapLine));
    MapLine *current = mapList->mapline;
    if (newLine == NULL) {
        write(2, "Error: Memory allocation failed\n",33);
        exit(EXIT_FAILURE);
    }

    newLine->content = ft_strdup(line);
    if (newLine->content == NULL) {
        write(2, "Error: Memory allocation failed\n",33);
        exit(EXIT_FAILURE);
    }
    
    newLine->next = NULL;
    if (mapList->mapline == NULL) {
        mapList->mapline = newLine;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newLine;
    }
}

void parse(int ac, char **av, t_GlobaleData *ptr) {
    int i;
    
    i = 0;
    if (ac != 2 || !check_name_cub(av[1])) {
        write(1, "Error invalid argument\n", 26);
        exit(EXIT_FAILURE);
    }
    get_file_content(ptr, av[1]);
    while (ptr->file_content[i]) {
        fill_textures(ptr, ptr->file_content[i]);
            //printf("file_content: %s\n", ptr->file_content[i]);
        if(ptr->file_content[i][0] == ' ' || ptr->file_content[i][0] == '1')
        {
            add_to_List(ptr, ptr->file_content[i]);
        }
        i++;
}
    ft_map(ptr);
}
