/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:00:00 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/12 16:01:58 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			parse_args(&pf);
//			reset_struct(&pf);
		}
	}
	return (0);
//	end (&pf);
}
