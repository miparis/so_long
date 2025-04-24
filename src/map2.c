/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:48:18 by miparis           #+#    #+#             */
/*   Updated: 2024/09/03 09:48:20 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	border_control(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (i < (map->width - 1))
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (ft_printf("Error: Map must have borders\n"), 1);
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		len = ft_strlen(map->map[j]) - 1;
		if (map->map[j][0] != '1' || map->map[j][len] != '1')
			return (ft_printf("Error: Map must have borders\n"), 1);
		j++;
	}
	return (0);
}

char	**copy_map(char **original, size_t height, size_t width)
{
	size_t	i;
	size_t	j;
	char	**copy;

	copy = ft_calloc((height + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = malloc(sizeof(char) * (width + 1));
		if (!copy[i])
		{
			j = -1;
			while (j++ < i)
				free(copy[j]);
			return (free(copy), NULL);
		}
		ft_strlcpy(copy[i], original[i], width);
		copy[i][width] = '\0';
		i++;
	}
	return (copy);
}

int	find_player(t_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->start_x = j;
				map->start_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	rec_check(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = '1';
	rec_check(map, x, y -1);
	rec_check(map, x + 1, y);
	rec_check(map, x, y + 1);
	rec_check(map, x - 1, y);
}

int	check_valid_map(t_map *map)
{
	char		**map_copy;
	size_t		i;
	size_t		j;

	find_player(map);
	map_copy = copy_map(map->map, map->height, map->width);
	rec_check(map_copy, map->start_x, map->start_y);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				ft_printf("Error: Unreachable object\n");
				free_split(map_copy);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_split(map_copy);
	return (0);
}
