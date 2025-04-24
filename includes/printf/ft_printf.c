/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:52:47 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 16:11:34 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (flag == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (ft_puthexmin(va_arg(args, unsigned long long int)));
	if (flag == 'X')
		return (ft_puthexmax(va_arg(args, unsigned long long int)));
	if (flag == 'p')
		return (ft_putptr(va_arg(args, unsigned long long int)));
	if (flag == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		counts;

	va_start(args, s);
	i = 0;
	counts = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			counts += check_format(s[i], args);
		}
		else
			counts += ft_putchar(s[i]);
		if (s[i])
			i++;
	}
	va_end(args);
	return (counts);
}
