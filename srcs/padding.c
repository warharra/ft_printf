#include "../includes/ft_printf.h"

void	char_padding(t_printf *pf, char c)
{
	
	printf("je rentre char_padding\n");
	check_buff(pf);
	pf->buff[pf->buff_i] = c;
	pf->buff_i++;
}

void	hash_padding(t_printf *pf)
{

	printf("je rentre hash_padding\n");
	char_padding(pf, '0');
	check_buff(pf);
	if (pf->conv == 'x' || pf->conv == 'p')
		pf->buff[pf->buff_i++] = 'x';
	else if (pf->conv == 'X')
		pf->buff[pf->buff_i++] = 'X';
}

void	min_padding(t_printf *pf, char c, int len)
{

	printf("je rentre min_padding\n");
	if (len > 0)
		while (len--)
			char_padding(pf, c);
}
