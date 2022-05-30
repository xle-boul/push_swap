/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:39:48 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fonction qui etablit les index des differents segments et les balance
// dans la fonction qui les envoie dans B
void	ft_sort_launch(t_stk **a, t_stk **b)
{
	t_index	step;
	int		passages;

	step = ft_set_indexes_first_step(a);
	ft_transfer_to_b(a, b, step);
	passages = step.passages / 2 - 2;
	while (passages-- > 0)
	{
		step = ft_set_indexes_step(step);
		ft_transfer_to_b(a, b, step);
	}
	step = ft_set_indexes_last_step(step, *a);
	ft_transfer_to_b(a, b, step);
}

// demarrage de la procedure de tri. Separe en 2 fonctions:
	//1/	<= 27 elements
	//		> 27 elements
	//			 ces valeurs ont ete attribuees par tests
// cf push_swap.c pour une explication du sort

void	ft_sort_init(t_stk *a)
{
	t_stk	*b;

	b = NULL;
	if (list_length(a) <= SWEET_SPOT)
		ft_sort_to_27(&a, &b);
	else
	{
		ft_sort_launch(&a, &b);
		ft_bring_back_to_a(&a, &b);
	}
	ft_fini(a, b);
}
