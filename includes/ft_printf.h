/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:50:22 by aconchit          #+#    #+#             */
/*   Updated: 2021/10/21 17:27:48 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_pars_param(const char *format);
int		ft_ctmemhex(unsigned long long int hex);
char	*ft_hex(unsigned long long int hex, int type);
int		ft_clean(char *str);
char	*ft_create_param(va_list ap, int type);

#endif