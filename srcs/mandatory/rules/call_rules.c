/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:44:24 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 19:07:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	call_sa(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = sa(head_a, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_sb(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = sb(head_b, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_ra(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = ra(head_a, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_rb(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = rb(head_b, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}

void	call_rra(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	int	operation_value;

	operation_value = rra(head_a, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}
