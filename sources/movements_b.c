/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:54:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 23:22:58 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack *head_a, t_stack *head_b)
{
	t_stack	*second;
	t_stack	*tmp;
	
	if (!head_b || !head_b->next)
		return ;
	second = head_b->next;
	tmp = head_b;
	head_b = second;
	second = tmp;
}

void	push_b(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!head_a)
		return ;
	tmp_a = head_a->next;
	tmp_b = head_b;
	head_b = head_a;
	head_a = tmp_a;
	head_b->next = tmp_b;
}

void	rotate_b(t_stack *head_a, t_stack *head_b)
{
	
}

void	reverse_rotate_b(t_stack *head_a, t_stack *head_b)
{
	
}
