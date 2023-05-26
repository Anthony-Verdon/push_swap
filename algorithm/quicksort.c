/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:14:20 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 15:58:02 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	calculate_sub_pivot(t_double_list **head_a)
{
	int				len_chunk;
	int				length;
	int				sub_pivot;
	t_double_list	*buffer;
	t_double_list	*start_buffer;

	length = calculate_len_stack(head_a);
	len_chunk = (length / 10) + 15;
	buffer = sort_a(head_a);
	start_buffer = buffer;
	if (length < len_chunk / 2)
		len_chunk = length;
	length = 0;
	while (buffer)
	{
		if (length == len_chunk / 2)
			sub_pivot = ft_atoi(buffer->content);
		length++;
		buffer = buffer->next;
	}
	ft_double_lstclear(&start_buffer, &del);
	return (sub_pivot);
}

t_double_list	*create_list_pivot(t_double_list **head_a_sorted, int nb_chunk)
{
	t_double_list	*pivot;
	int				median;	
	char			*str;
	int				nb_pivot;

	pivot = NULL;
	nb_pivot = 1;
	while (nb_pivot < nb_chunk + 1)
	{
		median = calculate_median(head_a_sorted, nb_pivot);
		str = ft_itoa(median);
		ft_double_lstadd_back(&pivot, ft_double_lstnew(ft_strdup(str)));
		free(str);
		nb_pivot++;
	}
	return (pivot);
}

t_double_list	*set_up_list_pivot(t_double_list **head_a)
{
	t_double_list	*head_a_sorted;
	int				len_stack;
	t_double_list	*pivot;
	int				nb_chunk;

	head_a_sorted = sort_a(head_a);
	if (!head_a_sorted)
		return (NULL);
	len_stack = calculate_len_stack(head_a);
	nb_chunk = len_stack / ((len_stack / 10) + 15);
	if ((len_stack % ((len_stack / 10) + 15)) > 0)
		nb_chunk += 1;
	pivot = create_list_pivot(&head_a_sorted, nb_chunk);
	ft_double_lstclear(&head_a_sorted, &del);
	return (pivot);
}

void	place_in_b(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions, int sub_pivot)
{
	call_pb(head_a, head_b, instructions);
	if (ft_atoi((*head_b)->content) <= sub_pivot)
	{
		if ((*head_b)->next)
			call_rb(head_a, head_b, instructions);
	}
}

void	quicksort(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	t_double_list	*pivot;
	t_double_list	*start_pivot;
	int				sub_pivot;

	pivot = set_up_list_pivot(head_a);
	if (!pivot)
		kill_program(head_a, head_b, instructions);
	start_pivot = pivot;
	while (pivot)
	{
		sub_pivot = calculate_sub_pivot(head_a);
		while (check_quicksort(head_a, ft_atoi(pivot->content)))
		{
			if (ft_atoi((*head_a)->content) <= ft_atoi(pivot->content))
				place_in_b(head_a, head_b, instructions, sub_pivot);
			else
				call_rotate_a_for_quicksort(head_a, head_b,
					instructions, ft_atoi(pivot->content));
		}
		pivot = pivot->next;
	}
	ft_double_lstclear(&start_pivot, &del);
}
