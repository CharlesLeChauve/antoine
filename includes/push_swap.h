/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:52 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 16:17:49 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"
#include <limits.h>

typedef struct	s_lst
{
	int				nb;
	int				index;
	int				cost;
	int				total_cost;
	struct s_lst	*next;
	struct s_lst	*target;
}					t_lst;

typedef struct	s_ab
{
	t_lst			*lst_a;
	t_lst			*lst_b;
}					t_ab;



void	init(t_ab *ab);

void	split_argv(int ac, char **av, t_ab *ab);

void	lst_add_front(t_lst **lst, t_lst *new);
void	lst_add_back(t_lst **lst, t_lst *new_lst);
int		lst_size(t_lst *lst);
t_lst	*lst_new(int nb);
t_lst	*lst_last(t_lst *lst);
void	create_lst(t_ab *ab, int nb);
void	print_ab(t_ab *ab);

void	push(t_lst **src, t_lst **dst);
void	swap(t_lst **lst);
void	rotate(t_lst **lst);
void	reverse_rotate(t_lst **lst);

void	pa(t_ab *ab);
void	sa(t_ab *ab);
void	ra(t_ab *ab);
void	rra(t_ab *ab);

void	pb(t_ab *ab);
void	sb(t_ab *ab);
void	rb(t_ab *ab);
void	rrb(t_ab *ab);

void	rr(t_ab *ab);
void	rrr(t_ab *ab);
void	ss(t_ab *ab);

int		is_sorted(t_ab *ab);

t_lst	*find_highest_node(t_lst **lst);
t_lst	*find_lowest_node(t_lst **lst);
t_lst	*find_smallest_bigger_node(t_lst **lst, t_lst *node);
t_lst	*find_lowest_cost(t_lst **lst);
int	find_total_cost(t_lst *target_a, t_lst *target_b, t_ab *ab);
void	find_target(t_ab *ab);

void	set_index(t_ab *ab);
void	set_cost(t_ab *ab);

void	put_node_to_top_a(t_ab *ab, t_lst *target);
void	put_node_to_top_b(t_ab *ab);
void	rr_or_rrr(t_lst *target_a, t_lst *target_b, int flag, t_ab *ab);
void	double_rotation(t_ab *ab);

void	tiny_sort(t_lst **lst, t_ab *ab);
void	algorithm(t_ab *ab);

void	free_lst(t_ab *ab);
