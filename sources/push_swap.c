/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:53:10 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 00:40:21 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* =============================== PUSH SWAP ===============================


recoit en argument une serie de nombres
	(uniques et dans le scope de int)

1/ premiere etape de mon projet, convertir les arguments en un
array comprenant chaque nombre dans l'ordre recu.

2/ convertit l'array en une liste doublement chainee et
attribue a chaque element un index d'increment 1 par soucis
de facilite.
	exemple:
	23	87	2	: valeurs recues
==>	1	2	0	: valeurs des index

3/ le projet fonctionne avec 2 facons de trier differentes:
	*)	pour une liste inferieure ou egale a 27 elements
		(nombre determine par tests)
	*)	pour une liste superieure a 27 elements
		3.1/ <= 27 elements:
			se base sur un tri de 3 elements.
			retrouve chaque element par ordre croissant et les
			pousse dans B jusqu'a arriver a 3 elements dans A.
			trie les 3 elements et ramene ensuite tout le reste dans A.
		3.2/ > 27 elements:
 			effectue un tri en 2 etapes:
			*)	de A vers B:
				decoupe la liste en un nombre defini de segments et assigne
				des index (valeurs minimales et maximales de chaque segment)
				recherche ces valeurs et les pousse dans B.
					- les valeurs inferieurs a la mediane du segment passent
					en haut du stack B.
					- les autres en bas.
				On obtient donc un escalier de segments.
			*)	de B ver A:
				recherche le chemin le plus court pour aller trouver l'element
				le plus grand de B.
				parcoure B pour le positionner en tete et le pousse dans A.
				repete jusqu'a vider B.
*/

int	main(int ac, char **av)
{
	t_stk		*a;
	int			*ls;
	int			i;
	int			count;

	count = 0;
	if (ac < 3)
		ft_error_handler(0, NULL);
	av++;
	while (av[count])
		if (ft_check_arguments(av[count++]) == -1)
			ft_error_handler(1, NULL);
	ls = malloc(sizeof(int) * count);
	if (!ls)
		ft_error_handler(4, NULL);
	i = -1;
	while (av[++i])
		ls[i] = ft_atoi_ps(av[i]);
	ft_check_doubles(ls, count);
	a = ft_arg_to_chained_list(ls, count);
	free (ls);
	ft_assign_indexes(&a);
	ft_sort_init(a);
	return (0);
}
