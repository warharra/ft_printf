#include "libft.h"

void	write_count(int sortie, const char *s, int size, int *count)
{
	write(sortie, s, size);
	*count = *count + size;
}
