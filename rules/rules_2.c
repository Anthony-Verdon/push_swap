/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:04:49 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:58:00 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	rrb(t_double_list **head, t_double_list **instructions)
{
	t_double_list	*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head)
		return (0);
	temp = ft_double_lstlast(*head);
	if (!temp->previous)
		return (0);
	temp->previous->next = NULL;
	ft_double_lstadd_front(head, temp);
	temp_content = ft_strdup("rrb");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	pa(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*temp_a;
	t_double_list	*temp_b;
	t_double_list	*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head_b)
		return (0);
	temp_b = *head_b;
	temp_a = ft_double_lstnew(ft_strdup(temp_b->content));
	ft_double_lstadd_front(head_a, temp_a);
	temp = temp_b->next;
	ft_double_lstdelone(temp_b, &del);
	*head_b = temp;
	temp_b = temp;
	temp_content = ft_strdup("pa");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	pb(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*temp_a;
	t_double_list	*temp_b;
	t_double_list	*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head_a)
		return (0);
	temp_a = *head_a;
	temp_b = ft_double_lstnew(ft_strdup(temp_a->content));
	ft_double_lstadd_front(head_b, temp_b);
	temp = temp_a->next;
	ft_double_lstdelone(temp_a, &del);
	*head_a = temp;
	temp_a = temp;
	temp_content = ft_strdup("pb");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	rr(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (*head_a)
		call_ra(head_a, head_b, instructions);
	if (*head_b)
		call_rb(head_a, head_b, instructions);
	return (0);
}

int	rrr(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (*head_a)
		call_rra(head_a, head_b, instructions);
	if (*head_b)
		call_rrb(head_a, head_b, instructions);
	return (0);
}
