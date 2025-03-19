/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:24 by saalarco          #+#    #+#             */
/*   Updated: 2025/02/28 19:49:46 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void	ft_str_capitalizer(char *str);
static int	ft_tolower(int c);
static int	ft_toupper(int c);
static int	ft_isspace(int c);

int	main(int argc, char **argv)
{
	int	index;

	if (argc < 0x2)
		write(STDOUT_FILENO, "\n", sizeof(char));
	else
	{
		index = 0x1;
		while (index < argc)
		{
			ft_str_capitalizer(argv[index]);
			write(STDOUT_FILENO, "\n", sizeof(char));
			index++;
		}
	}
	return (EXIT_SUCCESS);
}

static void	ft_str_capitalizer(char *str)
{
	char	*last;
	char	*first;

	first = str;
	while (*str)
	{
		while (*str && !ft_isspace(*str))
		{
			last = str;
			*str = ft_tolower(*str);
			str++;
		}
		if (ft_isspace(*str) || (*str) == 0)
			*last = ft_toupper(*last);
		if (*str)
			str++;
	}
	while (*first)
		write(1, &(*first++), 1);
}

static int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += ('a' - 'A');
	return (c);
}

static int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c -= ('a' - 'A');
	return (c);
}

static int	ft_isspace(int c)
{
	return ((c == ' ') || ((c >= '\t') && (c <= '\r')));
}
