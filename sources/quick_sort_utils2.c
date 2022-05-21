/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:52:40 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 11:40:40 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reassort_a_and_b(t_stack **a, t_stack **b, t_index s, t_index t)
{
	while (s.len_lo-- > 0)
		reverse_rotate(a, 'a');
	while (t.len_lo-- > 0)
		push(b, a, 'b');
	while (t.len_hi-- > 0)
		reverse_rotate(b, 'b');
}

void	ft_reassort_a(t_stack **a, t_stack **b, t_index s)
{
	t_index	tmp;
	int		add;

	tmp = ft_set_indexes_step3(s, 'l');
	add = tmp.len_hi + tmp.len_lo;
	while (tmp.len_lo-- > 0)
		reverse_rotate(a, 'a');
	while (add-- > 0)
		push(b, a, 'b');
}

// ramene tous les elements du fond de B pour les transferer vers A
void	ft_push_to_bottom(t_stack **head, t_index s)
{
	while (s.min <= (*head)->idx && (*head)->idx <= s.median)
		rotate(head, 'b');
}

// ramene tous les elements du fond de A pour les transferer vers B
void	ft_push_to_top(t_stack **head, t_index s)
{
	while (s.number_of_el_to_pass-- > 0)
		reverse_rotate(head, 'a');
}

void	ft_empty_a(t_stack **a, t_stack **b)
{
	while (*a != NULL)
		push(b, a, 'b');
}