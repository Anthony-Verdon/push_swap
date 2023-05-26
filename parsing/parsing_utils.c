/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:43:09 by averdon           #+#    #+#             */
/*   Updated: 2022/11/25 16:49:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	pass_one_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			break ;
		i++;
	}
	return (i);
}

int	advance_in_str(char	*str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	i += pass_one_char(&str[i], ' ');
	i += pass_one_char(&str[i], '+');
	if (str[i] == '-')
		minus = 1;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
		{
			if (minus)
			{
			str[i - 1] = '-';
			i--;
			}
			break ;
		}
		i++;
	}
	return (i);
}

int	is_valid_atoi(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '+' && str[i] != '-'
			&& str[i] != ' ' && str[i] <= '0' && str[i] >= '9' )
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp_modified(char *s1, char *s2)
{
	int	i;
	int	j;
	int	y;
	int	len;

	i = advance_in_str(s1);
	j = advance_in_str(s2);
	y = 0;
	while ((unsigned char)s1[i + y] == (unsigned char)s2[j + y]
		&& (unsigned char)s1[i + y] && (unsigned char)s2[j + y])
		y++;
	if (y == 0)
	{
		if (ft_strlen(s1) > ft_strlen(s2))
			len = ft_strlen(s1);
		else
			len = ft_strlen(s2);
		return (ft_strncmp(s1, s2, len));
	}
	return ((unsigned char)s1[i + y] - (unsigned char)s2[j + y]);
}

int	check_duplicate_value(t_double_list **head_a, char *new_elt)
{
	t_double_list	*temp;

	temp = *head_a;
	while (temp)
	{
		if (ft_strcmp_modified((char *)temp->content, new_elt) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}
