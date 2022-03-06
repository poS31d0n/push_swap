/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:06:26 by sscot             #+#    #+#             */
/*   Updated: 2022/03/06 15:12:47 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_3_end(t_stack **stack_a, t_stack *first, int max, int min)
{
	if (first->info == max && first->next->index != min)
	{
		ra(stack_a);
		sa(stack_a);
		return ;
	}
	if (first->info == max && first->next->index == min)
	{
		ra(stack_a);
		return ;
	}
	if (first->next->info == max && first->index == min)
	{
		rra(stack_a);
		sa(stack_a);
		return ;
	}
	if (first->next->info == max && first->index != min)
		rra(stack_a);
	if (first->next->index == min && first->info != max)
		sa(stack_a);
	return ;
}

int	ft_duplicate(int tmp, char **argv, int i)
{
	i = i + 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return (0);
		i++;
	}
	return (1);
}

int	ft_digit(char *element)
{
	int	i;

	i = 0;
	if (element[i] == '-')
		i++;
	while (element[i])
	{
		if (!ft_isdigit(element[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_checking(char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_digit(argv[i]))
			error("Error");
		if (!ft_duplicate(tmp, argv, i))
			error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			error("Error");
		i++;
	}
}
