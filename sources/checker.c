/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:49:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/25 22:27:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// recoit en argument la liste de nombres et ensuite recoit
// les operations separees par un \n
// applique les operations au fur et a mesure et retourne
// OK si la liste est en ordre
// KO si elle ne l'est pas

int	main(int ac, char **av)
{
	t_stack		*a;
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
	free(ls);
	ft_assign_indexes(&a);
	ft_listen_to_stdin(a);
}
