/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:07:13 by aconchit          #+#    #+#             */
/*   Updated: 2021/10/21 17:22:53 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_pars_param(const char *format)
{
	if (!ft_strncmp(format, "%c", 2))
		return (1);
	if (!ft_strncmp(format, "%s", 2))
		return (2);
	if (!ft_strncmp(format, "%p", 2))
	{
		write (1, "0x", 2);
		return (3);
	}
	if (!ft_strncmp(format, "%d", 2))
		return (4);
	if (!ft_strncmp(format, "%i", 2))
		return (5);
	if (!ft_strncmp(format, "%u", 2))
		return (6);
	if (!ft_strncmp(format, "%x", 2))
		return (7);
	if (!ft_strncmp(format, "%X", 2))
		return (8);
	if (!ft_strncmp(format, "%%", 2))
		return (9);
	return (0);
}

int	ft_ctmemhex(unsigned long long int hex)
{
	int	index;

	index = 0;
	while (hex >= 16)
	{
		hex /= 16;
		index++;
	}
	return (index);
}

char	*ft_hex(unsigned long long int hex, int type)
{
	char	*res;
	int		size;
	char	*base;

	size = ft_ctmemhex(hex);
	res = (char *)malloc(sizeof(char) * (size + 2));
	if (!res)
		return (NULL);
	res[size + 1] = '\0';
	if (type == 3 || type == 7)
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	while (size >= 0)
	{
		res[size] = base[hex % 16];
		size--;
		hex /= 16;
	}
	free(base);
	return (res);
}

int	ft_clean(char *str)
{
	int	size;

	size = ft_strlen(str);
	free(str);
	return (size);
}

char	*ft_create_param(va_list ap, int type)
{
	char	*param;

	param = NULL;
	if (!type)
		return (NULL);
	if (type == 2)
		param = ft_strdup(va_arg(ap, char *));
	if (type == 3)
		param = ft_hex(va_arg(ap, unsigned long long int), type);
	if (type == 7 || type == 8)
		param = ft_hex(va_arg(ap, unsigned int), type);
	if (type == 4 || type == 5)
		param = ft_itoa(va_arg(ap, int));
	if (type == 6)
		param = ft_itoa_ultra(va_arg(ap, unsigned int));
	if (type == 9)
		param = ft_strdup("%");
	return (param);
}
