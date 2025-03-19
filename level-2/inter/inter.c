/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:50:07 by saalarco          #+#    #+#             */
/*   Updated: 2025/02/28 18:11:45 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_result(char *one, char *two, int *used)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (one[i])
	{
		j = 0;
		while (two[j])
		{
			if (one[i] == two[j])
			{
				if (used[(unsigned char) one[i]] == 1)
					write (1, &(one[i]), 1);
				used[(unsigned char) one[i]] = 0;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	used[255];
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (argv[1][i])
		{
			used[(unsigned char)argv[1][i]] = 1;
			i++;
		}
		ft_write_result(argv[1], argv[2], used);
	}
	write (1, "\n", 1);
	return (0);
}
