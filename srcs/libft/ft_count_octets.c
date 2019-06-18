#include "libft.h"

int		ft_count_octets(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base_unsint(n, 2);
	while (str[i] != '\0')
		i++;
	free(str);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return 2;
	else if (i <= 16)
		return 3;
	else
		return 4;	
							
													
}
