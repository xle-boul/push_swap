/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:06:16 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/06 11:53:32 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swapswap(t_stack **a, t_stack **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_operations_counter("ss", 0, 1);
}

void	rotrot(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_operations_counter("rr", 0, 1);
}

void	revrotrot(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_operations_counter("rrr", 0, 1);
}
