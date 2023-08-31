/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:16 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/30 22:32:04 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_number(const char *format, va_list args);
char			ft_str(const char *format, va_list args);
char			ft_chr(const char *format, va_list args);
unsigned int	ft_number_positive(const char *format, va_list args);
char			ft_putstr(char *s);
size_t			ft_unsigned_hexa_low(const char *format, va_list args);
size_t			ft_unsigned_hexa_upper(const char *format, va_list args);

#endif
