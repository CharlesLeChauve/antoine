/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:14:45 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 16:29:51 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*find_smallest_bigger_node(t_lst **lst, t_lst *node)
{
	t_lst	*current;
	t_lst	*smallest_bigger_node;
	int		max;

	current = *lst;
	smallest_bigger_node = current;
	max = INT_MAX;
	while (current)
	{
		if (current->nb > node->nb && current->nb < max)
		{
			max = current->nb;
			smallest_bigger_node = current;
		}
		current = current->next;
	}
	if (max == INT_MAX)
		return (find_lowest_node(lst));
	return (smallest_bigger_node);
}

t_lst	*find_highest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*highest_node;

	current = *lst;
	highest_node = current;
	while (current)
	{
		if (current->nb > highest_node->nb)
			highest_node = current;
		current = current->next;
	}
	return (highest_node);
}

t_lst	*find_lowest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*lowest_node;

	current = *lst;
	lowest_node = *lst;
	while (current)
	{
		if (current->nb < lowest_node->nb)
			lowest_node = current;
		current = current->next;
	}
	return (lowest_node);
}

void	find_target(t_ab *ab)
{
	t_lst	*aux;

	aux = ab->lst_b;
	while (aux)
	{
		aux->target = find_smallest_bigger_node(&ab->lst_a, aux);
		aux = aux->next;
	}
}

t_lst	*find_lowest_cost(t_lst **lst)
{
	t_lst	*aux;
	t_lst	*lowest;

	aux = *lst;
	lowest = *lst;
	while (aux)
	{
		if (aux->total_cost < lowest->total_cost)
			lowest = aux;
		aux = aux->next;
	}
	return (lowest);
}

int	find_total_cost(t_lst *target_a, t_lst *target_b, t_ab *ab)
{
	int	dir_a;
	int	dir_b;
	int	cost;

	if (target_a->index > lst_size(ab->lst_a) / 2)
		dir_a = -1;
	else
		dir_a = 1;
	if (target_b->index > lst_size(ab->lst_b) / 2)
		dir_b = -1;
	else
		dir_b = 1;
	if (dir_a == dir_b)
	{
		if (target_a->cost > target_b->cost)
			cost = target_a->cost;
		else
			cost = target_b->cost;
	}
	else
		cost = target_a->cost + target_b->cost;
	return (cost);
}

