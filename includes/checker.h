/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:01 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 19:19:15 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		launch_move(t_double_list **head_a, t_double_list **head_b,
			t_double_list **instructions);
void	del(void *content);
int		check_valid_move(char *new_elt);
int		launch_ss(t_double_list **head_a, t_double_list **head_b);
int		launch_rr(t_double_list **head_a, t_double_list **head_b);
int		launch_rrr(t_double_list **head_a, t_double_list **head_b);
#endif
