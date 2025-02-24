/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print_own.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:15:59 by saalarco          #+#    #+#             */
/*   Updated: 2025/02/24 19:28:27 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		i--;
		while (i > 0)
		{
			write(1, &(argv[1][i]), 1);
			i--;
		}
		write(1, &(argv[1][0]), 1);
		write (1, "\n", 1);
		return (1);
	}
	write(1, "\n", 1);
	return (1);
}
