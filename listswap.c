/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:05:17 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 22:12:25 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_new(int newlist)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->index = -1;
	new->next = NULL;
	new->info = newlist;
	return (new);
}

t_stack	*ft_last(t_stack *first)
{
	t_stack	*tmp;

	tmp = first;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_addlast(t_stack **list, t_stack *new)
{
	t_stack	*n;

	if (*list)
	{
		n = ft_last(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	sizelista(t_stack *first)
{
	t_stack	*tmp;
	int		i;

	tmp = first;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
