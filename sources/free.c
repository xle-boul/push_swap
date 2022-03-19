/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 22:05:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_list(t_stack *head_a)
{
	t_stack	*tmp;

	if (!head_a)
		return ;
	while (head_a)
	{
		tmp = head_a->next;
		free(head_a);
		head_a = tmp;
	}
	free(head_a);
	head_a = NULL;
}