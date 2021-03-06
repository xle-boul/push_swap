/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_prints_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 00:16:11 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_print_list(t_stk *head, char color, t_bool bl)
{
	if (!head)
	{
		if (bl.color == true)
			ft_printf(YELLOW"Empty"END);
		else
			ft_printf("Empty");
	}
	while (head != NULL)
	{
		if (color == 'A')
			ft_printf(BLUE"%d "END, head->num);
		else if (color == 'B')
			ft_printf(MAGENTA"%d "END, head->num);
		else
			ft_printf("%d ", head->num);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_both_lists(t_stk *a, t_stk *b, t_bool bl)
{
	if (bl.color == true)
	{
		ft_printf(BLUE"A = "END);
		ft_print_list(a, 'A', bl);
		ft_printf(MAGENTA"B = "END);
		ft_print_list(b, 'B', bl);
	}
	else
	{
		ft_printf("A = ");
		ft_print_list(a, 'C', bl);
		ft_printf("B = ");
		ft_print_list(b, 'C', bl);
	}
}

void	ft_print_list_index(t_stk *head)
{
	if (!head)
		return ;
	while (head != NULL)
	{
		ft_printf("%d ", head->idx);
		head = head->next;
	}
	ft_printf("\n");
}
