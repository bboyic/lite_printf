/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ultra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:01:55 by aconchit          #+#    #+#             */
/*   Updated: 2021/10/21 17:26:44 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mem_itoa_ultra(unsigned int n)
{
	char	*str;
	int		size;

	size = 0;
	while ((unsigned int)n >= 10)
	{
		size++;
		n /= 10;
	}
	str = (char *)malloc(sizeof(char) * (size) + 2);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa_ultra(unsigned int nb)
{
	char			*str;
	int				index;

	index = 0;
	str = ft_mem_itoa_ultra(nb);
	if (!str)
		return (NULL);
	while (nb >= 10)
	{
		str[index++] = (nb % 10) + '0';
		nb /= 10;
	}
	str[index++] = (nb % 10) + '0';
	str[index] = '\0';
	str = ft_strrev(str);
	return (str);
}
