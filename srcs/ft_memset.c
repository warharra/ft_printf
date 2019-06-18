#include "../includes/ft_printf.h"

void	*ft_memset(void *s, int c, size_t len)
{

	printf("je rentre ft_memset\n");
	char *tmp;

	tmp = s;
	while (len--)
		*tmp++ = c;
	return (s);
}
