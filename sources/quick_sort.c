/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:20:13 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 11:40:49 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
void	ft_quick_sort_hub(t_stack **a, t_stack **b)
{
	ft_quick_sort_first_part(a, b);
	ft_quick_sort_second_part(a, b);
	// ft_final_step(a, b);
	ft_print_both_lists(*a, *b);
	ft_fini(*a, *b);
}