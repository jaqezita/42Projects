/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:43:16 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/07 20:08:30 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_numbers_flag(char format, va_list args);
int		ft_str_flag(va_list args);
int		ft_numbers_hexa_upper_flag(va_list args);
int		ft_numbers_hexa_low_flag(va_list args);
int		ft_check_specifier_type_flag(char format, char flag, va_list args);
size_t	ft_unsigned_number_flag(va_list args);
int		ft_pointer_flag(va_list args);
int		ft_check_specifier_type(char format, va_list args);
size_t	ft_unsigned_number_flag(va_list args);
int		ft_percent_flag(char c);
int		ft_chr_flag(va_list args);
int		ft_check_specifier_type(char format, va_list args);

#endif
