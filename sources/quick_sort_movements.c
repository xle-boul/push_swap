/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:56:49 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/23 11:45:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_to_first_of_range(t_stack **a, int path, t_index s)
{
	while (1)
	{
		if (s.min_lo <= (*a)->idx && (*a)->idx <= s.max_hi)
			return ;
		else
		{
			if (path > 0)
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
	}
}


void	ft_transfer_to_b(t_stack **a, t_stack **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if (s.min_lo <= (*a)->idx && (*a)->idx <= s.max_hi)
		{
			push(b, a, 'b');
			if (s.min_lo <= (*b)->idx && (*b)->idx <= s.max_lo)
				rotate(b, 'b');
			s.number_of_el_to_pass--;
		}
		else
			rotate(a, 'a');
	}
}