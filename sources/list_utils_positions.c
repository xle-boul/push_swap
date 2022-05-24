/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:42:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 09:55:12 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// verifie que l'element portant la valeur num est dans la liste
// passee en argument
int	ft_is_in_list(t_stack **head, int num)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->idx == num)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->idx == num)
		return (0);
	return (1);
}

// retourne le dernier element de la liste chainee passee en argument
t_stack	*last_node(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	if (!tmp)
		return (NULL);
	if (!tmp->next)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// retourne le premier element de la liste chainee passee en argument
t_stack	*first_node(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
