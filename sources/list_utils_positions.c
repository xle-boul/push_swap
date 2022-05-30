/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:42:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// verifie que l'element portant la valeur num est dans la liste
// passee en argument
int	ft_is_in_list(t_stk **head, int num)
{
	t_stk	*tmp;

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
t_stk	*last_node(t_stk **head)
{
	t_stk	*tmp;

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
t_stk	*first_node(t_stk **head)
{
	t_stk	*tmp;

	tmp = *head;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

// verifie si les elements d'une liste sont classes en ordre croissant
int	ft_check_if_sorted(t_stk *head)
{
	t_stk	*temp;

	if (head == NULL || head->next == NULL)
		return (1);
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->idx > temp->next->idx)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
