#include "../includes/ft_printf.h"

t_conv g_conv[] =
{
	{"dDi", &ft_castconvint},
	{"uUoOxXbB", &ft_castconvuox},
	{"cC", &char_conv},
	{"sS", &str_conv},
	{"%", &print_pct},
	{"p", &print_ptr_add},
	{"f", &float_conv}
};

int		is_conv(t_printf *pf)
{

	printf("je rentre is_conv\n");
	int i;

	i = 0;
	while (i <= 6)
	{
		if (find_conv(g_conv[i].c, pf->conv))
		{
			printf("i = %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}

int		conv_to_fct(t_printf *pf)
{

	printf("je rentre conv_to_fct\n");
	int i;

	i = is_conv(pf);
	printf("is_conv(pf) %d\n", i);

	if (i != -1)
	{
		
	printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
		g_conv[i].funct(pf);
	}
	return (1);
}

/*
** find_conv returns a char : the proper conv ("s,d,x..")
*/

int		get_conversion(t_printf *pf)
{
	
	
	
	printf("je rentre get_conversion\n");
	if ((pf->conv = find_conv("sSpdDioOuUxXcCfFbB%", *pf->format)) != 0)
	{
		//printf("je rentre iciiiiiiiiiiii\n");
		//printf("aaaaaaaaaaaaaaaaaaa%c\n", *pf->format);
		pf->format++;
		
		//printf("aaaaaaaaaaaaaaaaaaa%c\n", *pf->format);
		if ((pf->conv == 'o') || (pf->conv == 'O'))
			pf->base = B_OCT;
		else if ((pf->conv == 'x') || (pf->conv == 'X') || (pf->conv == 'p'))
		{
			pf->base = B_HEX;
			printf("base = %d\n",pf->base);
		}
		else if ((pf->conv == 'b') || (pf->conv == 'B'))
			pf->base = B_BIN;
		else
		{
			
			//printf("je rentre \n");
			pf->base = B_DEC;
			printf("base = %d\n",pf->base);
		}
	}
	else
		return (0);
	return (1);
}
