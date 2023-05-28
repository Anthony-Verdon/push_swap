/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstdelone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:53:21 by averdon           #+#    #+#             */
/*   Updated: 2022/10/19 18:45:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_double_list.h"

void	ft_double_lstdelone(t_double_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
