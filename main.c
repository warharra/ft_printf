/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:41:00 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/12 16:02:43 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int main()
{
	ft_printf("test %#d %0d %#d %+8", 1,1,1);
	return (0);
}
