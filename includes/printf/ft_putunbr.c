/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:54:21 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 16:34:16 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n > 9)
		count += ft_putunbr(n / 10);
	digit = n % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}
