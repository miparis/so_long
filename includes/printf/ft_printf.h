/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:52:27 by miparis           #+#    #+#             */
/*   Updated: 2023/10/30 16:37:50 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(char const *s, ...);

/*                  PRINTF FUNCTIONS                                         */
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int c);
int	ft_putunbr(unsigned int n);
int	ft_puthexmin(unsigned int n);
int	ft_puthexmax(unsigned int n);
int	ft_putptr(unsigned long long int n);

#endif
