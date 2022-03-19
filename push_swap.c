/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:53:10 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 22:39:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;
	int		*ls;
	int		i;
	int		count;

	count = 0;
	head_a = NULL;
	if (ac < 3)
		ft_error_handler(0);
	av++;
	while (av[count])
		if (ft_check_arguments(av[count++]) == -1)
			ft_error_handler(1);
	ls = malloc(sizeof(int) * count);
	i = -1;
	while (av[++i])
		ls[i] = ft_atoi(av[i]);
	if (ft_check_doubles(ls, count) == -1)
		ft_error_handler(2);
	head_a = ft_arg_to_chained_list(ls, head_a, count);
	ft_movement_init(head_a);
	ft_free_list(head_a);
}