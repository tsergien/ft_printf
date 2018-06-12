#include <stdio.h>
//#include "../ft_pr/includes/ft_printf.h"
#include "includes/ft_printf.h"
#include <locale.h>
#include <wchar.h>


int main()
{
	setlocale(LC_ALL, "");
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
	ft_printf("ft_print:_%10S\n\n", (wchar_t *)q);

	/**********               x conversion different types          ***********/
	
	// short int ha = -42;
	// int a = 42111;
	// long int la = -4211111;
	// long long lla = -41111112;

	// ft_printf("ft: %hx\n", ha);
	// printf("pr: %hx\n\n", ha);

	// ft_printf("ft: %x\n", a);
	// printf("pr: %x\n\n", a);
	
	// ft_printf("ft: %lx\n", la);
	// printf("pr: %lx\n\n", la);
	
	// ft_printf("ft: %llx\n", lla);
	// printf("pr: %llx\n\n", lla);

	// ft_printf("ft: %hx\n", 4294967296);//undef
	// //printf("pr: %hx\n", 4294967296);

	// ft_printf("ft: %jx\n", -4294967296);
	// //printf("%pr: jx\n", -4294967296);

	// ft_printf("ft: %#-08x\n", 42);//undef
	// //printf("pr: %#-08x\n", 42);

	// ft_printf("ft: %lx\n", 4294967296);//undef
	// printf("pr: %lx\n", 4294967296);

	// ft_printf("ft: @moulitest: %s\n", NULL);
	// printf("pr: @moulitest: %s\n\n", NULL);

	// // /***************          CHARS                                     ******/

	// ft_printf("ft: @moulitest: %c\n", 0);
	// printf("pr: @moulitest: %c\n\n", 0);


	// ft_printf("ft: %d\n", -129);
	// printf("pr: %d\n\n", -129);


	// ft_printf("ft: %d\n", 128);
	// printf("pr: %d\n\n", 128);
	
	// ft_printf("ft: null %c and text\n", 0);
	// printf("pr: null %c and text\n\n", 0);

	// // /**************      numbers (10-sys)               ***************/
	
	// char *adr;
	// ft_printf("ft: %p\n", &adr);
	// printf("pr: %p\n\n", &adr);

	// ft_printf("ft: %U\n", (unsigned int)4294967296);
	// printf("pr: %U\n\n", (unsigned int)4294967296);

	// ft_printf("ft: %.10d\n", 4242);                    
	// printf("ft: %.10d\n\n", 4242);                    
	
	// ft_printf("ft: %10.5d\n", 4242);                   
	// printf("pr: %10.5d\n\n", 4242);                   
	
	// ft_printf("ft: %-10.5d\n", 4242);                  
	// printf("pr: %-10.5d\n\n", 4242);                  
	
	// ft_printf("ft: % 10.5d\n", 4242);                  
	// printf("pr: % 10.5d\n\n", 4242);                  
	
	// ft_printf("ft: %+10.5d\n", 4242);                  
	// printf("pr: %+10.5d\n\n", 4242);                  
	
	// ft_printf("ft: %-+10.5d|\n", 4242);
	// printf("pr: %-+10.5d|\n\n", 4242);

	// ft_printf("ft: %0+5d\n", -42); 
	// printf("pr: %0+5d\n\n", -42);

	// ft_printf("ft: %5d\n", -42);
	// printf("pr: %5d\n\n", -42);
	
	// ft_printf("ft: %05d\n", -42);
	// printf("pr: %05d\n\n", -42);
	
	// int si = -11;
	// int sii = -1;
	// ft_printf("ft: %4.3d\n", si);
	// printf("pr: %4.3d\n", si); 

	// ft_printf("ft: %03.2d\n", sii);
	// printf("pr: %03.2d\n", sii); 

	// ft_printf("ft: %+03.2d\n", sii);
	// printf("pr: %+03.2d\n", sii); 

	// ft_printf("ft: %c|\n", '\n');
	// printf("pr: %c|\n", '\n');

	// ft_printf("ft: %C|\n", 65536);
	// printf("pr: %C|\n", 65536);

	char c = 'Q';
	// ft_printf("%p%S%D|%o|%O|%u|%U|||||%x|%X|%c|%C|\n", &c, (wchar_t *)q, 2147483647,
	// 	10, 11, 12, 13, 14, 15, c, 945);
	// printf("%p%S%D|%o|%O|%u|%U|||||%x|%X|%c|%C|\n",  &c, (wchar_t *)q, 2147483647,
	// 	10, 11, 12, 13, 14, 15, c, 945);

	ft_printf("%o|%O|%u|%U|||||%x|%X|%c|%C|\n", 4, 11,  12, 13, 14, 7, c, 945);
	printf("%o|%O|%u|%U|||||%x|%X|%c|%C|\n", 4, 11,  12, 13, 14, 7, c, 945);

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
