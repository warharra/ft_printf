/*
** warning: flag ' ' is ignored when flag '+' is present [-Wformat]
** warning: flag '0' is ignored when flag '-' is present [-Wformat]
** => '+' > ' ' et '-' > '0'
** personal note : ' ' flag is ignored when flag '0' is present
** => '0' > ' '
*/

#include "../includes/ft_printf.h"

/*
** renvoie -1 si il faut incrementer la partie entiere
** renvoie la precision arrondie sinon
*/

intmax_t		ft_getdecimal(long double nb, int n)
{

	printf("je rentre ft_putdecimal\n");
	intmax_t	res;
	int			i;

	i = 0;
	res = 0;
	nb = (nb - (intmax_t)nb) * 10;
	while (i++ < n)
	{
		res = res * 10 + (intmax_t)nb;
		nb = (nb - (intmax_t)nb) * 10;
	}
	if (nb >= 5)
		res++;
	if (res == pow_ten(10, n))
		return (-1);
	return (res);
}

void			ft_putllnbr(t_printf *pf, intmax_t nb)
{

	printf("je rentre ft_putllnbr\n");
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		ft_putllnbr(pf, (nb / 10));
	char_padding(pf, (nb % 10 + 48));
}

void			ft_putdecimal(t_printf *pf, intmax_t decimal)
{
	
	printf("je rentre ft_getdecimal\n");
	int n;

	n = 0;
	if (decimal == -1)
	{
		while (n++ < pf->precision)
			char_padding(pf, '0');
	}
	else
	{
		while (ft_nbrlen(decimal, 10) < pf->precision)
		{
			char_padding(pf, '0');
			pf->precision--;
		}
		ft_putllnbr(pf, decimal);
	}
}

static void		f_flags_padding(t_printf *pf, long double nb)
{

	printf("je rentre f_flags_padding\n");
	if ((nb < 0) || !(1 / nb > 0))
		char_padding(pf, '-');
	if ((!(pf->flags & F_ZERO) && pf->flags & F_PLUS && nb >= 0)
		|| pf->flags & F_SPACE)
		(pf->flags & F_SPACE) ? char_padding(pf, ' ') : char_padding(pf, '+');
}

void			f_conv(t_printf *pf, long double nb)
{
	
	printf("je rentre f_conv\n");
	intmax_t	floor;
	intmax_t	decimal;

	f_flags_padding(pf, nb);
	decimal = (pf->precision) ? ft_getdecimal(nb, pf->precision) : 0;
	floor = (decimal == -1) ? (intmax_t)nb + 1 : (intmax_t)nb;
	if (!pf->precision)
	{
		if (((int)((nb - (intmax_t)nb) * 10)) >= 5)
			floor++;
	}
	ft_putllnbr(pf, floor);
	(pf->precision || (pf->flags & F_HASH)) ? char_padding(pf, '.') : 0;
	(pf->precision) ? ft_putdecimal(pf, decimal) : 0;
}
