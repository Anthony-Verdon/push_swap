/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:49:45 by averdon           #+#    #+#             */
/*   Updated: 2023/05/28 14:04:29 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<limits.h>
# include<stdlib.h>
# include<unistd.h>
# include"libraries/libft/libft.h"
# include"libraries/libft/ft_printf/ft_printf.h"
# include"libraries/srcs_double_list/ft_double_list.h"

typedef struct s_array_int{
	int	*array;
	int	size;
}	t_array_int;

int				sa(t_double_list **head, t_double_list **instructions);
int				sb(t_double_list **head, t_double_list **instructions);
int				ra(t_double_list **head, t_double_list **instructions);
int				rb(t_double_list **head, t_double_list **instructions);
int				rra(t_double_list **head, t_double_list **instructions);
int				rrb(t_double_list **head, t_double_list **instructions);
int				pa(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
int				pb(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);

void			call_sa(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_sb(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_ra(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_rb(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_rra(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_rrb(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_pa(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_pb(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
void			call_rotate_a(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions, int value);
void			call_rotate_a_for_quicksort(t_double_list **head_a,
					t_double_list **head_b, t_double_list **instructions,
					int value);
void			call_rotate_b(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions, int value);

void			quicksort(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
int				empty_b(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);
int				rotate_a(t_double_list **head_a, int min_a,
					t_double_list **instructions);
int				rotate_a_for_quicksort(t_double_list **head_a,
					int min_a, t_double_list **instructions);
int				rotate_b(t_double_list **head_b, int min_b,
					t_double_list **instructions);
void			complete_a(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);

t_double_list	*parsing(int argc, char **argv);
char			**create_tab(int argc, char **argv);
int				ft_strcmp_modified(char *s1, char *s2);
int				check_duplicate_value(t_double_list **head_a, char *new_elt);
int				is_valid_atoi(char	*str);
void			free_tab(char **tab);
t_double_list	*sort_a(t_double_list **head_a);
int				calculate_len_stack(t_double_list **head_a);
int				calculate_median(t_double_list **head_a_sorted, int nb_pivot);
int				check_quicksort(t_double_list **head_a, int median);
void			less_than_six(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);

int				search_min(t_double_list *head);
int				search_after_min(t_double_list *head);
int				search_max(t_double_list *head);
int				search_before_max(t_double_list *head);
void			del(void *content);
int				list_sorted(t_double_list **head);
int				calculate_len_stack(t_double_list **head_a);
int				nb_action_to_find(t_double_list **head, int num);
void			kill_program(t_double_list **head_a, t_double_list **head_b,
					t_double_list **instructions);

#endif
