#include "ft_printf.h"

int	main()
{
	printf("Print moi mes premiers tests chien\n");
	ft_printf("Print moi mes premiers tests chien\n");

	ft_printf("------------------\n");

	printf("Un char : %c\n", 'a');
	ft_printf("Mon char : %c\n", 'a');

	ft_printf("------------------\n");

	printf("Une string : %s", "Mama la string\n");
	ft_printf("Mon string : %s", "Mama ne touche pas mes string\n");

	ft_printf("------------------\n");

	printf("Un int : %i\n", -56854);
	ft_printf("Mon int : %i\n", -56854);

	ft_printf("------------------\n");

	printf("Un double : %d\n", -5665);
	ft_printf("Mon double : %d\n", -5665);

	ft_printf("------------------\n");

	printf("Un unsigned : %u\n", 1248);
	ft_printf("Mon unsigned : %u\n", 1248);

	ft_printf("------------------\n");

	printf("Un entier en hexa : %x\n", 25698);
	ft_printf("Mon entier hexa : %x\n", 25698);

	ft_printf("------------------\n");


	printf("Un pourcent : %%\n");
	ft_printf("Mon pourcent : %%\n");

	ft_printf("------------------\n");

	int a = 12;
	void *p = &a;

	printf("Un pointeur : %p\n", p);
	ft_printf("Mon pointeur : %p\n", p);
	return (0);
}
