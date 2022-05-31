/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:49:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 10:55:07 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// reprend le code de push_swap pour creer la liste chainee du stack A
void	ft_create_stack(t_stk **a, char **av)
{
	int	count;
	int	i;
	int	*ls;

	count = 0;
	while (av[count])
		if (ft_check_arguments(av[count++]) == -1)
			ft_error_handler_checker(1, NULL);
	ls = malloc(sizeof(int) * count);
	if (!ls)
		ft_error_handler_checker(4, NULL);
	i = -1;
	while (av[++i])
		ls[i] = ft_atoi_ps(av[i]);
	ft_check_doubles(ls, count);
	*a = ft_arg_to_chained_list(ls, count);
	free(ls);
}

// recoit en argument la liste de nombres et ensuite recoit
// les operations separees par un \n
// applique les operations au fur et a mesure et retourne
// OK si la liste est en ordre
// KO si elle ne l'est pas
int	main(int ac, char **av)
{
	t_stk		*a;

	if (ac <= 2)
		return (0);
	ft_create_stack(&a, ++av);
	ft_assign_indexes(&a);
	ft_listen_to_stdin(a);
	return (0);
}
