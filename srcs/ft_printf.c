#include "../includes/ft_printf.h"

void		end(t_printf *pf)
{

	printf("je rentre end\n");
	pf->buff[pf->buff_i] = '\0';
	write(pf->fd, pf->buff, pf->buff_i);
	pf->ret += pf->buff_i;
	va_end(pf->ap);
}

int			ft_printf(const char *format, ...)
{


	printf("je rentre ft_printf\n");
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = 1;
	pf.format = (char*)format;
	printf("format :%s\n", pf.format);
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
			color_or_char(&pf);
	}
	end(&pf);
	return (-1);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	printf("je rentre ft_dprintf\n");fflush(stdout);

	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fd = fd;
	pf.format = (char*)format;
	va_start(pf.ap, format);
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			if (!*pf.format)
				break ;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
			color_or_char(&pf);
	}
	end(&pf);
	return (0);
}

void		color_or_char(t_printf *pf)
{
	
	printf("je rentre color_or_char\n");
	int	to_buff;

	if (*pf->format == '{')
	{
		printf("*pf->format%c\n", *pf->format);
		if (!(color(pf) == NULL))
		{
			to_buff = (color(pf) == C_BOLD || color(pf) == C_UNDERLINE) ? 4 : 5;
			buffer(pf, (color(pf)), 0, to_buff);
			pf->format += pf->pad;
		}
		else
		{
			char_padding(pf, *pf->format);
			pf->format++;
		}
	}
	else
	{
		
		printf("je rentre11111");
		char_padding(pf, *pf->format);
		pf->format++;
	}
}

char		*color(t_printf *pf)
{

	printf("je rentre color\n ");
	if (ft_strncmp(pf->format, "{bold}", (pf->pad = 6)) == 0)
		return (C_BOLD);
	else if (ft_strncmp(pf->format, "{underline}", (pf->pad = 11)) == 0)
		return (C_UNDERLINE);
	else if (ft_strncmp(pf->format, "{black}", (pf->pad = 7)) == 0)
		return (C_BLACK);
	else if (ft_strncmp(pf->format, "{red}", (pf->pad = 5)) == 0)
		return (C_RED);
	else if (ft_strncmp(pf->format, "{green}", (pf->pad = 7)) == 0)
		return (C_GREEN);
	else if (ft_strncmp(pf->format, "{yellow}", (pf->pad = 8)) == 0)
		return (C_YELLOW);
	else if (ft_strncmp(pf->format, "{blue}", (pf->pad = 6)) == 0)
		return (C_BLUE);
	else if (ft_strncmp(pf->format, "{purple}", (pf->pad = 8)) == 0)
		return (C_PURPLE);
	else if (ft_strncmp(pf->format, "{cyan}", (pf->pad = 6)) == 0)
		return (C_CYAN);
	else if (ft_strncmp(pf->format, "{white}", (pf->pad = 7)) == 0)
		return (C_WHITE);
	else
		return (NULL);
}
