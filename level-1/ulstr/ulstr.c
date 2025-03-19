/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:13:39 by saalarco          #+#    #+#             */
/*   Updated: 2025/02/27 19:07:32 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ((write(1, "\n", 1)), 1);
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] -= 32;
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			argv[1][i] += 32;
		i++;
	}
	ft_putstr(argv[1]);
	write(1, "\n", 1);
	return (1);
}

/* idea guay*/
// la cadena que me dan la puedo manejar haciendo uso de la va_list
// cajas grandes y cajas pequeñas, write espera un puntero a char (una caja que lleva chars)
// y el resultado de una operación como '+' es un int (una caja más grande, de hecho)
// entonces en algun punto tengo que castear de nuevo a char * (puedo hacer un cambio de variable o como aquí, EN LA FUNCIÓN FT_PUTSTR)

// #include <unistd.h>

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	char	buffer[1000];

// 	i = 0;
// 	if (argc != 2)
// 		return ((write(1, "\n", 1)), 1);
// 	while (argv[1][i] && i < 999)
// 	{
// 		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
// 			buffer[i] = argv[1][i] - 32;
// 		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 			buffer[i] = argv[1][i] + 32;
// 		else
// 			buffer[i] = argv[1][i];
// 		i++;
// 	}
// 	buffer[i] = '\0';
// 	ft_putstr(buffer);
// 	write(1, "\n", 1);
// 	return (0);
// }
