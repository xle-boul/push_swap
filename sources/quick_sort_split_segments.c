/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_split_segments.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:25:03 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/18 11:53:55 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// envoie les a high et low au dessus de la liste A
void	ft_push_to_top_of_a(t_stack **a, t_stack **b, t_ct *n)
{
	if ((*b)->idx < n->new_med_a)
		n->count_low_a++;
	else
		n->count_high_a++;
	push(a, b, 'a');
}

// envoiles les b high and le fond de A et
// les b low dans le fond de b
void	ft_split_between_a_and_b(t_stack **a, t_stack **b, t_ct *n)
{
	if ((*b)->idx < n->new_med_b)
	{
		rotate(b, 'b');
		n->count_low_b++;
	}
	else
	{
		push(a, b, 'a');
		rotate(a, 'a');
		n->count_high_b++;
	}
}

// replace a dans b en fonction de la taille de l'element:
// 	les plus faibles en haut
// 	les plus eleves en bas
void	ft_split_a_even_more(t_stack **a, t_stack **b, t_ct n)
{
	int	tot_count;

	tot_count = n.count_high_a + n.count_low_a;
	while (tot_count-- > 0)
	{
		push(b, a, 'b');
		if ((*b)->idx >= n.new_med_a)
			rotate(b, 'b');
	}
}