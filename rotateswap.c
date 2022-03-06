/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:59:58 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 22:13:55 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((sizelista(*stack_a) < 2) || (sizelista(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverserotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	if (sizelista(*stack) < 2)
		return (-1);
	first = *stack;
	tail = ft_last(first);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverserotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverserotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((sizelista(*stack_a) < 2) || (sizelista(*stack_b) < 2))
		return (-1);
	reverserotate(stack_a);
	reverserotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
