/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:40:45 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/19 16:48:49 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_flags(t_printf *pf)
{
	int res;

	while ((res = find_flag("#0-+ ", *pf->format)) && pf->format++)
		pf->flags = pf->flags | res;
	pf->flags = ((pf->flags & F_MINUS) && (pf->flags & F_ZERO)) ? pf->flags & ~F_ZERO : pf->flags;
	pf->flags = ((pf->flags & F_PLUS) && (pf->flags & F_SPACE)) ? pf->flags & ~F_SPACE : pf->flags;
}

void	get_min_len(t_printf *pf)
{
	int len;
	if (*pf->format >= 48 && *pf->format <= 57)
	{
		//pf->min_len = MAX(ft_atoi(pf->format), 1);
		len = ft_atoi(pf->format);
		if(len > 1)
			pf->min_len = len;
		else
			pf->min_len = 1;
	}
	if (*pf->format == '*')
	{
		pf->format++;
		pf->min_len = va_arg(pf->ap, int);
		/*if (pf->min_len < 0)
			(pf->flags |= F_MINUS) && (pf->flags &= ~F_ZERO);
		pf->min_len = ABS(pf->min_len);*/
		if (*pf->format >= 48 && *pf->format <= 57)
				pf->min_len = ft_atoi(pf->format);
	}
	while (*pf->format >= 48 && *pf->format <= 57)
		pf->format++;
}

void	get_precision(t_printf *pf)
{
	if (*pf->format == '.')
	{
		(pf->format)++;
		pf->precision = ft_atoi(pf->format) ? ft_atoi(pf->format) : -1;
		if (*pf->format == '*')
		{
			pf->format++;
			pf->precision = va_arg(pf->ap, long int);
			if (pf->precision <= 0)
				pf->precision = (pf->precision == 0) ? -1 : 0;
		}
		while (*pf->format >= 48 && *pf->format <= 57)
			pf->format++;
	}
}

void	get_length_modifier(t_printf *pf)
{
	int res;

	if ((res = find_flag("hlLjz", *pf->format)))
	{
		res <<= 5;
		pf->format++;
		if (((res == 32) && (*pf->format == 'h')) ||
				((res == 64) && (*pf->format == 'l')))
		{
			res <<= 5;
			pf->format++;
		}
		pf->flags |= res;
	}
}

int		parse_arg(t_printf *pf)
{
	get_flags(pf);
	get_min_len(pf);
	get_precision(pf);
	get_length_modifier(pf);
	if (!get_conversion(pf))
		return (0);
	conv_to_fct(pf);
	return (1);
}
