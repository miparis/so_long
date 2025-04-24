/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:52:06 by miparis           #+#    #+#             */
/*   Updated: 2024/08/22 11:52:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define TILE_SIZE 72
# define WIDHT 72
# define HEIGHT 72

typedef struct s_map	t_map;
typedef struct s_data	t_data;
typedef struct s_game	t_game;

struct s_data
{
	void		*mlx_ptr;
	void		*w_ptr;
	void		*txts[5];
	t_map		*map;
	t_game		*game;	
};

struct s_map
{
	size_t		width;
	size_t		height;
	char		**map;
	size_t		start_x;
	size_t		start_y;
	int			player;
	int			exit;
	int			collectable;
};

struct s_game
{
	int			counter;
	int			x_player;
	int			y_player;
	int			collectable;
};

/*					TITLE										*/
int		on_key_press(int keycode, t_data *mlx_ptr);
int		on_destroy(t_data *mlx_ptr);
int		charge_images(t_data *data);
void	create_window(t_data data);

/*					FILE & MAP									*/
int		check_file(char *file);
void	read_file(int fd);
int		char_validation(char *file);
int		calculate_dimension(char *file, t_map *map);
void	initialize_struct(t_map *map);
int		map_memory(t_map *map);
int		map_population(char *file, t_map *map);
int		map_control(t_map *map, char *file, int argc, char **argv);
int		objs_control(t_map *map);
int		border_control(t_map *map);
int		check_valid_map(t_map *map);
void	rec_check(char **map, int x, int y);
int		find_player(t_map *map);
char	**copy_map(char **original, size_t height, size_t width);

/*						MLX & GRAPHICS							*/
int		init_window(t_data *mlx_ptr, t_map *map);
int		hooks_loops(t_data *mlx_ptr);
void	put_image(t_data *data, int pos, int x, int y);
void	render(t_data *data);

/*						MOVEMENTS & GAME						*/
void	move_player(int keycode, t_data *data);
void	init_game(t_data *data);
void	move(t_data *data, int x, int y);
void	player_out(t_data *data);
int		end_game(t_data *data);

#endif
