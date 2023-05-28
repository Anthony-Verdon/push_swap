/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:54:45 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 15:37:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	kill_program(t_double_list **head_a, t_double_list **head_b,
		t_double_list **instructions)
{
	if (head_a)
		ft_double_lstclear(head_a, &del);
	if (head_b)
		ft_double_lstclear(head_b, &del);
	if (instructions)
		ft_double_lstclear(instructions, &del);
	write(2, "Error\n", 6);
	exit (0);
}

void	complete_list(char **tab, t_double_list **head_a)
{
	int				i;
	char			*check_overflow_value;
	t_double_list	*temp_a;

	i = 1;
	while (tab[i])
	{
		check_overflow_value = ft_itoa(ft_atoi(tab[i]));
		if (ft_strcmp_modified(check_overflow_value, tab[i]) != 0
			|| check_duplicate_value(head_a, tab[i]) != 0
			|| !is_valid_atoi(tab[i]))
		{
			free(check_overflow_value);
			free_tab(tab);
			kill_program(head_a, NULL, NULL);
		}
		free(check_overflow_value);
		temp_a = ft_double_lstnew(ft_strdup(tab[i]));
		ft_double_lstadd_back(head_a, temp_a);
		i++;
	}
}

t_double_list	*parsing(int argc, char **argv)
{
	char			*check_overflow_value;
	char			**tab;
	t_double_list	*head_a;

	tab = create_tab(argc, argv);
	if (!tab)
	{
		free_tab(tab);
		write(2, "Error\n", 6);
		exit(0);
	}
	check_overflow_value = ft_itoa(ft_atoi(tab[0]));
	head_a = NULL;
	if (ft_strcmp_modified(check_overflow_value, tab[0]) != 0
		|| !is_valid_atoi(tab[0]))
	{
		free(check_overflow_value);
		free_tab(tab);
		kill_program(&head_a, NULL, NULL);
	}
	free(check_overflow_value);
	head_a = ft_double_lstnew(ft_strdup(tab[0]));
	complete_list(tab, &head_a);
	free_tab(tab);
	return (head_a);
}
