#include "ft_printf.h"

int	main()
{
	printf("Print moi mes premiers tests chien\n");
	ft_printf("Print moi mes premiers tests chien\n");

	ft_printf("------------------\n");

	printf("Un char : %c\n", 'a');
	ft_printf("Mon char : %c\n", 't');

	ft_printf("------------------\n");

	printf("Une string : %s", "Mama la string\n");
	ft_printf("Mon string : %s", "Mama ne touche pas mes string\n");

	ft_printf("------------------\n");

	printf("Un int : %i\n", -56854);
	ft_printf("Mon int : %i", -523414);
	return (0);
}
