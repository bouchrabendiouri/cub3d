/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:46:58 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/02 17:42:10 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
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
	return (i);
}

void get_file_content(t_GlobaleData *ptr, int i, char *filename)
{
    int len;
    int fd;
    
    len = nbr_of_lines(filename);
    ptr->file_content = malloc(len + 1);
    if(!ptr->file_content)
        write(0,"Allocation error", 20);
    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        write(0, "Error opening file \n", 20);
        exit(EXIT_FAILURE);
    }
    ptr->file_content[i] = get_next_line(fd);
    while (i < len && ptr->file_content[i++])
    {
        ptr->file_content[i] = get_next_line(fd);
    }
    ptr->file_content[i] = 0;
    
    close(fd);
}


void parse(int ac, char **av, t_GlobaleData *ptr)
{
    int i;
    
    i = 0;
    if(ac != 2 || !check_name_cub(av[1]))
    {
        write(1, "Error invalid argument\n", 26);
		exit(0);
    }
    get_file_content(ptr, i, av[1]);
    while (ptr->file_content[i++])
    {
        get_file_content(ptr, i, av[1]);
        fill_textures(ptr,ptr->file_content[i]);
        printf("hiiiiiii\n");
    }
    
}
