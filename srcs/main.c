#include <stdio.h>
#include "../includes/ft_printf.h"
int main()
{
	char *p = "str";
	//ft_printf("%%");
	//ft-printf ("Characters: %c %c \n", 'a', 65);
	//ft_printf ("%jd\n",650000L);
	//ft_printf ("Preceding with blanks: %10d \n", 1977);
	//ft_printf ("Preceding with zeros: %010d \n", 1977);
	//ft_printf ("d = %d\n x =%x\n o =%o \n", 15, 15, 15);
	//ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	//ft_printf ("Width trick: %*d \n", 5, 10);
	//ft_printf ("je test\n");
	//ft_printf("je test == %s\n", "wafae");
//	printf("%*5d\n", 18, 18);
	//ft_printf("%*d\n", 10, 18);
	//printf("!!!!!!!!!!!%-0d\n", 10);
//	printf("%10d \n", 10);
	//ft_printf("test 1 :%c\n", 'a');
	
	//ft_printf("test 1 :%.5c\n test 2 %5c\n test 3%05c\n test 4%-5c\n",'a', 'b', 'c' , 'd');
	//printf("%.d\n",9);
	ft_printf("test %s\ntest2 %*5d\n test 3 %*d\n","olkjhgfdsazxcvbnmt",2, 3,4,4);
	printf("test %4d\ntest2 %*5d\n test 3 %*d",1,2, 3,4);
	//printf("test %4d\n",'a');
return 0;
}
