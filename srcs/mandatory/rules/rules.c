/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:20:49 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:50:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	sa(t_double_list **head, t_double_list **instructions)
{
	void			*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head)
		return (0);
	if (!(*head)->next)
		return (0);
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	temp_content = ft_strdup("sa");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	sb(t_double_list **head, t_double_list **instructions)
{
	void			*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head)
		return (0);
	temp = (*head)->content;
	if (!(*head)->next)
		return (0);
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	temp_content = ft_strdup("sb");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	ra(t_double_list **head, t_double_list **instructions)
{
	t_double_list	*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head)
		return (0);
	temp = *head;
	if (!(*head)->next)
		return (0);
	(*head) = (*head)->next;
	temp->next = NULL;
	ft_double_lstadd_back(head, temp);
	temp_content = ft_strdup("ra");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	rb(t_double_list **head, t_double_list **instructions)
{
	t_double_list	*temp;
	t_double_list	*new_elt;
	char			*temp_content;

	if (!*head)
		return (0);
	temp = *head;
	if (!(*head)->next)
		return (0);
	(*head) = (*head)->next;
	temp->next = NULL;
	ft_double_lstadd_back(head, temp);
	temp_content = ft_strdup("rb");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}

int	rra(t_double_list **head, t_double_list **instructions)
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
	temp_content = ft_strdup("rra");
	new_elt = ft_double_lstnew(temp_content);
	if (!temp_content || !new_elt)
		return (1);
	ft_double_lstadd_back(instructions, new_elt);
	return (0);
}
