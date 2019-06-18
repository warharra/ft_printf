#include "libft.h"

char	*ft_strnew_a_size(size_t size)
{
		char	*str;
			size_t	i;

				i = 0;
					str = (char*)malloc(sizeof(*str) * (size + 1));
						if (str == NULL)
									return (NULL);
							while (i < size)
									{
												str[i] = 'a';
														i++;
															}
								str[i] = '\0';
									return (str);
}
