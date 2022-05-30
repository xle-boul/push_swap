/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:51:05 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// retourne le nombre d'operations a faire pour atteindre
// l'element de la liste chainee contenant l'index n
// en partant du haut de la liste
int	from_top(t_stk **head, int num)
{
	t_stk	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		if (tmp->idx == num)
			return (count);
		tmp = tmp->next;
		count++;
	}
	return (-1);
}

// retourne le nombre d'operations a faire pour atteindre
// l'element de la liste chainee contenant l'index n
// en partant du bas de la liste
int	from_bot(t_stk **head, int num)
{
	t_stk	*tmp;
	int		count;

	tmp = last_node(head);
	count = 0;
	while (tmp)
	{
		count++;
		if (tmp->idx == num)
			return (count);
		tmp = tmp->prev;
	}
	return (-1);
}

// trouve le chemin le plus court pour atteindre le num recherche
int	ft_find_shortest_path(t_stk *head, int num)
{
	int	top;
	int	bot;

	top = from_top(&head, num);
	bot = from_bot(&head, num);
	if (top < bot)
		return (top);
	return ((bot) * -1);
}
