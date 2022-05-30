/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_simple_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:54:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 21:12:46 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap(t_stack **head, char who)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	third = second->next;
	*head = second;
	(*head)->prev = NULL;
	first->prev = *head;
	first->next = second->next;
	if (third != NULL)
		third->prev = first;
	(*head)->next = first;
	ft_operations_counter("s", who, 0);
}

void	push_last_elem(t_stack **head_dest, t_stack **head_orig)
{
	t_stack	*tmp_dest;

	tmp_dest = NULL;
	if (*head_dest)
		tmp_dest = *head_dest;
	if (!((*head_orig)->next))
	{
		*head_dest = *head_orig;
		(*head_dest)->next = tmp_dest;
		if (tmp_dest != NULL)
			tmp_dest->prev = *head_dest;
		*head_orig = NULL;
		return ;
	}
}

void	push(t_stack **head_dest, t_stack **head_orig, char who)
{
	t_stack	*tmp_dest;

	if (!*head_orig)
		return ;
	tmp_dest = NULL;
	if (*head_dest)
		tmp_dest = *head_dest;
	if (!((*head_orig)->next))
	{
		push_last_elem(head_dest, head_orig);
		ft_operations_counter("p", who, 0);
		return ;
	}
	*head_dest = *head_orig;
	*head_orig = (*head_orig)->next;
	(*head_orig)->prev = NULL;
	(*head_dest)->next = tmp_dest;
	if (tmp_dest != NULL)
		tmp_dest->prev = *head_dest;
	ft_operations_counter("p", who, 0);
}

void	rotate(t_stack **head, char who)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	node = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	tmp->next->prev = tmp;
	*head = node->next;
	(*head)->prev = NULL;
	node->next = NULL;
	ft_operations_counter("r", who, 0);
}

void	reverse_rotate(t_stack **head, char who)
{
	t_stack	*last;
	t_stack	*tmp;
	t_stack	*first;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	tmp = last->prev;
	*head = last;
	tmp->next = NULL;
	(*head)->prev = NULL;
	(*head)->next = first;
	first->prev = *head;
	ft_operations_counter("rr", who, 0);
}
