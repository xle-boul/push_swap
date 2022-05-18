/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:55:04 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/10 21:43:23 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// retourne l'index de valeur maximale de la liste passee en argument
int	max_index(t_stack *head)
{
	t_stack	*tmp;
	int		max_index;

	tmp = head;
	max_index = 0;
	while (tmp)
	{
		if (tmp->idx > max_index)
			max_index = tmp->idx;
		tmp = tmp->next;
	}
	return (max_index);
}

// retourne l'index de valeur minimale de la liste passee en argument
int	min_index(t_stack *head)
{
	t_stack	*tmp;
	int		min_index;

	tmp = head;
	min_index = max_index(head);
	while (tmp)
	{
		if (tmp->idx < min_index)
			min_index = tmp->idx;
		tmp = tmp->next;
	}
	return (min_index);
}

// retourne la valeur de l'index du dernier element de la liste passee en argument
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
int	ft_next_index(t_stack *head)
{
	t_stack	*tmp;
	int		count;
	int		n;

	tmp = head;
	count = 0;
	n = max_index(tmp);
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
