/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:41:54 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/11 13:41:58 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_write_width(int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	fill = modifiers.flags[zero] ? '0' : ' ';
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(int len, t_modifiers modifiers)
{
	int n;

	n = 0;
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', FD);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_print_manager(unsigned long pointer, int n, 
		t_modifiers modifiers)
{
	int len;

	len = n;
	if (pointer < 0)
		modifiers.precision++;
	if (modifiers.flags[minus])
	{
		ft_putstr_fd("0x", FD);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || pointer)
			ft_putnbr_base_fd(pointer, BASE_16, FD);
	}
	n += ft_write_width(modifiers.precision > len ?
			modifiers.precision : len, modifiers);
	if(!modifiers.flags[minus] || modifiers.flags[zero])
	{
		ft_putstr_fd("0X", FD);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || pointer)
			ft_putnbr_base_fd(pointer, BASE_16, FD);
	}
	return (n);
}

int		p_req_p(va_list *args, t_modifiers modifiers)
{
	unsigned long	pointer;
	int				n;

	pointer = (unsigned long)va_arg(*args, void *);
	n = ft_ulnumlen_base(pointer, 16) + 2;
	if (!modifiers.precision && !pointer)
		n = 2;
	n = ft_print_manager(pointer, n, modifiers);
	return (n);
}