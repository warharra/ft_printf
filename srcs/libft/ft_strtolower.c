#include "libft.h"

char	*ft_strtolower(char *str)
{
		int		i;
			char	*dst;

				i = 0;
					if (!str)
								return (NULL);
						if (!(dst = (char*)malloc(sizeof(*dst) * ft_strlen(str) + 1)))
									return (NULL);
							while (str[i] != '\0')
									{
												if (ft_isupper(str[i]))
																dst[i] = str[i] + 32;
														else
																		dst[i] = str[i];
																i++;
																	}
								dst[i] = '\0';
									return (dst);
}
