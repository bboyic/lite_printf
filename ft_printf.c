/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:52:52 by aconchit          #+#    #+#             */
/*   Updated: 2021/10/21 17:28:14 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_param(va_list ap, const char *format)
{
	int		type;
	char	*param;

	type = ft_pars_param(format);
	param = ft_create_param(ap, type);
	if (type == 1)
		ft_putchar_fd(va_arg(ap, int), 1);
	if (param)
	{
		write (1, param, ft_strlen(param));
		if (type != 3)
			return (ft_clean(param));
		else
			return (ft_clean(param) + 2);
	}
	else if (type != 1)
	{
		write (1, "(null)", 6);
		return (6);
	}
	return (type);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;

	index = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			index += ft_print_param(ap, format);
			format += 2;
		}
		else
		{
			write (1, format, 1);
			index++;
			format++;
		}
	}
	va_end(ap);
	return (index);
}
