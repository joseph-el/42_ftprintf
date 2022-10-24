/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:34:28 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/24 11:54:11 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 *	This version of printf function handles
 *	flags ('+', ' ', '#')
 *	passes 1 to ft_get_format as an order to parse the format string.
 **/

int	ft_printf(const char *s, ...)
{
	t_data	*ap;
	int		res;
	int		i;

	ap = malloc(sizeof(t_data));
	if (!ap)
		return (0);
	ap->t_res = 0;
	i = 0;
	va_start(ap->args, s);
	ft_get_format(s, ap, i, 1);
	res = ap->t_res;
	va_end(ap->args);
	free(ap);
	return (res);
}
