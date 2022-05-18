/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_second_split.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:33:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/18 11:48:56 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ramene high_a et high_b du bas des listes A et B en meme temps
void	ft_bring_both_bottoms_up(t_stack **a, t_stack **b, int count_a, int count_b)
{
	if (count_a > 0 && count_b > 0)
	{
		while (count_a > 0 && count_b > 0)
		{
			revrotrot(a, b);
			count_a--;
			count_b--;
		}
	}
	while (count_a-- > 0)
		reverse_rotate(b, 'b');
	while (count_b-- > 0)
		reverse_rotate(a, 'a');
}

// remet high_b sur le dessus de A, sauf si la liste A est deja classee
// telle quelle
void	ft_bring_higher_split_back(t_stack **a, t_stack **b, t_ct *n)
{
	// int	count_low;
	int	count_high;

	// count_low = n->count_low_b;
	count_high = n->count_high_b;
	// while (count_low-- > 0)
	// 	reverse_rotate(b, 'b');
	if (ft_check_if_sorted(*a) == 0)
	{
		n->count_high_b = 0;
		return ;
	}
	while (count_high-- > 0)
		push(b, a, 'b');
}



void	ft_bring_back_from_bottom_b(t_stack **a, t_stack **b, int num)
{
	int	path;

	while (num-- > 0)
	{
		path = ft_find_shortest_path(*b, (*a)->idx - 1);
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
	}
}

void	ft_sort_shit(t_stack **a, t_stack **b, t_splits s)
{
	ft_sort_shit_split(a, b, s.max_high_b, s.min_high_b);
	ft_sort_shit_split(a, b, s.max_low_b, s.min_low_b);
	ft_sort_shit_split(a, b, s.max_high_a, s.min_high_a);
	ft_sort_shit_split(a, b, s.max_low_a, s.min_low_a);
}


// recoit le stack b rempli avec chaque segment.
// l'intention de cette fonction est de subdiviser encore chaque segment
// afin d'avoir moins d'elements a la fois.
void	ft_second_split(t_stack **a, t_stack **b, t_data **data)
{
	t_ct		n;
	t_splits	s;

	n = ft_counters_init(*data);
	while (n.steps-- > 0)
	{
		if ((*b)->idx < (*data)->med)
			ft_push_to_top_of_a(a, b, &n);
		else
			ft_split_between_a_and_b(a, b, &n);
	}
	ft_split_a_even_more(a, b, n);
	ft_bring_both_bottoms_up(a, b, n.count_high_a, n.count_high_b);
	ft_bring_higher_split_back(a, b, &n);
	s = ft_second_counters_init(&n, *data);
	ft_sort_shit(a, b, s);
	ft_move_data_pointer(data);
}

// nouvelle idee pour ameliorer le score:
// A chaque sous tri, trier encore avec le pivot du median, voire,
// trier completement le sous segment dans sa position pour n'avoir
// qu'a le push directement dans A