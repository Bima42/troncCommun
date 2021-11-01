#include "ft_printf.h"

int	main()
{
	int	v;
	int	my_v;

	v = printf("Print moi mes premiers tests chien\n");
	my_v = ft_printf("Print moi mes premiers tests chien\n");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Une char : %c\n", 'a');
	my_v = ft_printf("Mon char : %c\n", 'a');
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Une string : %s", "Mama la string\n");
	my_v = ft_printf("Mon string : %s", "Mama la string\n");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Un int : %i\n", -56854);
	my_v = ft_printf("My int : %i\n", -56854);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Un double : %d\n", -5665);
	my_v = ft_printf("My double : %d\n", -5665);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Un unsigned : %u\n", 1248);
	my_v = ft_printf("My unsigned : %u\n", 1248);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Un entier en hexa : %x\n", 25698);
	my_v = ft_printf("My entier en hexa : %x\n", 25698);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Un purcent : %%%%\n");
	my_v = ft_printf("My purcent : %%%%\n");
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Mix : %d et puis %c\n", 123, 'z');
	my_v = ft_printf("Mix : %d et puis %c\n", 123, 'z');
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	int a = 12;
	void *p = &a;

	v = printf("Un pointeur : %p\n", p);
	my_v = ft_printf("Mon pointeur : %p\n", p);
	printf("Value = %d || My value = %d\n", v, my_v);

	ft_printf("--------------------------------------------\n");

	v = printf("Mix2 : %%%d%%%i\n", 123, 456);
	my_v = ft_printf("Mix2 : %%%d%%%i\n", 123, 456);
	printf("Value = %d || My value = %d\n", v, my_v);

	return (0);
}
