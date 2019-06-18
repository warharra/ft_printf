#include "libft.h"

void	ft_putstr_count(char const *s, int *count)
{
	int i;

	i = 0;
				
	if (s != NULL)	
	{
									while (s[i] != '\0')
				
									{															write(1, &s[i], 1);															*count = *count + 1;				
	i++;
																								}
										}
}
