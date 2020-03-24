/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers_edit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewis <lewis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:47:46 by lbonnete          #+#    #+#             */
/*   Updated: 2020/03/24 17:06:38 by lewis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem_edit.h"

int		dealers_edit(t_var *info,t_map *map, t_input_edit *input_edit)
{
	SDL_Event		event;

	(void)info;
	(void)input_edit;
	if (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT)
			return (0);
		if (event.key.keysym.sym == SDLK_ESCAPE && event.type == SDL_KEYDOWN)
			return (0);
		if(event.type == SDL_MOUSEMOTION)
		{
			input_edit->mouse_x = event.button.x;
			input_edit->mouse_x = event.button.x;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				input_edit->left_click = 1;
			if (event.button.button == SDL_BUTTON_RIGHT)
				input_edit->right_click = 1;
		}
		if(event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				input_edit->left_click = 0;
			if (event.button.button == SDL_BUTTON_RIGHT)
				input_edit->right_click = 0;
		}
		if (event.key.keysym.sym == SDLK_d)
		{
			if (event.key.state == SDL_PRESSED)
				del_sector(info, map);
		}
		if (event.key.keysym.sym == SDLK_s)
		{
			if (event.key.state == SDL_PRESSED)
				create_sector(info, map);
		}
		if (event.key.keysym.sym == SDLK_p)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_p = 1;
			else
				input_edit->t_p = 0;
		}
		if (event.key.keysym.sym == SDLK_y)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_y = 1;
			else
				input_edit->t_y = 0;
		}
		if (event.key.keysym.sym == SDLK_n)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_n = 1;
			else
				input_edit->t_n = 0;
		}
		if (event.key.keysym.sym == SDLK_0)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_0 = 1;
			else
				input_edit->t_0 = 0;
		}
		if (event.key.keysym.sym == SDLK_1)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_1 = 1;
			else
				input_edit->t_1 = 0;
		}
		if (event.key.keysym.sym == SDLK_2)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_2 = 1;
			else
				input_edit->t_2 = 0;
		}
		if (event.key.keysym.sym == SDLK_3)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_3 = 1;
			else
				input_edit->t_3 = 0;
		}
		if (event.key.keysym.sym == SDLK_4)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_4 = 1;
			else
				input_edit->t_4 = 0;
		}
		if (event.key.keysym.sym == SDLK_5)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_5 = 1;
			else
				input_edit->t_5 = 0;
		}
		if (event.key.keysym.sym == SDLK_6)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_6 = 1;
			else
				input_edit->t_6 = 0;
		}
		if (event.key.keysym.sym == SDLK_7)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_7 = 1;
			else
				input_edit->t_7 = 0;
		}
		if (event.key.keysym.sym == SDLK_8)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_8 = 1;
			else
				input_edit->t_8 = 0;
		}
		if (event.key.keysym.sym == SDLK_9)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_9 = 1;
			else
				input_edit->t_9 = 0;
		}
		if (event.key.keysym.sym == SDLK_p)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_p = 1;
			else
				input_edit->t_p = 0;
		}
		if (event.key.keysym.sym == SDLK_p)
		{
			if (event.key.state == SDL_PRESSED)
				input_edit->t_p = 1;
			else
				input_edit->t_p = 0;
		}
	}
	return (1);

}
void		dealers_init(t_input_edit *input_edit)
{
	input_edit->mouse_x = 0;
	input_edit->mouse_y = 0;
	input_edit->right_click = 0;
	input_edit->left_click = 0;
	input_edit->del = 0;
	input_edit->t_s = 0;
	input_edit->t_p = 0;
	input_edit->t_y = 0;
	input_edit->t_n = 0;
	input_edit->t_0 = 0;
	input_edit->t_1 = 0;
	input_edit->t_2 = 0;
	input_edit->t_3 = 0;
	input_edit->t_4 = 0;
	input_edit->t_5 = 0;
	input_edit->t_6 = 0;
	input_edit->t_7 = 0;
	input_edit->t_8 = 0;
	input_edit->t_9 = 0;
}
void		dealers_tester(t_input_edit input_edit)
{
	if (input_edit.right_click)
		ft_putendl("right_click");
	if (input_edit.left_click)
		ft_putendl("left_click");
	if (input_edit.del)
		ft_putendl("del");
	if (input_edit.t_s)
		ft_putendl("t_s");
	if (input_edit.t_p)
		ft_putendl("t_p");
	if (input_edit.t_y)
		ft_putendl("t_y");
	if (input_edit.t_n)
		ft_putendl("t_n");
	if (input_edit.t_0)
		ft_putendl("t_0");
	if (input_edit.t_1)
		ft_putendl("t_1");
	if (input_edit.t_2)
		ft_putendl("t_2");
	if (input_edit.t_3)
		ft_putendl("t_3");
	if (input_edit.t_4)
		ft_putendl("t_4");
	if (input_edit.t_5)
		ft_putendl("t_5");
	if (input_edit.t_6)
		ft_putendl("t_6");
	if (input_edit.t_7)
		ft_putendl("t_7");
	if (input_edit.t_8)
		ft_putendl("t_8");
	if (input_edit.t_9)
		ft_putendl("t_9");
}