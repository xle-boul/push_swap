/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:56:53 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 15:10:47 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sort du programme proprement, en liberant la memoire allouee
void	ft_fini(t_stack *a, t_stack *b)
{
	ft_free_list(a);
	ft_free_list(b);
	exit (EXIT_SUCCESS);
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
		if (temp->idx > temp->next->idx)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
