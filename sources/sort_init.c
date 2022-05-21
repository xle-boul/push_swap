/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:39:48 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/19 22:22:26 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// demarrage de la procedure de tri. Separe en 2 fonctions:
	// moins de 11 elements
	// plus de 10 elements
void	ft_sort_init(t_stack *a, int ac)
{
	t_stack	*b;

	b = NULL;
	if (ac <= 11)
		ft_sort_to_10(&a, &b);
	else
	{
		ft_quick_sort_hub(&a, &b);
		// ft_quick_sort_first(&a, &b, &data);
	}
	if (b == NULL && ft_check_if_sorted(a) == 0)
		ft_operations_counter(NULL, 0, 2);
}
