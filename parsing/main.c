/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:15:21 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/02 17:49:10 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void free_texture(t_Texture* texture) {
    free(texture->path);
    free(texture);
}
int main (int ac, char **av)
{
      t_GlobaleData myData;
    
    myData.mlx = mlx_init();
    if (!myData.mlx)
        return EXIT_FAILURE;

    if (!myData.win)
        return EXIT_FAILURE;
    myData.win = mlx_new_window(myData.mlx, 800, 600, "Simple Window");
    parse(ac, av, &myData);
    mlx_put_image_to_window(myData.mlx, myData.win, myData.north->img, 300, 200);
    mlx_loop(myData.mlx);
    
    free_texture(myData.north);

    return EXIT_SUCCESS;
    return 0;
}