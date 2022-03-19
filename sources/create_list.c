/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:32 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_new_node(int	num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		ft_error_handler(0);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	ft_add_at_tail(t_stack **head_a, t_stack *new)
{
	t_stack	*tmp;

	if (!(*head_a))
	{
		*head_a = new;
		return ;
	}
	else
	{
		tmp = *head_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_stack	*ft_arg_to_chained_list(int *ls, t_stack *head_a, int count)
{
	int		i;
	t_stack	*new;

	head_a = NULL;
	i = 0;
	while (i < count)
	{
		new = ft_create_new_node(ls[i]);
		ft_add_at_tail(&head_a, new);
		i++;
	}
	free(ls);
	return (head_a);
}