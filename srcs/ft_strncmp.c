#include "../includes/ft_printf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{

	printf("je rentre ft_strncmp\n");
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
