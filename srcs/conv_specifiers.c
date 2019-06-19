/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:09:44 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/19 17:35:35 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv g_conv[] =
{
	{"dDi", &ft_castconvint},
	{"uUoOxXbB", &ft_castconvuox},
	{"cC", &char_conv},
	{"sS", &str_conv},
	{"%", &print_pct},
	{"p", &print_ptr_add},
	{"f", &float_conv}
};

int		is_conv(t_printf *pf)
{
	int i;

	i = 0;
	while (g_conv[i].c)
	{
		if (find_conv(g_conv[i].c, pf->conv))
			return (i);
		i++;
	}
	return (-1);
}

int		conv_to_fct(t_printf *pf)
{
	int i;

	i = is_conv(pf);
	if (i != -1)
		g_conv[i].funct(pf);
	return (1);
}

int		get_conversion(t_printf *pf)
{
	if ((pf->conv = find_conv("sSpdDioOuUxXcCfFbB%", *pf->format)) != 0)
	{
		pf->format++;
		if ((pf->conv == 'o') || (pf->conv == 'O'))
			pf->base |= B_OCT;
		else if ((pf->conv == 'x') || (pf->conv == 'X') || (pf->conv == 'p'))
			pf->base |= B_HEX;
		else if ((pf->conv == 'b') || (pf->conv == 'B'))
			pf->base |= B_BIN;
		else
			pf->base = B_DEC;
	}
	else
		return (0);
	return (1);
}
