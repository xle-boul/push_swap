/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_transfer_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:20:13 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/16 20:02:15 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* =====================================================
divise la liste en 2 parties egales (attention, la division en c tronque a l'inferieur)
envoie la moitie des elements dans B en les triant de la maniere suivante:
	1/ ceux faisant partie de la portion sous la mediane vont en bas de B
	2/ ceux faisant partie de la portion au dessus de la mediane vont en haut de B
une fois le transfert effectue, avant de relancer la procedure, replacer les elements
si necessaire
===================================================== */

// cree la liste chainee pour stocker les maxima depuis les index
t_data	*ft_create_data(t_index sort_b, t_data *data)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (!node)
		ft_error_handler(0);
	node->med = sort_b.future_median_b;
	node->max = sort_b.future_max_b;
	node->min = sort_b.future_min_b;
	node->to_transfer = sort_b.number_of_el_to_pass;
	node->next = NULL;
	if (data != NULL)
		node->next = data;
	return (node);
}

// calcule les maxima de chaque portion et stock l'information dans
// une liste chainee (data) pour reutiliser plus tard
t_index	ft_transfer_index_init(t_stack *a, t_data **data)
{
	int		future_len_b;
	t_index	sort_b;

	sort_b.number_of_el_to_pass = list_length(a) / 2;
	sort_b.future_len_a = list_length(a) - sort_b.number_of_el_to_pass;
	future_len_b = sort_b.number_of_el_to_pass;
	sort_b.future_min_b = min_index(a);
	sort_b.future_max_b = future_len_b + min_index(a) - 1;
	sort_b.future_median_b = list_length(a) / 4 + min_index(a);
	*data = ft_create_data(sort_b, *data);
	return (sort_b);
}

// fonction qui ramene les elements stockes en bas de la pile B
void	ft_put_order_in_b(t_stack **b, int count)
{
	while (count-- > 0)
		reverse_rotate(b, 'b');
}

// fonction recursive pour completer le transfert des elements vers B.
// Cette fois, les elements les plus grands sont envoyes en bas avant
// d'etre remis en haut, apres transfert du segment
void	ft_transfer_to_b_next(t_stack **a, t_stack **b, t_index sort_b, t_data **data)
{
	int	steps;
	int	count;

	count = 0;
	steps = sort_b.number_of_el_to_pass;
	while (steps > 0)
	{
		if ((*a)->idx <= sort_b.future_median_b)
		{
			push(b, a, 'b');
			steps--;
		}
		else if ((*a)->idx > sort_b.future_median_b
			&& (*a)->idx <= sort_b.future_max_b)
		{
			push(b, a, 'b');
			rotate(b, 'b');
			steps--;
			count++;
		}
		else
			rotate(a, 'a');
	}
	if (list_length(*a) <= 3)
	{
		ft_sort_to_10(a, NULL);
		return ;
	}
	ft_put_order_in_b(b, count);
	ft_transfer_to_b_next(a, b, ft_transfer_index_init(*a, data), data);
}

// premiere serie de transferts vers B. Met directement les plus petits
// elements en bas et les plus gros en haut de B
void	ft_transfer_to_b_start(t_stack **a, t_stack **b, t_index sort_b, t_data **data)
{
	int	steps;

	steps = sort_b.number_of_el_to_pass;
	while (steps > 0)
	{
		if ((*a)->idx <= sort_b.future_median_b)
		{
			push(b, a, 'b');
			if ((*b)->next)
				rotate(b, 'b');
			steps--;
		}
		else if ((*a)->idx > sort_b.future_median_b
			&& (*a)->idx <= sort_b.future_max_b)
		{
			push(b, a, 'b');
			steps--;
		}
		else
			rotate(a, 'a');
	}
	ft_transfer_to_b_next(a, b, ft_transfer_index_init(*a, data), data);
}

// fonction qui initie le transfer des elements vers B en assignant les
// maxima dans la structure t_index et en lancant la fonction sort
void	ft_transfer_to_b_init(t_stack **a, t_stack **b, t_data **data)
{
	t_index	sort_b;
	
	sort_b = ft_transfer_index_init(*a, data);
	ft_transfer_to_b_start(a, b, sort_b, data);
}