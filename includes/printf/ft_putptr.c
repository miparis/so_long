/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:15:24 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 17:57:12 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		count += write(1, "0x", 2);
		count += write(1, base + n, 1);
	}
	else
	{
		if (n / 16 != 0)
		{
			count += ft_putptr(n / 16);
			count += write(1, base + (n % 16), 1);
		}
	}
	return (count);
}
