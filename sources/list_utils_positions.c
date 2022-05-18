/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:42:28 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/11 09:16:49 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// retourne le nombre d'operations a faire pour atteindre
// l'element de la liste chainee contenant le numero n
// en partant du haut de la liste
int	top(t_stack *head, int n)
{
	t_stack	*temp;
	int		count;

	temp = head;
	count = 0;
	if (temp->next)
	{
		while (temp->next && temp->num != n)
		{
			count++;
			temp = temp->next;
		}
	}
	return (count);
}

// retourne le nombre d'operations a faire pour atteindre
// l'element de la liste chainee contenant le numero n
// en partant du bas de la liste
int	bot(t_stack *head, int n)
{
	t_stack	*temp;
	int		count;

	temp = head;
	count = 0;
	while (temp->next)
		temp = temp->next;
	while (temp->prev && temp->num != n)
	{
		temp = temp->prev;
		count++;
	}
	return (count);
}

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
// verifie si les elements d'une liste sont classes en ordre croissant
int	ft_check_if_sorted(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp->next == NULL || temp == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
