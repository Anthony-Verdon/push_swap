/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rules_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:39:48 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 18:53:32 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	call_rrb(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = rrb(head_b, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_pa(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = pa(head_a, head_b, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_pb(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = pb(head_a, head_b, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_rotate_a(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions, int value)
{
	int	operation_value;

	operation_value = rotate_a(head_a, value, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_rotate_a_for_quicksort(t_double_list **head_a,
		t_double_list **head_b, t_double_list **instructions, int value)
{
	int	operation_value;

	operation_value = rotate_a_for_quicksort(head_a, value, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}
