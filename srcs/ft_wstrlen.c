#include "../includes/ft_printf.h"

size_t	ft_wstrlen(wchar_t *s)
{

	
	printf("je rentre ft_wstrlen\n");
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i += ft_wcharlen(*s);
		s++;
	}
	return (i);
}
