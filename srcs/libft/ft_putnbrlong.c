#include "libft.h"

void	ft_putnbrlong_count(long long n, int *count)
{
		if (n == -9223372036854775807 - 1)
				{
							write(1, "-", 1);
									write(1, "9", 1);
											*count = *count + 1;
													*count = *count + 1;
															n = 223372036854775808;
																}
			if (n < 0)
					{
								ft_putchar('-');
										*count = *count + 1;
												n = -n;
													}
				if (n > 9)
						{
									ft_putnbrlong_count(n / 10, count);
											ft_putnbrlong_count(n % 10, count);
												}
					if (n <= 9)
							{
										ft_putchar(n + '0');
												*count = *count + 1;
													}
}
