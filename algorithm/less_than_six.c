/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:20:48 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:48:48 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	for_two(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (ft_atoi((*head_a)->content) > ft_atoi((*head_a)->next->content))
		call_sa(head_a, head_b, instructions);
}

void	for_three(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	min_a;
	int	max_a;

	if (!list_sorted(head_a))
	{
		min_a = search_min(*head_a);
		max_a = search_max(*head_a);
		if (min_a == ft_atoi((char *)(ft_double_lstlast(*head_a)->content))
				&& max_a == ft_atoi((char *)((*head_a)->content)))
		{
			call_sa(head_a, head_b, instructions);
			call_rra(head_a, head_b, instructions);
		}
		else
		{
			call_rotate_a(head_a, head_b, instructions, min_a);
			call_pb(head_a, head_b, instructions);
			for_two(head_a, head_b, instructions);
			call_pa(head_a, head_b, instructions);
		}
	}
}

void	for_four(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	min_a;

	if (!list_sorted(head_a))
	{
		min_a = search_min(*head_a);
		call_rotate_a(head_a, head_b, instructions, min_a);
		call_pb(head_a, head_b, instructions);
		min_a = search_min(*head_a);
		call_rotate_a(head_a, head_b, instructions, min_a);
		call_pb(head_a, head_b, instructions);
		for_two(head_a, head_b, instructions);
		call_pa(head_a, head_b, instructions);
		call_pa(head_a, head_b, instructions);
	}
}

void	for_five(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	min_a;

	if (!list_sorted(head_a))
	{
		min_a = search_min(*head_a);
		call_rotate_a(head_a, head_b, instructions, min_a);
		call_pb(head_a, head_b, instructions);
		for_four(head_a, head_b, instructions);
		call_pa(head_a, head_b, instructions);
	}
}

void	less_than_six(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (calculate_len_stack(head_a) == 2)
		for_two(head_a, head_b, instructions);
	if (calculate_len_stack(head_a) == 3)
		for_three(head_a, head_b, instructions);
	if (calculate_len_stack(head_a) == 4)
		for_four(head_a, head_b, instructions);
	if (calculate_len_stack(head_a) == 5)
		for_five(head_a, head_b, instructions);
}
