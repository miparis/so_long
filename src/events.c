/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:28:00 by miparis           #+#    #+#             */
/*   Updated: 2024/09/03 11:28:02 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hooks_loops(t_data *mlx_ptr)
{
	mlx_key_hook(mlx_ptr->w_ptr, on_key_press, mlx_ptr);
	mlx_hook(mlx_ptr->w_ptr, KeyRelease, KeyReleaseMask, \
			&on_key_press, mlx_ptr);
	mlx_hook(mlx_ptr->w_ptr, DestroyNotify, StructureNotifyMask, \
			&end_game, mlx_ptr);
	return (0);
}

int	on_key_press(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		end_game(data);
		exit(5);
	}
	render(data);
	move_player(keysym, data);
	return (0);
}
