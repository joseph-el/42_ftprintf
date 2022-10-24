/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:40:24 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/24 22:09:25 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_base(unsigned long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
/*
* this function handel (X, x, u) format take by (t_data)
* and convert the nb (base 10) to (base that is given)
* & the function base_itoa will be store 
* the result in a arrays type char
*/

char	*base_itoa(unsigned long nb, int base, t_data *ap)
{
	char	*str;
	int		i;

	i = ft_base(nb, base);
	str = malloc(i + 1);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb != 0)
	{
		if (ap->format == 'X')
			str[i] = M_HEX[nb % base];
		else
			str[i] = N_HEX[nb % base];
		nb /= base;
		i--;
	}
	return (str);
}
/*
* ft_pointers take care by the format (p)
* she convert the value of void pointers to hex
* by (itoa_base) and write (0x) the prefix for hexadecimal
* numeric constants  
*/

void	ft_pointers(void *_adress, t_data *ap)
{
	unsigned long	using;
	char			*res;

	using = (unsigned long long)_adress;
	res = base_itoa(using, 16, ap);
	ap->t_res += ft_putstr("0x");
	ap->t_res += ft_putstr(res);
	free(res);
}

int	hex_zero(t_data *ap)
{
	int	res;

	res = 0;
	if (ap->format == 'x')
		res += ft_putstr("0x");
	else
		res += ft_putstr("0X");
	return (res);
}
/*
* This function deal with all format (d, i, u, x, X, p, s, c)
* its gets the format to be print using the (t_data)
* use help the argument pointer va_args()
*/

void	ft_print_format(t_data *ap)
{
	char	*tmp;

	if (ap->format == 'p')
		ft_pointers(va_arg(ap->args, void *), ap);
	else if (ap->format == 'x' || ap->format == 'X' || ap->format == 'u')
	{
		tmp = base_itoa(va_arg(ap->args, unsigned int),(ap->format == 'u') ? 10 : 16, ap);
		if (ap->flag == '#' && tmp[0] != '0')
			ap->t_res += hex_zero(ap);
		ap->t_res += ft_putstr(tmp);
		free(tmp);
	}
	else if (ap->format == 'i' || ap->format == 'd')
		ap->t_res += put_nbr(va_arg(ap->args, int));
	else if (ap->format == 's')
		ap->t_res += ft_putstr(va_arg(ap->args, char *));
	else if (ap->format == 'c')
		ap->t_res += ft_putchar(va_arg(ap->args, int));
	else
		ap->t_res += ft_putchar('%');
}
