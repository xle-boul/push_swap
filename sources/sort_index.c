/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:58:03 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/24 15:17:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// definit le nombre de decoupes de la liste pour la pousser dans B
int	ft_define_splits(int len)
{
	int	splits;

	if (len <= 250)
		splits = 10;
	else if (len <= 500)
		splits = 20;
	else if (len <= 1000)
		splits = 30;
	else if (len <= 2500)
		splits = 40;
	else if (len <= 5000)
		splits = 60;
	else
		splits = 100;
	return (splits);
}

// definit les index de la premiere phase du transfer
t_index	ft_set_indexes_first_step(t_stack **head)
{
	t_index	step1;
	int		len;

	len = list_length(*head);
	step1.passages = ft_define_splits(len);
	step1.splits = list_length(*head) / step1.passages;
	step1.number_of_el_to_pass = step1.splits * 2;
	step1.min_lo = min(*head);
	step1.max_lo = (step1.min_lo + step1.splits) - 1;
	step1.min_hi = step1.max_lo + 1;
	step1.max_hi = step1.min_hi + step1.splits - 1;
	return (step1);
}

// definit les index pour toutes les etapes du transfert sauf
// le premier et le dernier
t_index	ft_set_indexes_step(t_index s)
{
	t_index	step;

	step.splits = s.splits;
	step.number_of_el_to_pass = s.number_of_el_to_pass;
	step.min_lo = s.max_hi + 1;
	step.max_lo = (step.min_lo + step.splits) - 1;
	step.min_hi = step.max_lo + 1;
	step.max_hi = step.min_hi + step.splits - 1;
	return (step);
}

// definit les index pour la derniere phase du transfert
t_index	ft_set_indexes_last_step(t_index s, t_stack *head)
{
	t_index	step;

	step.splits = list_length(head) / 2;
	step.number_of_el_to_pass = list_length(head);
	step.min_lo = s.max_hi + 1;
	step.max_lo = (step.min_lo + step.splits) - 1;
	step.min_hi = step.max_lo + 1;
	step.max_hi = max(head);
	return (step);
}
