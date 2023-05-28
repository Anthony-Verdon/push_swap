/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:30:04 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 21:45:32 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	list_sorted(t_double_list **head)
{
	t_double_list	*temp;
	int				content_one;
	int				content_two;

	temp = *head;
	content_one = 0;
	content_two = 0;
	while (temp && temp->next)
	{
		content_one = ft_atoi((char *)temp->content);
		content_two = ft_atoi((char *)temp->next->content);
		if (content_one > content_two)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_instructions_that_follow(t_double_list *temp, char *first_instruction,
		char *second_instruction, char *displayed_instruction)
{
	int	len1;
	int	len2;
	int	count;

	len1 = ft_strlen(first_instruction);
	len2 = ft_strlen(second_instruction);
	count = 0;
	if (temp->next
		&& !ft_strncmp((char *)temp->content, first_instruction, len1)
		&& !ft_strncmp((char *)temp->next->content, second_instruction, len2))
		count++;
	if (temp->next
		&& !ft_strncmp((char *)temp->content, second_instruction, len2)
		&& !ft_strncmp((char *)temp->next->content, first_instruction, len1))
		count++;
	if (count != 0)
	{
		ft_printf("%s\n", displayed_instruction);
		return (1);
	}	
	return (0);
}

int	display_instructions(t_double_list **instructions)
{
	t_double_list	*temp;

	temp = *instructions;
	while (temp)
	{
		if (check_instructions_that_follow(temp, "ra", "rb", "rr"))
			temp = temp->next->next;
		else if (check_instructions_that_follow(temp, "rra", "rrb", "rrr"))
			temp = temp->next->next;
		else if (check_instructions_that_follow(temp, "sa", "sb", "ss"))
			temp = temp->next->next;
		else
		{
			ft_printf("%s\n", (char *)temp->content);
			temp = temp->next;
		}
	}
	return (0);
}

void	del(void *content)
{
	free(content);
	content = NULL;
}

int	main(int argc, char **argv)
{
	t_double_list	*head_a;
	t_double_list	*head_b;
	t_double_list	*instructions;

	if (argc == 1)
		exit(0);
	head_a = parsing(argc, argv);
	head_b = NULL;
	instructions = NULL;
	if (list_sorted(&head_a))
	{
		ft_double_lstclear(&head_a, del);
		exit(0);
	}
	if (calculate_len_stack(&head_a) <= 5)
		less_than_six(&head_a, &head_b, &instructions);
	else
	{
		quicksort(&head_a, &head_b, &instructions);
		empty_b(&head_a, &head_b, &instructions);
	}
	display_instructions(&instructions);
	ft_double_lstclear(&head_a, &del);
	ft_double_lstclear(&instructions, &del);
}
