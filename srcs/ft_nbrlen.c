#include "../includes/ft_printf.h"

int		ft_nbrlen(uintmax_t nb, intmax_t base)
{

	printf("je rentre ft_nbrlen\n");
	int				len;
	printf("nb de ft_nbrlen %ju\n base%jd\n", nb, base);
	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}
