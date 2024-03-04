/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:40:52 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 16:20:21 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index(t_ab *ab)
{
	t_lst	*current;
	int		index;

	current = ab->lst_a;
	index = 0;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
	index = 0;
	current = ab->lst_b;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

void	set_cost_a(t_ab *ab)
{
	t_lst	*current;

	current = ab->lst_a;
	while (current)
	{
		if (current->index <= lst_size(ab->lst_a) / 2)
			current->cost = current->index;
		else
			current->cost = lst_size(ab->lst_a) - current->index;
		current = current->next;
	}
}

void	set_cost_b(t_ab *ab)
{
	t_lst	*current;

	current = ab->lst_b;
	while (current)
	{
		if (current->index <= lst_size(ab->lst_b) / 2)
			current->cost = current->index;
		else
			current->cost = lst_size(ab->lst_b) - current->index;
		current->total_cost = find_total_cost(current->target, current, ab);
		current = current->next;
	}
}

void	set_cost(t_ab *ab)
{
	set_cost_a(ab);
	set_cost_b(ab);
}
// void	set_cost(t_ab *ab)
// {
// 	t_lst	*current;

// 	current = ab->lst_b;
// 	while (current)
// 	{
// 		if (current->index <= lst_size(ab->lst_b) / 2)
// 		{
// 			if (current->target->index <= lst_size(ab->lst_a) / 2)
// 				current->target->cost = current->target->index;
// 			else
// 				current->target->cost
// 					= lst_size(ab->lst_a) - current->target->index;
// 			if ((current->index <= lst_size(ab->lst_b) / 2
// 					&& current->target->index <= lst_size(ab->lst_a) / 2)
// 				|| (current->index > lst_size(ab->lst_b) / 2
// 					&& current->target->index > lst_size(ab->lst_a) / 2))
// 			{
// 				if (current->cost <= current->target->cost)
// 					current->cost = current->target->cost;
// 			}
// 			else
// 				current->cost = current->cost + current->target->cost;
// 		}
// 		else
// 			current->cost = current->cost + current->target->cost;
// 		current = current->next;
// 		}
// }
