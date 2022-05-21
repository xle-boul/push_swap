/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:56:49 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 10:42:21 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// divise la liste complete en 2 parties, pousse les elements de la moitie
// inferieure vers B en les divisant selon le median.
// 	les plus petits et egal passent en bas
// 	les plus grands passent en haut
void	ft_quick_sort_step_1(t_stack **a, t_stack **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if ((*a)->idx <= s.max
			&& (*a)->idx >= s.min)
		{
			push(b, a, 'b');
			if ((*b)->idx <= s.median)
				rotate(b, 'b');
			s.number_of_el_to_pass--;
		}
		else
			rotate(a, 'a');
	}
}

// divise une seconde fois la demi liste passee en B.
// applique le meme principe que le step 1 mais de B vers A.
// avec la moitie la demi-liste
void	ft_quick_sort_step_2(t_stack **a, t_stack **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if ((*b)->idx <= s.max
			&& (*b)->idx >= s.min)
		{
			push(a, b, 'a');
			if ((*a)->idx <= s.median)
				rotate(a, 'a');
			s.number_of_el_to_pass--;
		}
		else
			rotate(b, 'b');
	}
}

// divise une derniere fois la portion de liste en 2 vers A.
// les classe une fois de plus selon l'ordre de grandeur
// 	les plus petits ou egal a la mediane en haut
// 	les plus grands que la mediane en bas
void	ft_quick_sort_step_3(t_stack **a, t_stack **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if ((*a)->idx <= s.max
			&& (*a)->idx >= s.min)
		{
			push(b, a, 'b');
			if ((*b)->idx > s.median)
				rotate(b, 'b');
			s.number_of_el_to_pass--;
		}
		else
			rotate(a, 'a');
	}
}

// divise une seconde fois la demi liste passee en B.
// applique le meme principe que le step 1 mais de B vers A.
// avec la moitie la demi-liste
void	ft_quick_sort_step_4(t_stack **a, t_stack **b, t_index s)
{
	while (s.number_of_el_to_pass > 0)
	{
		if ((*b)->idx <= s.max
			&& (*b)->idx >= s.min)
		{
			push(a, b, 'a');
			if ((*a)->idx > s.median)
				rotate(a, 'a');
			s.number_of_el_to_pass--;
		}
		else
			rotate(b, 'b');
	}
}

