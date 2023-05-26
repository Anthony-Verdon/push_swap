/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:26:59 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 19:20:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	launch_move_next_next_next(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*output;

	output = NULL;
	if (ft_strncmp((char *)((*instructions)->content), "pa", 2) == 0)
	{
		if (!(*head_b))
			return (1);
		call_pa(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	else if (ft_strncmp((char *)((*instructions)->content), "pb", 2) == 0)
	{
		if (!(*head_a))
			return (1);
		call_pb(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	else
	{
		ft_double_lstdelone(output, del);
		return (0);
	}
}

int	launch_move_next_next(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*output;

	output = NULL;
	if (ft_strncmp((char *)((*instructions)->content), "ra", 2) == 0)
	{
		if (!(*head_a))
			return (1);
		call_ra(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	else if (ft_strncmp((char *)((*instructions)->content), "rb", 2) == 0)
	{
		if (!(*head_b))
			return (1);
		call_rb(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	ft_double_lstdelone(output, del);
	if (ft_strncmp((char *)((*instructions)->content), "rr", 2) == 0)
		return (launch_rr(head_a, head_b));
	else
		return (launch_move_next_next_next(head_a, head_b, instructions));
}

int	launch_move_next(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*output;

	output = NULL;
	if (ft_strncmp((char *)((*instructions)->content), "rra", 3) == 0)
	{
		if (!(*head_a))
			return (1);
		call_rra(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	else if (ft_strncmp((char *)((*instructions)->content), "rrb", 3) == 0)
	{
		if (!(*head_b))
			return (1);
		call_rrb(head_a, head_b, NULL);
		ft_double_lstdelone(output, del);
		return (0);
	}
	ft_double_lstdelone(output, del);
	if (ft_strncmp((char *)((*instructions)->content), "rrr", 3) == 0)
		return (launch_rrr(head_a, head_b));
	else
		return (launch_move_next_next(head_a, head_b, instructions));
}

int	launch_move(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*output;

	output = NULL;
	if (ft_strncmp((char *)((*instructions)->content), "sa", 2) == 0)
	{
		if (!(*head_a) || !(*head_a)->next)
			return (1);
		call_sa(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	else if (ft_strncmp((char *)((*instructions)->content), "sb", 2) == 0)
	{
		if (!(*head_b) || !(*head_b)->next)
			return (1);
		call_sb(head_a, head_b, &output);
		ft_double_lstdelone(output, del);
		return (0);
	}
	ft_double_lstdelone(output, del);
	if (ft_strncmp((char *)((*instructions)->content), "ss", 2) == 0)
		return (launch_ss(head_a, head_b));
	else
		return (launch_move_next(head_a, head_b, instructions));
}
