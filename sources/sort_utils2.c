/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:55:04 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 15:17:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// retourne l'index de valeur maximale de la liste passee en argument
int	max(t_stack *head)
{
	t_stack	*tmp;
	int		max;

	tmp = head;
	max = 0;
	while (tmp)
	{
		if (tmp->idx > max)
			max = tmp->idx;
		tmp = tmp->next;
	}
	return (max);
}

// retourne l'index de valeur minimale de la liste passee en argument
int	min(t_stack *head)
{
	t_stack	*tmp;
	int		min;

	tmp = head;
	min = max(head);
	while (tmp)
	{
		if (tmp->idx < min)
			min = tmp->idx;
		tmp = tmp->next;
	}
	return (min);
}

// retourne la valeur de l'index du dernier element de la
// liste passee en argument
int	last_index(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->idx);
}

// retourne la valeur de l'index du prochain element (ordre croissant) de
// la liste passee en argument
int	next_index(t_stack *head)
{
	t_stack	*tmp;
	int		count;
	int		n;

	tmp = head;
	count = 0;
	n = max(tmp);
	while (1)
	{
		if (tmp->idx == n)
			break ;
		if (tmp->next == NULL)
		{
			tmp = first_node(&tmp);
			count++;
		}
		else
		{
			tmp = tmp->next;
			count++;
		}
	}
	return (count);
}
