#include "ft_printf.h"

int			isnan(long double nb)
{

	printf("je rentre isnan\n");
	return (nb != nb);
}

int			isinf(long double nb)
{

	printf("je rentre isinf");
	return (!isnan(nb) && isnan(nb - nb));
}

intmax_t	pow_ten(intmax_t nb, int n)
{

	printf("je rentre pow_ten");
	intmax_t res;

	res = 1;
	while (n--)
		res *= nb;
	return (res);
}
