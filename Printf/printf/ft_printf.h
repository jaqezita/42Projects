/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:16 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/04 18:57:56 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_numbers(va_list args);
int				ft_str(va_list args);
int				ft_chr(va_list args);
unsigned int	ft_number_positive(va_list args);
size_t			ft_numbers_hexa_low(va_list args);
size_t			ft_numbers_hexa_upper(va_list args);
int				ft_check_specifier_type(char format, va_list args);
size_t			ft_unsigned_number(va_list args);
int				ft_pointer(va_list args);
int				ft_putnbr(int n);
char			ft_percent(char c);
size_t			ft_putnbr_hexa_low(size_t n);
int				ft_printf(const char *format, ...);

#endif
