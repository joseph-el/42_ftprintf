/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:17:04 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/10/24 22:10:45 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define N_HEX "0123456789abcdef"
# define M_HEX "0123456789ABCDEF"

typedef struct ft_printf
{
	va_list	args;
	int		t_res;
	int		base;
	char	format;
	char	flag;
}			t_data;

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			put_nbr(int to_print);
int			ft_strchr(const char *str, int c);
int			put_nbr(int to_print);
int			is_format(char c);
int			is_flags(char c);
int			hex_zero(t_data *ap);
int			ft_printf(const char *s, ...);

char		*ft_itoa(int n);
void		ft_print_format(t_data *ap);
void		ft_get_format(const char *s, t_data *ap, int i, bool check);
void		apply_flags(const char *s, int i, t_data *ap);
void		set_as_zero(t_data *ap);

#endif
