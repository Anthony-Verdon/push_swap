/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:21:25 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 21:20:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	nb_action_to_find(t_double_list **head, int num)
{
	int				nb_action;
	t_double_list	*temp;
	int				length;
	int				memory;

	memory = 0;
	length = 0;
	nb_action = 0;
	temp = *head;
	while (temp)
	{
		if (ft_atoi(temp->content) == num)
			memory = 1;
		if (memory == 0)
			nb_action++;
		temp = temp->next;
		length++;
	}
	if (nb_action > length / 2)
		return (length - nb_action);
	else
		return (nb_action);
}

void	switch_max_and_before(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	max_b;
	int	before_max_b;

	max_b = search_max(*head_b);
	before_max_b = search_before_max(*head_b);
	call_rotate_b(head_a, head_b, instructions, before_max_b);
	call_pa(head_a, head_b, instructions);
	call_rotate_b(head_a, head_b, instructions, max_b);
	call_pa(head_a, head_b, instructions);
	call_sa(head_a, head_b, instructions);
}

int	empty_b(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	max_b;
	int	before_max_b;
	int	nb_action_max_b;
	int	nb_action_before_max_b;

	while (*head_b)
	{
		max_b = search_max(*head_b);
		before_max_b = search_before_max(*head_b);
		nb_action_max_b = nb_action_to_find(head_b, max_b);
		nb_action_before_max_b = nb_action_to_find(head_b, before_max_b);
		if (max_b == before_max_b
			|| (nb_action_max_b <= nb_action_before_max_b))
		{
			call_rotate_b(head_a, head_b, instructions, max_b);
			call_pa(head_a, head_b, instructions);
		}
		else
			switch_max_and_before(head_a, head_b, instructions);
	}
	return (0);
}
