/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:38 by saalarco          #+#    #+#             */
/*   Updated: 2025/02/24 19:27:28 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		while (i > 0)
		{
			i--;
			write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
