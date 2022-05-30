/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 21:13:07 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

// transforme les valeurs de la liste en index, partant de 0
// et incrementant de 1 a chaque element
void	ft_assign_indexes(t_stack **head)
{
	unsigned int	i;
	int				num;
	t_stack			*tmp;

	i = 0;
	tmp = *head;
	num = min_value(*head);
	while (tmp)
	{
		if (tmp->num == num)
		{
			tmp->idx = i;
			if (num == next_num(*head, num))
				return ;
			num = next_num(*head, num);
			tmp = *head;
			i++;
		}
		else
			tmp = tmp->next;
	}
}

// cree un element de la liste chainee avec son numero
// correspondant
t_stack	*ft_create_new_node(int num, t_stack *head)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		ft_error_handler_free(0, head);
	node->num = num;
	node->idx = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// place l'element de la liste chainee au bout de la liste
void	ft_add_at_tail(t_stack **a, t_stack *new)
{
	t_stack	*tmp;

	if (!(*a))
	{
		*a = new;
		return ;
	}
	else
	{
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

// transforme les arguments en une liste chainee
t_stack	*ft_arg_to_chained_list(int *ls, int count)
{
	int		i;
	t_stack	*head;
	t_stack	*new;

	head = NULL;
	i = 0;
	while (i < count)
	{
		new = ft_create_new_node(ls[i], head);
		ft_add_at_tail(&head, new);
		i++;
	}
	return (head);
}
