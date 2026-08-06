/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:40:22 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:40:23 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	it_power_two(int num)
{
	if (num <= 0)
		return (false);
	if (num == 2)
		return (true);
	while (!(num % 2))
	{
		num /= 2;
		if (num == 2)
			return (true);
	}
	return (false);
}
