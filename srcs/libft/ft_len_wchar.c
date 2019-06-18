#include "libft.h"

int	ft_len_wchar(wchar_t *str)
{
		int i;
			int cpt;

				cpt = 0;
					i = 0;
						while (str[i] != '\0')
								{
											if (str[i] <= 255)
															cpt = cpt + 1;
													else
																	cpt = cpt + ft_count_octets(str[i]);
															i++;
																}
							return (cpt);
}
