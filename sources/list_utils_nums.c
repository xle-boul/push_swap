/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:02:49 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 16:34:15 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// retourne la longueur de la liste donnee en argument
int	list_length(t_stack *head)
{
	t_stack	*temp;
	int		len;

	temp = head;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

// retourne la valeur maximal de la chaine passee en argument
int	max_value(t_stack *head)
{
	t_stack	*temp;
	int		max_value;

	temp = head;
	max_value = MIN_INT;
	while (temp)
	{
		if (temp->num > max_value)
			max_value = temp->num;
		temp = temp->next;
	}
	return (max_value);
}

// retourne la valeur minimale de la chaine passee en argument
int	min_value(t_stack *head)
{
	t_stack	*temp;
	int		min_value;

	temp = head;
	min_value = MAX_INT;
	while (temp)
	{
		if (temp->num < min_value)
			min_value = temp->num;
		temp = temp->next;
	}
	return (min_value);
}

// retourne la valeur du prochain element (ordre croissant) de la liste
int	next_num(t_stack *head, int num)
{
	t_stack	*temp;
	int		next_number;

	if (!head)
		return (num);
	next_number = max_value(head);
	temp = head;
	while (temp)
	{
		if (temp->num > num && next_number > temp->num)
			next_number = temp->num;
		temp = temp->next;
	}
	return (next_number);
}
