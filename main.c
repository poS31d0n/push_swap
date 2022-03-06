/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:03:58 by sscot             #+#    #+#             */
/*   Updated: 2022/03/03 22:33:53 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = sizelista(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	initialise(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	int		i;
	int		tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		new = ft_new(tmp);
		ft_addlast(stack, new);
		i++;
	}
	indexation(stack);
	if (argc == 2)
		ft_free(args);
}

void	sortirovka(t_stack **stack_a, t_stack **stack_b)
{
	if (sizelista(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	ft_checking(argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_b = NULL;
	*stack_a = NULL;
	initialise(stack_a, argc, argv);
	if (sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sortirovka(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
