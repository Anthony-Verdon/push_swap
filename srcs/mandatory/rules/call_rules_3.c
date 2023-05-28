/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rules_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:38:52 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:50:05 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	call_rotate_b(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions, int value)
{
	int	operation_value;

	operation_value = rotate_b(head_b, value, instructions);
	if (operation_value)
		kill_program(head_a, head_b, instructions);
}
