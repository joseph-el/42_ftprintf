/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_building.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:38:06 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/24 22:11:39 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_flags(char c)
{
	return (c == '+' || c == ' ' || c == '#');
}

int	is_format(char c)
{
	return (c == 'd' || c == 'x' || c == 'X' || c == 's'
		|| c == 'c' || c == 'p' || c == '%' || c == 'i' || c == 'u');
}
/*
 * This function prints the characters in string,
 * when '%' is found she store the format data be printet and call
 * print_format() to print the argument.
 */

void	ft_get_format(const char *s, t_data *ap, int i, bool b_check)
{
	while (s[i])
	{
		set_as_zero(ap);
		if (s[i] != '%')
			ap->t_res += ft_putchar(s[i]);
		else
		{
			if (ft_strchr("xXidupcs%", s[i + 1]))
			{
				ap->format = s[i + 1];
				ft_print_format(ap);
				i++;
			}
			else if (b_check && is_flags(s[i + 1]))
			{	
				i++;
				ap->flag = s[i];
				while (s[i] == ap->flag && !is_format(s[i]))
					i++;
				apply_flags(s, i, ap);
			}
		}
		i++;
	}
}
/*
* this function its it handles the flags ('+',' ', '#'),
* when get_format() found flags she store data flags
* & call this function for apply flags on arguments
*/

void	apply_flags(const char *s, int i, t_data *ap)
{
	int	res;

	res = 0;
	if (ap->flag == ' ' && ft_strchr("di", s[i]))
	{
		res = va_arg(ap->args, int);
		if (res >= 0)
			ap->t_res += ft_putchar(' ');
		ap->t_res += put_nbr(res);
	}
	else if (ap->flag == '#' && ft_strchr("xX", s[i]))
	{
		ap->format = s[i];
		ft_print_format(ap);
	}
	else if (ap->flag == '+' && ft_strchr("di", s[i]))
	{
		res = va_arg(ap->args, int);
		if (res >= 0)
			ap->t_res += ft_putchar('+');
		ap->t_res += put_nbr(res);
	}
}
