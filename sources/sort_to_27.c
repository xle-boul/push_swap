/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_27.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:09 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 15:17:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// hard code de la resolution des cas de 3 elements
void	ft_sort_3(t_stack **head, char who)
{
	if ((*head)->idx == min(*head) && (*head)->next->idx < max(*head))
		return ;
	else if ((*head)->idx == max(*head) && (*head)->next->idx > min(*head))
	{
		swap(head, who);
		reverse_rotate(head, who);
	}
	else if ((*head)->next->idx == min(*head) && (*head)->idx < max(*head))
		swap(head, who);
	else if ((*head)->idx == min(*head) && (*head)->next->idx == max(*head))
	{
		swap(head, who);
		rotate(head, who);
	}
	else if ((*head)->idx == max(*head) && (*head)->next->idx == min(*head))
		rotate(head, who);
	else if ((*head)->next->idx == max(*head) && (*head)->idx > min(*head))
		reverse_rotate(head, who);
}

// remet les elements passes dans B sur le dessus de A
void	ft_sort_back_27(t_stack **a, t_stack **b)
{
	if ((*b) == NULL)
		return ;
	while ((*b) != NULL)
		push(a, b, 'a');
}

void	ft_stupid_norminette(int i, t_stack **a)
{
	if (i > 0)
		rotate(a, 'a');
	else
		reverse_rotate(a, 'a');
}

// pousse dans B tous les elements sauf 3 en les classant en
// ordre decroissant dans B
void	ft_prepare_transfer_to_b(t_stack **a, t_stack **b)
{
	int	num;
	int	i;

	while (list_length(*a) > 3)
	{
		num = min(*a);
		i = ft_find_shortest_path(*a, num);
		while (1)
		{
			num = min(*a);
			if ((*a)->idx == num)
			{
				push(b, a, 'b');
				break ;
			}
			else if ((*a)->next->idx == num)
				swap(a, 'a');
			else
				ft_stupid_norminette(i, a);
		}
	}
}

// gere le tri de moins de 28 elements
void	ft_sort_to_27(t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 0)
		return ;
	if (list_length(*a) == 1 || list_length(*a) == 0)
		return ;
	else if (list_length(*a) == 2)
	{
		if ((ft_check_if_sorted(*a) == -1))
			swap(a, 'a');
	}
	else if (list_length(*a) == 3)
		ft_sort_3(a, 'a');
	else
	{
		ft_prepare_transfer_to_b(a, b);
		ft_sort_3(a, 'a');
		ft_sort_back_27(a, b);
	}
}
