/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:49:26 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:13:19 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

bool	ft_check_flags(char  ***av, t_bool *bl)
{
	if ((ft_strncmp(*av[0], "-p", 2) == 0 && ft_strlen(*av[0]) == 2)
		|| (ft_strncmp(*av[0], "-c", 2) == 0 && ft_strlen(*av[0]) == 2))
	{
		if (ft_strncmp(*av[0], "-c", 2) == 0)
			bl->color = true;
		else
			bl->print = true;
		return (true);
	}
	return (false);
}

void	ft_create_chained_list(t_stack **a, char **av)
{
	int	i;
	int	count;
	int	*ls;

	count = 0;
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
	*a = ft_arg_to_chained_list(ls, count);
	free(ls);
	ft_assign_indexes(a);
}

// recoit en argument la liste de nombres et ensuite recoit
// les operations separees par un \n
// applique les operations au fur et a mesure et retourne
// OK si la liste est en ordre
// KO si elle ne l'est pas

int	main(int ac, char **av)
{
	t_stack		*a;
	t_bool		bl;

	bl.color = false;
	bl.print = false;
	if (ac < 3)
		ft_error_handler(0, NULL);
	av++;
	while (ft_check_flags(&av, &bl) == true)
		av++;
	ft_create_chained_list(&a, av);
	if (bl.color == true && bl.print == true)
		ft_listen_to_stdin_both_flags(a);
	else if (bl.color == true && bl.print == false)
		ft_listen_to_stdin_color_flags(a);
	else if (bl.color == false && bl.print == true)
		ft_listen_to_stdin_print_flags(a);
	else
		ft_listen_to_stdin_no_flags(a);
}
