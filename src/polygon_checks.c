/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:47:46 by lbonnete          #+#    #+#             */
/*   Updated: 2020/06/30 17:58:57 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		check_convexity(t_sector *sector)
{
	t_wall	*walls;
	int 	a;
	int 	b;
	int 	c;
	float 	produit;
	int		got_negative;
	int		got_positive;

	walls = sector->walls;
	a = 0;
	got_negative = 0;
	got_positive = 0;
	while (a < sector->nbr_walls)
	{
		b = (a + 1) % sector->nbr_walls;
		c = (b + 1) % sector->nbr_walls;
		produit = cross_product(walls[a].a, walls[b].a, walls[c].a);
		if (produit < 0)
        {
            got_negative = 1;
        }
        else if (produit > 0)
            got_positive = 1;
        if (got_negative && got_positive)
			return (0);
		a++;
	}
	return (1);
}

int		check_surrounding(t_sector *sector)
{
	t_sector *current_sector;
	int i;

	i = 0;
	current_sector = sector->map->sectors;
	while (current_sector)
	{
		if (current_sector->sector_id != sector->sector_id)
		{
			while (i < current_sector->nbr_walls)
			{
				if (!is_in_sector(current_sector->walls[i].a, sector))
					return (0);
				i++;
			}
			i = 0;
		}
		current_sector = current_sector->next_sector;
	} 
	return (1);
}

int		check_self_intersection(t_sector *sector)
{
	int i;
	int	j;

	i = 0;
	while (i < sector->nbr_walls)
	{
		j = 0;
		while (j < sector->nbr_walls)
		{
			if (j != i && sector->walls[i].a.x > 0 && sector->walls[i].b.x > 0 && sector->walls[j].a.x > 0 && sector->walls[j].b.x > 0)
			{
				if(!check_wall_intersections(sector->walls[i].a, sector->walls[i].b, sector->walls[j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int 	pnpoly(int nbr_walls, t_wall *walls, t_point first)
{
	int i;
	int j;
	int c;

	i = 0;
	j = nbr_walls - 1;
	c = 0;
	while (i < nbr_walls)
	{
		if (!is_new_point_in_sector(first, walls))
			return(0);
		if (((walls[i].a.y > first.y) != (walls[j].a.y > first.y)) && (first.x < (walls[j].a.x - walls[i].a.x) * (first.y - walls[i].a.y) / (walls[j].a.y - walls[i].a.y) + walls[i].a.x))
			c = !c;
		j = i++;
	}
	return (c);
}

int		is_in_sector(t_point first,t_sector *sector)
{
	if (pnpoly(sector->nbr_walls, sector->walls, first))
	{
		return (0);
	}
	return (1);
}

int		is_in_sectors(t_point first,t_map *map)
{
	t_sector *current_sector;

	current_sector = map->sectors;
	while (current_sector->next_sector)
	{
		if(!is_in_sector(first, current_sector))
			return(0);
		current_sector = current_sector->next_sector;
	}
	return (1);
}

int		player_sec(t_sector *sector, t_var *info)
{
	if (pnpoly_float(sector->nbr_walls, sector->walls, info->player->posx, info->player->posy))
	{
		return (sector->sector_id);
	}
	else if (sector->next_sector)
		return(player_sec(sector->next_sector, info));
	return (-1);
}

// int		player_sec(t_render *render, t_var *info)
// {
// 	render->s = render->sec_0;
// 	while (render->s)
// 	{
// 		if (pnpoly_float(render->s->nbr_walls, render->s->walls, info->player->posx, info->player->posy))
// 			return (render->s->sector_id);
// 		render->s = render->s->next_sector;
// 	}
// 	return (0);
// }

int 	pnpoly_spawn(int nbr_walls, t_wall *walls, t_point first)
{
	int i;
	int j;
	int c;

	i = 0;
	j = nbr_walls - 1;
	c = 0;
	while (i < nbr_walls)
	{
		if (!is_new_point_in_sector(first, walls))
			return(0);
		if (((walls[i].a.y >= first.y) != (walls[j].a.y >= first.y)) && (first.x <= (walls[j].a.x - walls[i].a.x) * (first.y - walls[i].a.y) / (walls[j].a.y - walls[i].a.y) + walls[i].a.x))
			c = !c;
		j = i++;
	}
	return (c);
}

int		is_in_sector_spawn(t_point first,t_sector *sector)
{
	if (pnpoly_spawn(sector->nbr_walls, sector->walls, first))
	{
		sector->map->spawn.z = sector->walls[0].d.z;
		//sector->map->spawn_sector_id = sector->sector_id;
		return (1);
	}
	return (0);
}

int		is_in_sectors_spawn(t_point first,t_map *map)
{
	t_sector *current_sector;

	current_sector = map->sectors;
	while (current_sector)
	{
		if(is_in_sector_spawn(first, current_sector))
			return (current_sector->sector_id);
		current_sector = current_sector->next_sector;
	}
	return (0);
}