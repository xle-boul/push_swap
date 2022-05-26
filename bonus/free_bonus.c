/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/22 09:02:10 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_list(t_stack *head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	while (head->next)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(head);
	head = NULL;
}

void	ft_free_array(int **splits, int max)
{
	while (--max >= 0)
		free(splits[max]);
	free(splits);
}
