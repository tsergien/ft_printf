#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <wchar.h>


int main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	ac++;
	av++;
	char *s;
	s = strdup("α Ձ Ɛ χ");

	wchar_t *q;
	q = (wchar_t *)malloc(sizeof(wchar_t) * 7);
	int i = 0;
	while ( i < 5)
	{
		q[i] = 945 + i;
		i++;
	}
	q[i++] = 'a';

	printf("original:_%3C\n", (wchar_t)*q);
	ft_printf("ft_print:_%3.C\n\n", (wchar_t)*q);

	printf("original:_%10S\n", (wchar_t *)q);
	ft_printf("ft_print:_%10S\n", (wchar_t *)q);


	printf("original:_%5.%\n");
	ft_printf("ft_print:_%5.%\n");

	free(q);
	free(s);
	return (0);
}



//______________________x__X__o__O______________________________________________________
	// long long l;
	// short int sh;
	// short int sh2;
	// short int sh3;
	// short int sh4;
	// sh = 0;
	// sh2 = -1234;
	// sh3 = 9;
	// sh4 = 15852;
	// l = 0;


	// ft_printf("ft_printf:_%#12.15llo\n", l);
	// printf("original :_%#12.15llo\n", l);
	// printf("\n\n");
	// ft_printf("ft_printf:_%#-10.0ho\n", sh2);
	// printf("original :_%#-10.0ho\n", sh2);
	// printf("\n\n");

	// ft_printf("ft_printf:_%.x\n", sh);
	// printf("original :_%.x\n", sh);
	// printf("\n\n");
	// ft_printf("ft_printf:_%#10.x\n", 123);
	// printf("original :_%#10.x\n", 123);
	// ft_printf("ft_printf:_%#10.o\n", 123);
	// printf("original :_%#10.o\n", 123);
//_______________________-d_i_____________________________________________________________
	// ft_printf("ft_print: %.d\n", 0);
	// printf("original: %.d\n", 0);
	// printf("\n");
	
	// ft_printf("ft_print:%+10d\n", i);
	// printf("original:%+10d\n", i);