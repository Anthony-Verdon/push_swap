/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:21:03 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:49:08 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../push_swap.h"

int	search_min(t_double_list *head)
{
	int				min;
	int				value_temp;
	t_double_list	*temp;

	temp = head;
	min = ft_atoi((char *)temp->content);
	while (temp)
	{
		value_temp = ft_atoi(temp->content);
		if (min > value_temp)
		{	
			min = value_temp;
		}
		temp = temp->next;
	}
	return (min);
}

int	search_max(t_double_list *head)
{
	int				max;
	int				value_temp;
	t_double_list	*temp;

	temp = head;
	max = ft_atoi((char *)temp->content);
	while (temp)
	{
		value_temp = ft_atoi(temp->content);
		if (max < value_temp)
		{	
			max = value_temp;
		}
		temp = temp->next;
	}
	return (max);
}

int	search_before_max(t_double_list *head)
{
	int				max;
	int				before_max;
	int				value_temp;
	t_double_list	*temp;

	temp = head;
	max = search_max(head);
	before_max = ft_atoi((char *)temp->content);
	while (temp)
	{
		value_temp = ft_atoi(temp->content);
		if (before_max < value_temp && value_temp < max)
			before_max = value_temp;
		temp = temp->next;
	}
	return (before_max);
}

int	search_after_min(t_double_list *head)
{
	int				min;
	int				after_min;
	int				value_temp;
	t_double_list	*temp;

	temp = head;
	min = search_min(head);
	after_min = ft_atoi((char *)temp->content);
	while (temp)
	{
		value_temp = ft_atoi(temp->content);
		if (after_min > value_temp && value_temp > min)
			after_min = value_temp;
		temp = temp->next;
	}
	return (after_min);
}
