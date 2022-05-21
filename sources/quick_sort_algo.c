/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:05:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 11:39:16 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_end_of_second_part(t_stack **a, t_stack **b, t_index s, int n)
{
	if (n == 1)
	{
		ft_quick_sort_step_2(a, b, s);
		ft_reassort_a(a, b, s);
	}
	else
	{
		ft_quick_sort_step_4(a, b, s);
		ft_empty_a(a, b);
	}
}

void	ft_quick_sort_second_part(t_stack **a, t_stack **b)
{
	int		repetitions;
	t_index	step4;
	t_index	step5;
	t_index	step6;

	repetitions = 0;
	while (repetitions++ < 2)
	{
		if (repetitions == 1)
			step4 = ft_set_indexes_step4(a, 'l');
		else
			step4 = ft_set_indexes_step4(a, 'h');
		ft_quick_sort_step_3(a, b, step4);
		step5 = ft_set_indexes_step3(step4, 'l');			
		ft_quick_sort_step_2(a, b, step5);
		step6 = ft_set_indexes_step3(step5, 'h');
		ft_reassort_a_and_b(a, b, step6, step5);
		step6 = ft_set_indexes_step3(step4, 'h');
		ft_end_of_second_part(a, b, step6, repetitions);
	}
}

void	ft_quick_sort_first_part(t_stack **a, t_stack **b)
{
	int		repetitions;
	t_index	step1;
	t_index	step2;
	t_index	step3;

	repetitions = 0;
	step1 = ft_set_indexes_step1(a);
	ft_quick_sort_step_1(a, b, step1);
	while (repetitions++ < 2)
	{
		if (repetitions == 1)
			step2 = ft_set_indexes_step2(b, 'h');
		else
			step2 = ft_set_indexes_step2(b, 'l');
		ft_quick_sort_step_2(a, b, step2);
		step3 = ft_set_indexes_step3(step2, 'h');
		ft_quick_sort_step_3(a, b, step3);
		ft_push_to_bottom(b, step3);
		step3 = ft_set_indexes_step3(step2, 'l');
		ft_push_to_top(a, step3);
		ft_quick_sort_step_3(a, b, step3);
		ft_push_to_bottom(b, step3);
	}
}
