/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:58:37 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 18:36:55 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_double_list	*create_instructions_list(t_double_list **head_a,
		t_double_list **head_b)
{
	t_double_list	*start_instructions;
	t_double_list	*new_elt;
	char			*str;

	str = get_next_line(0);
	start_instructions = NULL;
	if (check_valid_move(str))
	{
		free(str);
		kill_program(head_a, head_b, &start_instructions);
	}
	start_instructions = ft_double_lstnew(str);
	while (str)
	{
		str = get_next_line(0);
		if (check_valid_move(str))
		{
			free(str);
			kill_program(head_a, head_b, &start_instructions);
		}
		new_elt = ft_double_lstnew(str);
		ft_double_lstadd_back(&start_instructions, new_elt);
	}
	return (start_instructions);
}

void	execute_instructions(t_double_list **head_a, t_double_list **head_b,
		t_double_list **start_instructions)
{
	int				value_check;
	t_double_list	*instructions;

	instructions = *start_instructions;
	while (instructions && instructions->content)
	{
		value_check = launch_move(head_a, head_b, &instructions);
		if (value_check)
			break ;
		instructions = instructions->next;
	}
}

int	main(int argc, char	**argv)
{
	t_double_list	*head_a;
	t_double_list	*head_b;
	t_double_list	*start_instructions;

	if (argc == 1)
		return (1);
	head_a = parsing(argc, argv);
	if (list_sorted(&head_a))
	{
		ft_printf("OK\n");
		ft_double_lstclear(&head_a, del);
		exit(0);
	}
	head_b = NULL;
	start_instructions = create_instructions_list(&head_a, &head_b);
	execute_instructions(&head_a, &head_b, &start_instructions);
	if (list_sorted(&head_a) && !head_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_double_lstclear(&start_instructions, del);
	ft_double_lstclear(&head_a, del);
	ft_double_lstclear(&head_b, del);
}
