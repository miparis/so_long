/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:58:56 by miparis           #+#    #+#             */
/*   Updated: 2024/09/03 09:58:58 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_dimension(char *file, t_map *map)
{
	char	*line;
	int		fd;
	size_t	line_len;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->height++;
		line_len = ft_strlen(line);
		if (map->width == 0)
			map->width = line_len;
		else
		{
			if (line[line_len - 1] != '\n')
				line_len++;
			if (map->width != line_len)
				return (read_file(fd), close(fd), free(line), 1);
			map->width = line_len;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), 0);
}

void	initialize_struct(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->player = 0;
	map->exit = 0;
	map->collectable = 0;
	map->map = NULL;
}

int	map_memory(t_map *map)
{
	size_t	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (ft_printf("Error: Memory allocation failed\n"), 1);
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->map[i])
		{
			while (map->map[i])
				free(map->map[i]);
			free(map->map);
			ft_printf("Error: Memory allocation failed\n");
			return (6);
		}
		i++;
	}
	map->map[i] = NULL;
	return (0);
}

int	map_population(char *file, t_map *map)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Can't open file\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strlcpy(map->map[i], line, map->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd), 0);
}

int	objs_control(t_map *map)
{
	size_t	i;
	size_t	j;
	char	current;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			current = map->map[i][j];
			if (current == 'P' && ++map->player > 1)
				return (ft_printf("Error: Multiple players found\n"), 1);
			else if (current == 'E' && ++map->exit > 1)
				return (ft_printf("Error: Multiple exits found\n"), 1);
			else if (current == 'C')
				map->collectable++;
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->collectable == 0)
		return (ft_printf("Error: Map with required objects missing\n"), 1);
	return (0);
}
