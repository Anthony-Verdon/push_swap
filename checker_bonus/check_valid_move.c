/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:28:58 by averdon           #+#    #+#             */
/*   Updated: 2022/11/06 20:29:43 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	check_valid_move_next(char *new_elt)
{
	int				len;

	len = ft_strlen(new_elt);
	if (ft_strncmp(new_elt, "rra\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "rrb\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "rrr\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "pa\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "pb\n", len) == 0)
		return (0);
	return (1);
}

int	check_valid_move(char *new_elt)
{
	int				len;

	if (!new_elt)
		return (0);
	len = ft_strlen(new_elt);
	if (len > 4)
		return (1);
	else if (ft_strncmp(new_elt, "sa\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "sb\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "ss\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "ra\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "rb\n", len) == 0)
		return (0);
	else if (ft_strncmp(new_elt, "rr\n", len) == 0)
		return (0);
	return (check_valid_move_next(new_elt));
}
