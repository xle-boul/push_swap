/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_free_list(t_stk *head)
{
	t_stk	*tmp;

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
