/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:22:05 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/12 17:21:20 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# define BUFF_SIZE 128


// GESTION DES FLAGS 

# define F_HASH (1 << 0) //'#' 0000 0000 0001
# define F_ZERO (1 << 1)//'0'  0000 0000 0010
# define F_MINUS (1 << 2)//'-' 0000 0000 0100
# define F_PLUS (1 << 3)//'+'  0000 0000 1000
# define F_SPACE (1 << 4)//' ' 0000 0001 0000
//GESTION DES FLAGS 2

# define F_H (1 << 5) //'h'   0000 0010 0000
# define F_HH (1 << 6) //'hh' 0000 0100 0000
# define F_L (1 << 7) //'l'   0000 1000 0000
# define F_LL (1 << 8) //'ll' 0001 0000 0000
# define F_LLL (1 << 9) //'L' 0010 0000 0000
# define F_J (1 << 10) //'j'  0100 0000 0000
# define F_Z (1 << 11) //'z'  1000 0000 0000

// BASES 

# define B_BIN (1 << 1)
# define B_DEC 10
# define B_OCT (1 << 2)
# define B_HEX (1 << 3)

typedef struct	s_printf
{
	char		*format;
	char		buff[BUFF_SIZE];
	int			ret;
	int			buff_i;
	int			flags;
	int			min_len;
	int			precision;
	int			base;
	int			neg;
	int			pad;
	char		conv;
	va_list		ap;
}				t_printf;

typedef	void(*t_f_conv)(t_printf*);

typedef struct	s_conv
{
	char		*c;
	t_f_conv	funct;
}				t_conv;


int	ft_printf(const char *format, ...);
int	parse_args(t_printf *pf);
void ft_bzero(void *s, size_t n);


#endif
