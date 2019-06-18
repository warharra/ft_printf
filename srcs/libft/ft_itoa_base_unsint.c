#include "libft.h"

static int		ft_nblen(uintmax_t nb, int base)
{
		int		i;

			i = 1;
				while (nb >= (uintmax_t)base)
						{
									i++;
											nb = nb / (uintmax_t)base;
												}
					return (i);
}

char			*ft_itoa_base_unsint(uintmax_t value, int base)
{
		char	*str;
			int		len;

				len = ft_nblen(value, base);
					if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
								return (NULL);
						str[len] = '\0';
							while (--len >= 0)
									{
												str[len] = (value % base >= 10) ? (value % base) + 55 :
																(value % base) + '0';
														value = value / base;
															}
								return (str);
}
