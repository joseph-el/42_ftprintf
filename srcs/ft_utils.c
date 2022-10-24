/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:15:31 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/23 16:35:55 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == '\0' && *str != (char)c)
		return (0);
	return (1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		res += ft_putchar(*s);
		s++;
	}
	return (res);
}

int	put_nbr(int to_print)
{
	char	*using;
	long	tmp;
	int		res;

	tmp = to_print;
	res = 0;
	using = ft_itoa(tmp);
	res += ft_putstr(using);
	free(using);
	return (res);
}

void	set_as_zero(t_data *ap)
{
	ap->flag = 0;
	ap->base = 16;
}
