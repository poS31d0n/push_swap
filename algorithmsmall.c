/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmsmall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:07:10 by sscot             #+#    #+#             */
/*   Updated: 2022/03/06 16:30:20 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	get_min(t_stack **list, int index)
{
	t_stack	*first;
	int		min;

	first = *list;
	min = first->index;
	while (first)
	{
		if ((first->index < min) && first->index != index)
			min = first->index;
		first = first->next;
	}
	return (min);
}

int	ft_max(t_stack **list)
{
	t_stack	*first;
	int		max;

	first = *list;
	max = first->info;
	while (first)
	{
		if (first->info > max)
			max = first->info;
		first = first->next;
	}
	return (max);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*first;
	int		max;
	int		min;

	min = get_min(stack_a, -1);
	first = *stack_a;
	max = ft_max(stack_a);
	if (sizelista(*stack_a) == 1)
		return ;
	else if (sizelista(*stack_a) == 2)
	{
		if (first->info > first->next->info)
			sa(stack_a);
		return ;
	}
	else if (sizelista(*stack_a) == 3)
	{
		sort_3_end(&*stack_a, first, max, min);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	int		min;

	first = *stack_a;
	if (sorted(stack_a))
		return ;
	min = get_min(stack_a, -1);
	if (first->next->index == min)
		ra(stack_a);
	else if (first->next->next->index == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (first->next->next->next->index == min)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	int		min;

	first = *stack_a;
	min = get_min(stack_a, -1);
	if (first->next->index == min)
		ra(stack_a);
	else if (first->next->next->index == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (first->next->next->next->index == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (first->next->next->next->next->index == min)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
