/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:11:22 by averdon           #+#    #+#             */
/*   Updated: 2022/12/01 14:47:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

char	**complete_tab(char **tab_1, char **tab_new_elements, char **new_tab)
{
	int	i;
	int	j;
	int	num_index_tab_1;
	int	num_index_tab_2;

	i = 0;
	num_index_tab_1 = 0;
	num_index_tab_2 = 0;
	while (tab_1[num_index_tab_1])
		num_index_tab_1++;
	while (tab_new_elements[num_index_tab_2])
		num_index_tab_2++;
	j = 0;
	while (i < num_index_tab_1)
	{
		new_tab[i] = tab_1[i];
		i++;
	}
	while (i + j < num_index_tab_1 + num_index_tab_2)
	{
		new_tab[i + j] = tab_new_elements[j];
		j++;
	}
	new_tab[i + j] = NULL;
	return (new_tab);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

char	**ft_join_tab(char **tab_1, char *new_elements, int num_index_tab_1)
{
	int		num_index_tab_2;
	char	**new_tab;
	char	**tab_new_elements;

	tab_new_elements = ft_split(new_elements, ' ');
	if (!tab_new_elements || !tab_new_elements[0])
	{
		free_tab(tab_new_elements);
		return (NULL);
	}
	num_index_tab_2 = 0;
	while (tab_new_elements[num_index_tab_2])
		num_index_tab_2++;
	new_tab = ft_calloc(num_index_tab_1 + num_index_tab_2 + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	new_tab = complete_tab(tab_1, tab_new_elements, new_tab);
	free(tab_new_elements);
	return (new_tab);
}

char	**create_tab(int argc, char **argv)
{
	char			**tab;
	char			**temp;
	int				i;
	int				num_index_tab;

	i = 1;
	tab = ft_split("", ' ');
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		num_index_tab = 0;
		while (tab[num_index_tab])
			num_index_tab++;
		temp = ft_join_tab(tab, argv[i], num_index_tab);
		if (!temp)
		{
			free_tab(tab);
			return (NULL);
		}
		free(tab);
		tab = temp;
		i++;
	}
	return (tab);
}
