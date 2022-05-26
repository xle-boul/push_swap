/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/25 22:14:22 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_stack *head, char color)
{
	if (!head)
		ft_printf(YELLOW"Empty"END);
	while (head != NULL)
	{
		if (color == 'A')
			ft_printf(BLUE"%d "END, head->num);
		else if (color == 'B')
			ft_printf(MAGENTA"%d "END, head->num);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_list_index(t_stack *head)
{
	if (!head)
		ft_printf("Empty\n");
	while (head != NULL)
	{
		ft_printf("%2d ", head->idx);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_both_lists(t_stack *a, t_stack *b)
{
	ft_printf(BLUE"A = "END);
	ft_print_list(a, 'A');
	ft_printf(MAGENTA"B = ");
	ft_print_list(b, 'B');
}
