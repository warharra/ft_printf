#include "../includes/ft_printf.h"

void		reset_struct(t_printf *pf)
{
	printf("je rentre RESET_STRUCT\n");
	
	pf->flags = 0;
	pf->precision = 0;
	pf->min_len = 0;
	pf->neg = 0;
	pf->base = 0;
	pf->conv = 0;
	pf->pad = 0;
}

/*void		reset_buff(t_printf *pf)
{
	printf("je rentre rest_buff\n");
	write(pf->fd, pf->buff, BUFF_SIZE - 1);
	ft_bzero(pf->buff, BUFF_SIZE);
	pf->ret += (BUFF_SIZE - 1);
	pf->buff_i = 0;
}*/

void		check_buff(t_printf *pf)
{
	printf("je rentre CHECK_BUFF\n");
	if (pf->buff_i == BUFF_SIZE - 1)
	{
		//reset_buff(pf);
	printf("je rentre rest_buff\n");
	write(pf->fd, pf->buff, BUFF_SIZE - 1);
	ft_bzero(pf->buff, BUFF_SIZE);
	pf->ret += (BUFF_SIZE - 1);
	pf->buff_i = 0;

		
	}
		printf("buff_i :%d\n", pf->buff_i);
}

void		buffer(t_printf *pf, char *str, int i, int n)
{
	printf("je rentre BUFFEriiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n");
	int		len;
	len = n - i;

	
	/*printf("bbbbbbbbbb%d\nlen%d\nsize%d\n",pf->buff_i ,len , BUFF_SIZE - 1);
	
	if (pf->buff_i + len >= BUFF_SIZE - 1)
	{

	printf("je rentre BUFFEraaaaaaaaaaaaaaaaaaaaaaaaaaaaan");
		ft_memcpy(&pf->buff[pf->buff_i], &str[i],
				((BUFF_SIZE - 1) - pf->buff_i));
		i += (BUFF_SIZE - 1) - pf->buff_i;
		//reset_buff(pf);
		check_buff(pf);
		buffer(pf, str, i, n);
	}*/
	//else
		while (len--)
		{
			pf->buff[pf->buff_i++] = str[i++];
			check_buff(pf);
		}
}

void		wstr_tobuff(t_printf *pf, wchar_t *str, int len)
{
	printf("je rentre wstr_tobuff\n");

	int i;

	i = 0;
	while (len > 0)
	{
		i = ft_wcharlen(*str);
		buffer(pf, ft_get_wchar(*str), 0, i);
		len -= i;
		str++;
	}
}
