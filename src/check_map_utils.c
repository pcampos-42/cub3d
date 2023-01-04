/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:30:06 by pcampos-          #+#    #+#             */
/*   Updated: 2023/01/04 15:35:31 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_element(char c, int o)
{
	if (o == 1)
	{
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			return (1);
	}
	else
	{
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
			|| c == '1')
			return (0);
		else
			return (1);
	}
	return (0);
}

int	check_line_limits(char **map, int y, int x)
{
	if (x == 1)
	{
		if (check_element(map[y][0], 1) || check_element(map[y][2], 0) ||
			check_element(map[y + 1][1], 0) || check_element(map[y - 1][1], 0))
			return (1);
	}
	else if (x == (int)ft_strlen(map[y]) - 2)
	{
		if (check_element(map[y][x - 1], 0) || check_element(map[y][x + 1], 1)
		|| check_element(map[y + 1][x], 0) || check_element(map[y - 1][x], 0))
			return (1);
	}
	return (0);
}

int	check_line_midle(char **map, int y, int x)
{
	if (x <= 1 || x >= (int)ft_strlen(map[y]) - 2)
		return (0);
	if (check_element(map[y][x - 1], 0) || check_element(map[y][x + 1], 0) ||
		check_element(map[y + 1][x], 0) || check_element(map[y - 1][x], 0))
		return (1);
	return (0);
}

int	single_player(char **map, t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' ||
				map[j][i] == 'W')
			{
				cub->player.x = i;
				cub->player.y = j;
				cub->player.dir = map[j][i];
				count++;
			}
		}
		i = -1;
	}
	if (count == 1)
		return (0);
	return (1);
}
