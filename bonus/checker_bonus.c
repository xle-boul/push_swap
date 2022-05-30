/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:49:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 23:55:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

bool	ft_check_flags(char ***av, t_bool *bl)
{
	if ((ft_strncmp(*av[0], "-p", 2) == 0 && ft_strlen(*av[0]) == 2)
		|| (ft_strncmp(*av[0], "-c", 2) == 0 && ft_strlen(*av[0]) == 2)
		|| (ft_strncmp(*av[0], "-n", 2) == 0 && ft_strlen(*av[0]) == 2))
	{
		if (ft_strncmp(*av[0], "-c", 2) == 0)
			bl->color = true;
		else if (ft_strncmp(*av[0], "-p", 2) == 0)
			bl->print = true;
		else if (ft_strncmp(*av[0], "-n", 2) == 0)
			bl->ops = true;
		return (true);
	}
	return (false);
}

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
	t_bool		bl;
	int			count;

	bl.color = false;
	bl.ops = false;
	bl.print = false;
	count = 0;
	if (ac < 3)
		ft_error_handler(0, NULL);
	av++;
	while (ft_check_flags(&av, &bl) == true)
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
	ft_listen_to_stdin(&a, bl);
}
