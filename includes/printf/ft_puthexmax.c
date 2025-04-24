/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:40:05 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 16:34:49 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexmax(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789ABCDEF";
	len = 0;
	if (n < 16)
		len += write(1, base + n, 1);
	else
	{
		len += ft_puthexmax(n / 16);
		len += write(1, base + (n % 16), 1);
	}
	return (len);
}
