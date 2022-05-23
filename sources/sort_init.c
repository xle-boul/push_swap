/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:39:48 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/23 13:36:05 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// demarrage de la procedure de tri. Separe en 2 fonctions:
	// moins de 11 elements
	// plus de 10 elements

// but du sort ici: decouper la liste en 2 parties egales (si possible)
// 1/ deplacer cette partie dans B en triant
// 	les chiffres au dessus de la mediane allant en haut
// 	les chiffres en dessous de la mediane (comprise) allant en bas
// 2/ ramener la moitie superieure de cette liste intermediaire dans B vers A
// 	les chiffres au dessus de la mediane allant en haut
// 	les chiffres en dessous de la mediane (comprise) allant en bas
// 3/ ramener la moitie inferieure de cette liste intermediaire dans B vers A
// 	les chiffres au dessus de la mediane allant en haut
// 	les chiffres en dessous de la mediane (comprise) allant en bas
void	ft_sort_init(t_stack *a, int ac)
{
	t_stack	*b;

	b = NULL;
	if (ac <= 11)
		ft_sort_to_10(&a, &b);
	else
	{
		ft_quick_sort(&a, &b);
		ft_bring_back_to_a(&a, &b);
		ft_fini(a, b);
	}
	if (b == NULL && ft_check_if_sorted(a) == 0)
		ft_operations_counter(NULL, 0, 2);
}
