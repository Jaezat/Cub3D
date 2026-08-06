/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:41:14 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:41:15 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	safe_init(t_parser *p)
{
	ft_bzero(p, sizeof(t_parser));
	p->map_fd = -1;
}

void	ft_safe_close(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (false);
}
