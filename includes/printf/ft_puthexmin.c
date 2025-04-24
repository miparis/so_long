/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:33:04 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 16:38:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexmin(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n < 16)
		len += write(1, base + n, 1);
	else
	{
		if (n / 16 != 0)
			len += ft_puthexmin(n / 16);
		len += write(1, base + (n % 16), 1);
	}
	return (len);
}
