/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/12 21:33:42 by xle-boul         ###   ########.fr       */
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

void	ft_print_med(t_data *head)
{
	if (!head)
		ft_printf("Nothing to print\n");
	while (head != NULL)
	{
		ft_printf("xfer: %d, max: %d, med: %d, min: %d\n", head->to_transfer, head->max, head->med, head->min);
		head = head->next;
	}
}

void	ft_print_both_lists(t_stack *a, t_stack *b)
{
	ft_printf("A = ");
	ft_print_list_index(a);
	ft_printf("B = ");
	ft_print_list_index(b);
}

void	ft_print_data(t_index sort_b)
{
	ft_printf("amount to pass = %d\nlen of a after transfer = %d\nfutur min b = %d\nfutur max b = %d\nfutur med b = %d\n", sort_b.number_of_el_to_pass, sort_b.future_len_a,sort_b.future_min_b, sort_b.future_max_b, sort_b.future_median_b);
}
