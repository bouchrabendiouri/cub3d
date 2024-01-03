/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:15:21 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/03 16:46:42 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

// void print_error(char *msg, int code)
// {
//     //
// }

void nit_game(t_GlobaleData *game) {
    game->mlx = mlx_init();
    game->file_content = NULL;
}

/*int main (int ac, char **av)
{
      t_GlobaleData myData;
    nit_game(&myData);
    myData.north->img = "textures/texture.xpm";
    if (!myData.mlx)
        return EXIT_FAILURE;

    if (!myData.win)
        return EXIT_FAILURE;
    myData.win = mlx_new_window(myData.mlx, 800, 600, "Simple Window");
    mlx_put_image_to_window(myData.mlx, myData.win, myData.north->img, 300, 200);
    mlx_loop(myData.mlx);
    parse(ac, av,&myData);
    free_texture(myData.north);

    return EXIT_SUCCESS;
    return 0;
}*/
void free_texture(t_Texture *texture)
{
    t_GlobaleData data;
    if (texture)
    {
        free(texture->path);
        mlx_destroy_image(data.mlx, texture->img);
        free(texture);
    }
}

int main(int ac, char **av)
{
    t_GlobaleData myData;

    parse(ac, av, &myData);

    return EXIT_SUCCESS;
}