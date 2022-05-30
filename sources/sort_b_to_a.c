/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:14:40 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 14:34:04 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fonction qui circule dans le stack B en fonction de la proximite
// du prochain element. essaye de reperer si l'element - 1 est sur le
// chemin. si oui: met l'element dans le bas du stack A
// 	Petite optimisation ici: Si la direction de l'element recherche
// 	correspond a rotate (operation pour mettre element - 1 dans le bas
// 	du stack A), on fait un double rotate.
void	ft_move_to_target(t_stk **a, t_stk **b, int target, int path)
{
	while (1)
	{
		if ((*b)->idx == target)
			return ;
		else if ((*b)->idx == target - 1)
		{
			push(a, b, 'a');
			if (path > 0 && (*b)->idx != target)
				rotrot(a, b, 0);
			else
				rotate(a, 'a');
		}
		else
		{
			if (path > 0)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
	}
}

// fonction qui recherche le chemin le plus court pour aller trouver l'element
// suivant a mettre dans le stack A et ramene l'element a sa place.
	// Petite optimisation: Si l'element - 1 est dans le fond du stack A
	// et que le sens de rotation pour l'element est reverse rotate,
	// double reverse rotate.
void	ft_bring_back_to_a(t_stk **a, t_stk **b)
{
	int	target;
	int	path;

	while (*b != NULL)
	{
		target = max(*b);
		path = ft_find_shortest_path(*b, target);
		ft_move_to_target(a, b, target, path);
		push(a, b, 'a');
		if (*b == NULL && ft_check_if_sorted(*a) == 0)
			return ;
		if (last_index(*a) != max(*a)
			&& ft_find_shortest_path(*b, max(*b) < 0))
			revrotrot(a, b, 0);
		else if (last_index(*a) != max(*a))
			reverse_rotate(a, 'a');
	}
}
