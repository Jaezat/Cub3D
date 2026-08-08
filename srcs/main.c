/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:41:42 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/08 02:44:20 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parsing(argc, argv);
	game(data);
	if (data)
		free_data(data);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_data	*data;
// 	bool	parse_only;

// 	parse_only = (argc == 3 && ft_strncmp(argv[1], "--parse-only", 13) == 0);
// 	if (parse_only)
// 	{
// 		argc--;
// 		argv++;
// 	}
// 	data = parsing(argc, argv);
// 	if (parse_only)
// 	{
// 		free_data(data);
// 		return (0);
// 	}
// 	game(data);
// 	if (data)
// 		free_data(data);
// 	return (0);
// }
