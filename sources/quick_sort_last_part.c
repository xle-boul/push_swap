/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_last_part.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:14:40 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/23 19:58:58 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_to_target(t_stack **a, t_stack **b, int target, int path)
{
	while (1)
	{
		(void)a;
		if ((*b)->idx == target)
			return ;
		// else if ((*b)->idx == target - 1)
		// {
		// 	push(a, b, 'a');
		// 	rotate(a, 'a');
		// }
		// else if (*a != NULL && (*b)->idx == last_index(*a) - 1)
		// {
		// 	push(a, b, 'a');
		// 	rotate(a, 'a');
		// }
		else
		{
			if (path > 0)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
	}
}

// void	ft_bring_rest_back_up(t_stack **a, t_stack **b)
// {
// 	int	target;
// 	int	path;

// 	target = max_index(*b);
// 	path = ft_find_shortest_path(*b, target);
// 	if (path < 0 && last_index(*a) > target)
// 	{
// 		while (path-- < 0 && last_index(*a) > target)
// 			revrotrot(a, b);
// 	}
// 	else if (path >= 0 && last_index(*a) > target)
// 		while (last_index(*a) > target)
// 			reverse_rotate(a, 'a');
// 	else
// 		return ;
// }

void	ft_bring_back_to_a(t_stack **a, t_stack **b)
{
	int	target;
	int	path;

	while (*b != NULL)
	{
		target = max_index(*b);
		path = ft_find_shortest_path(*b, target);
		ft_move_to_target(a, b, target, path);
		push(a, b, 'a');
		// ft_bring_rest_back_up(a, b);
	}
}