/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:05:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 10:01:03 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	t_index	step;
	int		passages;

	step = ft_set_indexes_first_step(a);
	ft_transfer_to_b(a, b, step);
	passages = step.passages / 2 - 2;
	while (passages-- > 0)
	{
		step = ft_set_indexes_step(step);
		ft_transfer_to_b(a, b, step);
	}
	step = ft_set_indexes_last_step(step, *a);
	ft_transfer_to_b(a, b, step);
}
