/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:04:28 by lewis             #+#    #+#             */
/*   Updated: 2020/07/09 11:15:33 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	check_map(char *the_map)
{
	int	i;

	i = 0;
	while (the_map[i])
	{
		if ((the_map[i] <= '9' && the_map[i] >= '0')
			|| (the_map[i] >= 'a' && the_map[i] <= 'z')
			|| (the_map[i] >= 'A' && the_map[i] <= 'Z'))
			++i;
		else
			return (0);
	}
	return (1);
}
