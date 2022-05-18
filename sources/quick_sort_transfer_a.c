/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_transfer_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:03:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/17 21:37:19 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* =====================================================
Arguments:

lance la fonction de tri

scanner le segment (len_tot mouvements vers A) et pour chaque element:
	cas1) envoyer en tete de A s'il est plus grand que median
	cas2) envoyer qu fond de A s'il est plus petit que median
lancer un second scan a partir de la sequence creee a partir de cas1;
	cas1) envoyer en tete de B tout ce qui est plus petit que new median
	cas2) envoyer en tete de B tout ce qui est plus grand que new median
remonter la partie inferieure de B et de A
lancer encore un scan a partir de la sequence creee a partir de cas2;
	cas1) envoyer en tete de B tout ce qui est plus petit que new median
	cas2) envoyer en tete de B tout ce qui est plus grand que new median

A ce stade, tout se retrouve dans B mais beaucoup mieux trie. Reste qu'a envoyer
une fonction clean-up.
	
ensuite:
	step1) classer tout ce qui est encore dans B (superieur ou egal au median)
	step2) renvoyer ce qu'on a mis dans A (inferieur au median) dans B
	step3) relancer la fonction de tri avec les donnees des elements revenus de A

post-conditions: dans error_handler.c
compteur doit etre < len_tot

sinon rappeler la meme fonction avec len_tot = compteur
===================================================== */

// deplacer le pointeur de data pour pointer sur les donnees correctes
// free la memoire du chainon utilise

void	ft_move_data_pointer(t_data **data)
{
	t_data	*tmp;

	tmp = (*data);
	(*data) = (*data)->next;
	free (tmp);
}

void	ft_seek_next_element(t_stack **head, int target)
{
	int	rot;
	if (ft_is_in_list(head, target) == 0)
	{
		rot = ft_find_shortest_path(*head, target);
		if (rot > 0)
			while (rot-- > 0)
				rotate(head, 'b');
		else if (rot < 0)
			while (rot++ < 0)
				reverse_rotate(head, 'b');
	}
}

void	ft_init_quick_sort(t_stack **a, t_stack **b, t_data **data)
{
	int	steps;
	
	steps = (*data)->to_transfer;
	while (steps > 0)
	{
		if ((*b)->idx == (*a)->idx - 1)
		{
			push(a, b, 'a');
			steps--;
		}
		else if ((*b)->next->idx == (*a)->idx - 1)
			swap(b, 'b');
		else
			ft_seek_next_element(b, (*a)->idx - 1);
	}
	ft_move_data_pointer(data);
}

void	ft_quick_sort_first(t_stack **a, t_stack **b, t_data **data)
{
	while ((*data)->to_transfer < 10)
		ft_init_quick_sort(a, b, data);
	while (*b != NULL)
		ft_second_split(a, b, data);
	ft_fini(*a, *b, *data);
}