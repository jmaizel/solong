/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:26:27 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/24 15:12:16 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_check(const char format, va_list args);
int		ft_print_char(va_list args);
int		ft_print_int(va_list args);
int		ft_print_str(va_list args);
int		ft_print_unsigned(va_list args);
int		ft_print_lowercase(va_list args);
int		ft_print_highercase(va_list args);
int		ft_print_pointeur(va_list args);

#endif