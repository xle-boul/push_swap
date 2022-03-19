/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:54:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 23:23:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *head_a)
{
	t_stack	*second;
	t_stack	*tmp;

	if (!head_a || !head_a->next)
		return ;
	second = head_a->next;
	tmp = head_a;
	head_a = second;
	second = tmp;
}

void	push_a(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!head_b)
		return ;
	tmp_b = head_b->next;
	tmp_a = head_a;
	head_a = head_b;
	head_b = tmp_b;
	head_a->next = tmp_a;
}

void	rotate_a(t_stack *head_a)
{
	t_stack	*tmp;

	tmp = head_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	
}

void	reverse_rotate_a(t_stack *head_a)
{
	
}
