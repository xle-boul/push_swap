/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/10 21:03:58 by xle-boul         ###   ########.fr       */
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

void	ft_free_list_data(t_data *head)
{
	t_data	*tmp;

	if (!head)
		return ;
	while (head->next != NULL)
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
