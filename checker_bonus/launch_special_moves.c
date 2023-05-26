/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_special_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:10:17 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 19:19:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	launch_ss(t_double_list **head_a, t_double_list **head_b)
{
	t_double_list	*output;

	output = NULL;
	if ((!(*head_a) || !(*head_a)->next)
		&& (!(*head_b) || !(*head_b)->next))
		return (1);
	else if (!(*head_a) || !(*head_a)->next)
		call_sb(head_a, head_b, &output);
	else if (!(*head_b) || !(*head_b)->next)
		call_sa(head_a, head_b, &output);
	else
	{
		call_sa(head_a, head_b, &output);
		call_sb(head_a, head_b, &output);
	}
	ft_double_lstdelone(output, del);
	return (0);
}

int	launch_rr(t_double_list **head_a, t_double_list **head_b)
{
	t_double_list	*output;

	output = NULL;
	if (!(*head_a) && !(*head_b))
		return (1);
	else if (!(*head_a))
		call_rb(head_a, head_b, &output);
	else if (!(*head_b))
		call_ra(head_a, head_b, &output);
	else
	{
		call_ra(head_a, head_b, &output);
		call_rb(head_a, head_b, &output);
	}
	ft_double_lstdelone(output, del);
	return (0);
}

int	launch_rrr(t_double_list **head_a, t_double_list **head_b)
{
	t_double_list	*output;

	output = NULL;
	if (!(*head_a) && !(*head_b))
		return (1);
	else if (!(*head_a))
		call_rrb(head_a, head_b, &output);
	else if (!(*head_b))
		call_rra(head_a, head_b, &output);
	else
	{
		call_rra(head_a, head_b, &output);
		call_rrb(head_a, head_b, &output);
	}
	ft_double_lstdelone(output, del);
	return (0);
}
