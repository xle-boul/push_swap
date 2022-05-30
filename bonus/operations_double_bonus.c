/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:06:16 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 21:56:58 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swapswap(t_stk **a, t_stk **b, int swtch)
{
	swap(a, 'd');
	swap(b, 'd');
	ft_details_counts(-1, 0, 'z');
	if (swtch == 0)
		ft_operations_counter("ss", 'c', 1);
	else
		ft_operations_counter("ss", 'c', 0);
}

void	rotrot(t_stk **a, t_stk **b, int swtch)
{
	rotate(a, 'd');
	rotate(b, 'd');
	ft_details_counts(1, 0, 'z');
	if (swtch == 0)
		ft_operations_counter("rr", 'c', 1);
	else
		ft_operations_counter("ss", 'c', 0);
}

void	revrotrot(t_stk **a, t_stk **b, int swtch)
{
	reverse_rotate(a, 'd');
	reverse_rotate(b, 'd');
	ft_details_counts(2, 0, 'z');
	if (swtch == 0)
		ft_operations_counter("rrr", 'c', 1);
	else
		ft_operations_counter("ss", 'c', 0);
}
