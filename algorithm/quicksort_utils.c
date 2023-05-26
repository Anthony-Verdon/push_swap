/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:16:37 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 15:58:49 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	calculate_len_stack(t_double_list **head_a)
{
	t_double_list	*buffer;
	int				len_stack;

	buffer = *head_a;
	len_stack = 0;
	while (buffer)
	{
		len_stack++;
		buffer = buffer->next;
	}
	return (len_stack);
}

int	calculate_median(t_double_list **head_a_sorted, int nb_pivot)
{
	t_double_list	*buffer;
	int				median;
	int				length;
	int				length2;

	buffer = *head_a_sorted;
	length = calculate_len_stack(head_a_sorted);
	length2 = 0;
	while (buffer)
	{
		if ((((length / 10) + 15) * nb_pivot) >= length)
			median = search_max(*head_a_sorted);
		else if (length2 == ((length / 10) + 15) * nb_pivot)
			median = ft_atoi(buffer->content);
		buffer = buffer->next;
		length2++;
	}
	return (median);
}

int	check_quicksort(t_double_list **head_a, int median)
{
	t_double_list	*temp;

	if (!(*head_a))
		return (0);
	temp = *head_a;
	while (temp)
	{
		if (ft_atoi(temp->content) <= median)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_double_list	*copy_a(t_double_list **head_a)
{
	t_double_list	*buffer;
	char			*temp_content;
	t_double_list	*temp1;
	t_double_list	*temp2;

	buffer = *head_a;
	if (!buffer)
		return (NULL);
	temp1 = NULL;
	while (buffer)
	{
		temp_content = ft_strdup(buffer->content);
		if (!temp_content)
			return (NULL);
		temp2 = ft_double_lstnew(temp_content);
		if (!temp2)
			return (NULL);
		ft_double_lstadd_back(&temp1, temp2);
		buffer = buffer->next;
	}
	return (temp1);
}

t_double_list	*sort_a(t_double_list **head_a)
{
	t_double_list	*temp1;
	t_double_list	*temp2;
	t_double_list	*buffer;
	char			*temp_content;

	buffer = copy_a(head_a);
	temp1 = buffer;
	while (buffer)
	{
		temp2 = temp1;
		while (temp2 && temp2->next)
		{
			if (ft_atoi(temp2->content) > ft_atoi(temp2->next->content))
			{
				temp_content = (char *)temp2->content;
				temp2->content = temp2->next->content;
				temp2->next->content = temp_content;
			}
			temp2 = temp2->next;
		}
		buffer = buffer->next;
	}
	return (temp1);
}
