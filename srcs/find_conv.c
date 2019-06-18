#include "../includes/ft_printf.h"

char		find_conv(char *str, char c)
{
	
	printf("je rentre find_conv\n");
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	return (0);
}
