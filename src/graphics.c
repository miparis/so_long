/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:10:10 by miparis           #+#    #+#             */
/*   Updated: 2024/08/27 10:10:12 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_data *mlx_ptr, t_map *map)
{
	size_t	w;
	size_t	h;

	w = (map->width - 1) * TILE_SIZE;
	h = map->height * TILE_SIZE;
	mlx_ptr->w_ptr = mlx_new_window(mlx_ptr->mlx_ptr, w, h, "so_long");
	if (!mlx_ptr->w_ptr)
	{
		ft_printf("Window creation failed\n");
		return (free(mlx_ptr->mlx_ptr), 1);
	}
	return (0);
}

void	render(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == '0')
				put_image(data, 0, x, y);
			if (data->map->map[y][x] == '1')
				put_image(data, 1, x, y);
			if (data->map->map[y][x] == 'P')
				put_image(data, 4, x, y);
			if (data->map->map[y][x] == 'C')
				put_image(data, 2, x, y);
			if (data->map->map[y][x] == 'E')
				put_image(data, 3, x, y);
			x++;
		}
		y++;
	}
}

void	put_image(t_data *data, int pos, int x, int y)
{
	int		a;
	int		b;

	a = x * TILE_SIZE;
	b = y * TILE_SIZE;
	mlx_put_image_to_window(data->mlx_ptr, data->w_ptr, data->txts[pos], a, b);
}

int	charge_images(t_data *data)
{
	int		i;
	int		h;
	int		w;

	i = -1;
	data->txts[0] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/f.xpm", \
					&w, &h);
	data->txts[1] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/w.xpm", \
					&w, &h);
	data->txts[2] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/c.xpm", \
					&w, &h);
	data->txts[3] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/e.xpm", \
					&w, &h);
	data->txts[4] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/p.xpm", \
					&w, &h);
	while (++i < 5)
	{
		if (!data->txts[i])
		{
			ft_printf("Failed to load image %d\n", i);
			end_game(data);
			return (1);
		}
	}
	return (0);
}
