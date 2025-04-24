/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:48:20 by miparis           #+#    #+#             */
/*   Updated: 2024/08/28 10:48:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_control(t_map *map, char *file, int argc, char **argv)
{
	initialize_struct(map);
	if (argc != 2 || check_file(argv[1]))
	{
		ft_printf("Error: Not usable map\n");
		return (1);
	}
	if (char_validation(file))
		return (1);
	if (calculate_dimension(file, map))
		return (ft_printf("Error: Map with wrong size\n"), 1);
	if (map_memory(map))
		return (1);
	if (map_population(file, map))
		return (1);
	if (objs_control(map))
		return (1);
	if (border_control(map))
		return (1);
	if (check_valid_map(map))
		return (1);
	return (0);
}

int	check_file(char *file)
{
	const char	*ext;
	size_t		file_len;
	size_t		ext_len;
	char		*file_ext;
	int			fd;

	ext = ".ber";
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (file_len < ext_len)
		return (1);
	file_ext = ft_substr(file, file_len - ext_len, ext_len);
	if (ft_strcmp(file_ext, ext) != 0)
	{
		free(file_ext);
		return (1);
	}
	free(file_ext);
	return (0);
}

int	char_validation(char *file)
{
	int		fd;
	char	*line;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error opening file\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] != '1' && line[j] != '0' && line[j] != 'P' \
					&& line[j] != 'E' && line[j] != 'C' && line[j] != '\n')
			{
				ft_printf("Error: Invalid character in map\n");
				return (read_file(fd), free(line), close(fd), 1);
			}
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

void	read_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
