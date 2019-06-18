#include "../includes/ft_printf.h"

void		zero_flag_pad(t_printf *pf, int nb_len)
{
	
	printf("je rentre zero_flag_pad\n");
	if (pf->flags & F_ZERO)
	{
		pf->pad = pf->precision ? pf->precision - nb_len :
			(pf->min_len - nb_len - pf->neg);
		if ((pf->flags & F_SPACE) && (pf->precision == 0))
			pf->pad--;
	}
	else
		pf->pad = pf->precision ? pf->precision - nb_len : 0;
	pf->pad = pf->pad < 0 ? 0 : pf->pad;
}

void		plus_flag_pad(t_printf *pf, int nb_len)
{

	printf("je rentre plus_flag_pad\n");
	if (pf->flags & F_PLUS)
	{
		char_padding(pf, '+');
		if (nb_len >= pf->precision)
			pf->pad--;
	}
}

void		hash_flag_pad(t_printf *pf, int nb)
{
	
	printf("je rentre hash_flag_pad\n");
	if (pf->conv == 'x' || pf->conv == 'X')
	{
		if ((pf->flags & F_HASH) && nb != 0)
		{
			hash_padding(pf);
			pf->pad = pf->precision ? pf->pad : pf->pad - 2;
		}
	}
	else if (pf->conv == 'o' || pf->conv == 'O')
	{
		if ((pf->flags & F_HASH))
		{
			hash_padding(pf);
			pf->pad--;
		}
	}
}
