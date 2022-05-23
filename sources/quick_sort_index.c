/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:58:03 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/23 20:07:26 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// definit les index de la premiere phase du transfer
t_index	ft_set_indexes_first_step(t_stack **head)
{
	t_index	step1;
	int		len;

	len = list_length(*head);
	if (len <= 200)
		step1.passages = 10;
	else
		step1.passages = 18;
	step1.splits = list_length(*head) / step1.passages;
	step1.number_of_el_to_pass = step1.splits * 2;
	step1.min_lo = min_index(*head);
	step1.max_lo = (step1.min_lo + step1.splits) - 1;
	step1.min_hi = step1.max_lo + 1;
	step1.max_hi = step1.min_hi + step1.splits - 1;
	return (step1);
}

t_index	ft_set_indexes_step(t_index s)
{
	t_index step;

	step.splits = s.splits;
	step.number_of_el_to_pass = s.number_of_el_to_pass;
	step.min_lo = s.max_hi + 1;
	step.max_lo = (step.min_lo + step.splits) - 1;
	step.min_hi = step.max_lo + 1;
	step.max_hi = step.min_hi + step.splits - 1;
	return (step);
}

t_index	ft_set_indexes_last_step(t_index s, t_stack *head)
{
	t_index	step;
	
	step.splits = list_length(head) / 2;
	step.number_of_el_to_pass = list_length(head);
	step.min_lo = s.max_hi + 1;
	step.max_lo = (step.min_lo + step.splits) - 1;
	step.min_hi = step.max_lo + 1;
	step.max_hi = max_index(head);
	return (step);
}