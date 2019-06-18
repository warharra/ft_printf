#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *str)
{

	printf("je rentre ft_strlen");
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
