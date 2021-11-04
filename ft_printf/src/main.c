#include "ft_printf.h"

int	main()
{
	int	v;
	int	my_v;

	ft_printf("\n----------------STRING_TEST----------------\n");

	v = printf("Une string : %s", "Mama la string\n");
	my_v = ft_printf("Mon string : %s", "Mama la string\n");
	printf("Value = %d || My value = %d\n", v, my_v);
	v = printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	my_v = ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n-----------------NORMAL_TEST----------------\n");
	v = printf("Print moi mes premiers tests chien\n");
	my_v = ft_printf("Print moi mes premiers tests chien\n");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n------------------CHAR_TEST------------------\n");

	v = printf("Une char : %c\n", 'a');
	my_v = ft_printf("Mon char : %c\n", 'a');
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n--------------------INT_TEST------------------\n");

	v = printf("Un int : %i\n", -56854);
	my_v = ft_printf("My int : %i\n", -56854);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n-------------------DOUBLE_TEST----------------\n");

	v = printf("Un double : %d\n", -5665);
	my_v = ft_printf("My double : %d\n", -5665);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n-----------------UNSIGNED_TEST------------------\n");

	v = printf("Un unsigned : %u\n", 1248);
	my_v = ft_printf("My unsigned : %u\n", 1248);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n---------------------HEXA_TEST------------------\n");

	v = printf("Un entier en hexa : %x\n", 25698);
	my_v = ft_printf("My entier en hexa : %x\n", 25698);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n--------------------PURCENT_TEST----------------\n");

	v = printf("Un purcent : %%%%\n");
	my_v = ft_printf("My purcent : %%%%\n");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n---------------------MIX_TEST-------------------\n");

	v = printf("Mix : %d et puis %c\n", 123, 'z');
	my_v = ft_printf("Mix : %d et puis %c\n", 123, 'z');
	printf("Value = %d || My value = %d\n", v, my_v);

	v = printf("Mix2 : %%%d%%%i\n", 123, 456);
	my_v = ft_printf("Mix2 : %%%d%%%i\n", 123, 456);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n-------------------POINTER_TEST---------------\n");

	char *str = NULL;
	v = printf(" NULL %s NULL \n", str);
	my_v = ft_printf(" NULL %s NULL \n", str);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("\n--------------------------------------------\n");

	return (0);
}
