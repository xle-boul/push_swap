/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:56:49 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 14:34:12 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fonction qui traite les elements un par un en cyclant avec rotate
// dans la stack A. Effectue en pre tri en fonction des grandeurs
// fournies par les index s
// 	si l'element est compris entre s.min_lo et s.max_lo
// 		l'element sera mis en haut du stack B.
// 	si l'element est compris entre s.min_hi et s.max_hi
// 		l'element sera mis en bas de stack B.
void	ft_transfer_to_b(t_stk **a, t_stk **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if (s.min_lo <= (*a)->idx && (*a)->idx <= s.max_hi)
		{
			push(b, a, 'b');
			if (s.min_lo <= (*b)->idx && (*b)->idx <= s.max_lo)
			{
				if (*a != NULL && !(s.min_lo <= (*a)->idx
						&& (*a)->idx <= s.max_hi))
					rotrot(a, b, 0);
				else
					rotate(b, 'b');
			}
			s.number_of_el_to_pass--;
		}
		else
			rotate(a, 'a');
	}
}
