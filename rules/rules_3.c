/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:57:13 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:57:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (*head_a)
		call_sa(head_a, head_b, instructions);
	if (*head_b)
		call_sb(head_a, head_b, instructions);
	return (0);
}
