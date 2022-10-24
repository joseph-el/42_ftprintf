/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:20:41 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/23 23:41:31 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * This version of printf function does not handle
 * flags, passes
 * a 0 to get_format as an order not to parse
 * the format string.
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
	ft_get_format(s, ap, i, 0);
	res = ap->t_res;
	va_end(ap->args);
	free(ap);
	return (res);
}
