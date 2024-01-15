/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <bbendiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:36:31 by bbendiou          #+#    #+#             */
/*   Updated: 2024/01/15 18:12:29 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_GlobaleData	mydata;

	parse(ac, av, &mydata);
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
