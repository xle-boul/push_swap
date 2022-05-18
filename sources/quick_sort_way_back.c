/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_way_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:21:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/17 21:23:54 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_algo(t_stack **a, t_stack **b, int path, int swtch)
{
	if (path > 0)
	{
		while (path-- > 0)
			rotate(b, 'b');
	}
	else if (path < 0)
	{
		while (path++ < 0)
			reverse_rotate(b, 'b');
	}
	push(a, b, 'a');
	if (swtch != 0)
		rotate(a, 'a');
}

int	ft_define_min_target(t_stack **a, t_stack **b, int min)
{
	int	min_target;

	if (ft_is_in_list(b, min) == 0)
		min_target = min;
	else if (ft_is_in_list(a, min) == 0)
		min_target = last_index(*a) + 1;
	return (min_target);
}

void	ft_sort_back_min(t_stack **a, int count)
{
	while (count-- > 0)
		reverse_rotate(a, 'a');
}

void	ft_sort_shit_split(t_stack **a, t_stack **b, int max, int min)
{
	int	target;
	int	min_target;
	int	steps;
	int	path;
	int	count;

	count = 0;
	steps = max - min + 1;
	while (steps-- > 0)
	{
		target = (*a)->idx - 1;
		min_target = ft_define_min_target(a, b, min);
		if (ft_find_shortest_path(*b, target) <= ft_find_shortest_path(*b, min_target))
		{
			path = ft_find_shortest_path(*b, target);
			ft_sort_algo(a, b, path, 0);
		}
		else if (ft_find_shortest_path(*b, target) > ft_find_shortest_path(*b, min_target))
		{
			path = ft_find_shortest_path(*b, min_target);
			ft_sort_algo(a, b, path, 1);
			count++;
		}
	}
	ft_sort_back_min(a, count);
}
