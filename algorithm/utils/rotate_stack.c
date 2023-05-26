/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:21:39 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:49:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../push_swap.h"

int	place_min(t_double_list **head, int min)
{
	int				index;
	int				end;
	t_double_list	*temp;

	end = 0;
	temp = *head;
	while (temp)
	{
		if (ft_atoi(temp->content) == min)
			index = end;
		end++;
		temp = temp->next;
	}
	if (index <= end / 2)
		return (0);
	else
		return (1);
}

int	place_first_min(t_double_list **head, int pivot)
{
	int				index;
	int				memory;
	int				end;
	t_double_list	*temp;

	end = 0;
	temp = *head;
	memory = 1;
	while (temp)
	{
		if (ft_atoi(temp->content) <= pivot && memory)
		{
			index = end;
			memory = 0;
		}
		end++;
		temp = temp->next;
	}
	if (index <= end / 2)
		return (0);
	else
		return (1);
}

int	rotate_b(t_double_list **head_b, int min_b, t_double_list **instructions)
{
	int	operation_value;

	if (place_min(head_b, min_b) == 0)
	{
		while (ft_atoi((char *)(*head_b)->content) != min_b)
		{
			operation_value = rb(head_b, instructions);
			if (operation_value)
				return (1);
		}
	}
	else
	{
		while (ft_atoi((char *)(*head_b)->content) != min_b)
		{
			operation_value = rrb(head_b, instructions);
			if (operation_value)
				return (1);
		}
	}
	return (0);
}

int	rotate_a(t_double_list **head_a, int min_a, t_double_list **instructions)
{
	int	operation_value;

	if (place_min(head_a, min_a) == 0)
	{
		while (ft_atoi((char *)(*head_a)->content) != min_a)
		{
			operation_value = ra(head_a, instructions);
			if (operation_value)
				return (1);
		}
	}
	else
	{
		while (ft_atoi((char *)(*head_a)->content) != min_a)
		{
			operation_value = rra(head_a, instructions);
			if (operation_value)
				return (1);
		}
	}
	return (0);
}

int	rotate_a_for_quicksort(t_double_list **head_a, int min_a,
		t_double_list **instructions)
{
	int	operation_value;

	if (place_first_min(head_a, min_a) == 0)
	{
		while (ft_atoi((char *)(*head_a)->content) > min_a)
		{
			operation_value = ra(head_a, instructions);
			if (operation_value)
				return (1);
		}
	}
	else
	{
		while (ft_atoi((char *)(*head_a)->content) > min_a)
		{
			operation_value = rra(head_a, instructions);
			if (operation_value)
				return (1);
		}
	}
	return (0);
}
