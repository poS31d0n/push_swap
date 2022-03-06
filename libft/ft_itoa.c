/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:49:02 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 12:55:54 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	neg(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static int	ft_putnbr_itoa(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	itoachar(char *str, int n, int len)
{
	len -= 1;
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_putnbr_itoa(n);
	negative = 0;
	neg(&n, &negative);
	len += negative;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	itoachar(str, n, len);
	str[--len] = '\0';
	if (negative)
		str[0] = '-';
	return (str);
}
