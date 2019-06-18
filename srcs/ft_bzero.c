#include "../includes/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	
	printf("je rentre ft_bzero\n");
	ft_memset(s, 0, n);
}
