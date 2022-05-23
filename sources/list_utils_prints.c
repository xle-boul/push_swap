/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/22 09:41:46 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list_index(t_stack *head)
{
	if (!head)
		ft_printf("Nothing to print\n");
	while (head != NULL)
	{
		ft_printf("%2d ", head->idx);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_list(t_stack *head)
{
	if (!head)
		ft_printf("Nothing to print\n");
	while (head != NULL)
	{
		ft_printf("%2d ", head->num);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_both_lists(t_stack *a, t_stack *b)
{
	ft_printf("A = ");
	ft_print_list_index(a);
	ft_printf("B = ");
	ft_print_list_index(b);
}

void	ft_print_index(t_index s)
{
	ft_printf("min low = %d\nmax low = %d\nmin high = %d\nmax high = %d\nsplits = %d\nelements to transfer = %d\n", s.min_lo, s.max_lo, s.min_hi, s.max_hi, s.splits, s.number_of_el_to_pass);
}
