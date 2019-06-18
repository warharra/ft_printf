#include "../includes/ft_printf.h"

void		print_ptr_add(t_printf *pf)
{
	 printf("je rentre print_ptr_add\n");
	
	void	*ptr;
	int		len;

	ptr = (void *)va_arg(pf->ap, void *);
	printf("talalalala \n");
	write(1, ptr, 11);
	printf("ptr...........%p\n ptr............... %s\n", ptr, ptr);
	len = ft_nbrlen((uintmax_t)ptr, B_HEX);
	printf("len >>>>> %d\n pad >>>%d\n min_len >>>>%d\n", len, pf->pad, pf->min_len);
	pf->pad = pf->min_len - 2 - len;
	printf("len >>>>> %d\n pad >>>%d\n min_len >>>>%d\n", len, pf->pad, pf->min_len);
	if (ptr == 0 && pf->precision == -1)
	{
		printf("je             rentre             ");
		hash_padding(pf);
	}
	else
	{
		printf("je             rentre          iciiiiiiii   ");
		!(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
		hash_padding(pf);
		buffer(pf, ft_lltoa_base((uintmax_t)ptr, pf->base), 0, len);
		(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
	}
}

void		print_pct(t_printf *pf)
{

	printf("je rentre print_pct\n");
	pf->pad = pf->min_len ? pf->min_len - 1 : 0;
	if (!(pf->flags & F_MINUS))
	{
		(pf->flags & F_ZERO) ? min_padding(pf, '0', pf->pad)
		: min_padding(pf, ' ', pf->pad);
	}
	char_padding(pf, '%');
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', pf->pad) : 0;
}
