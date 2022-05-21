/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:58:03 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 11:40:25 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// definit les index de la premiere phase du transfer
t_index	ft_set_indexes_step1(t_stack **head)
{
	t_index	step1;

	step1.len_hi = list_length(*head) / 2;
	step1.len_lo = list_length(*head) - step1.len_hi;
	step1.number_of_el_to_pass = step1.len_lo;
	step1.max = min_index(*head) + step1.len_lo - 1;
	step1.min = min_index(*head);
	step1.median = (step1.max - step1.min) / 2 + step1.min;
	return (step1);
}

// definit les index pour separer une portion de la liste
	// si h, passe les elements superieurs a la mediane de step1
	// si l, passe les elements inferieurs ou egal a la mediane de step1
t_index	ft_set_indexes_step2(t_stack **head, char c)
{
	t_index	step2;

		step2.len_hi = list_length(*head) / 2;
		step2.len_lo = list_length(*head) - step2.len_hi;
	if (c == 'h')
	{
		step2.number_of_el_to_pass = step2.len_hi;
		step2.max = min_index(*head) + list_length(*head) - 1;
		step2.min = step2.max - step2.len_hi + 1;
	}
	else
	{
		step2.number_of_el_to_pass = step2.len_lo;
		step2.max = min_index(*head) + step2.len_lo - 1;
		step2.min = min_index(*head);
	}
	step2.median = (step2.max - step2.min) / 2 + step2.min;
	return (step2);
}


// definit les index pour separer une portion de la liste
	// si h, passe les elements superieurs a la mediane de step2
	// si l, passe les elements inferieurs ou egal a la mediane de step2
t_index	ft_set_indexes_step3(t_index s, char c)
{
	t_index	step3;

		step3.len_hi = s.number_of_el_to_pass / 2;
		step3.len_lo = s.number_of_el_to_pass - step3.len_hi;
	if (c == 'h')
	{
		step3.number_of_el_to_pass = step3.len_hi;
		step3.max = s.max;
		step3.min = s.median + 1;
	}
	else
	{
		step3.number_of_el_to_pass = step3.len_lo;
		step3.max = s.median;
		step3.min = s.min;
	}
	step3.median = (step3.max - step3.min) / 2 + step3.min;
	return (step3);
}


// definit les index de la seconde et derniere moitie des elements
t_index	ft_set_indexes_step4(t_stack **head, char c)
{
	t_index	step4;

	step4.len_hi = list_length(*head) / 2;
	step4.len_lo = list_length(*head) - step4.len_hi;
	if (c == 'l')
	{
		step4.number_of_el_to_pass = step4.len_lo;
		step4.max = min_index(*head) + step4.len_lo - 1;
		step4.min = min_index(*head);
	}
	else
	{
		step4.number_of_el_to_pass = list_length(*head);
		step4.max = max_index(*head);
		step4.min = min_index(*head);
	}
	step4.median = (step4.max - step4.min) / 2 + step4.min;
	return (step4);
}
