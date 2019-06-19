/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:45:45 by pthan             #+#    #+#             */
/*   Updated: 2019/04/11 22:03:24 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			isnan(long double nb)
{
	return (nb != nb);
}

int			isinf(long double nb)
{
	return (!isnan(nb) && isnan(nb - nb));
}

intmax_t	pow_ten(intmax_t nb, int n)
{
	intmax_t res;

	res = 1;
	while (n--)
		res *= nb;
	return (res);
}
