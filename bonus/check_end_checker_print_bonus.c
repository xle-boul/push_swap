/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker_print_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:01:29 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_end_checker_print(char *line, t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
	{
		ft_printf("\n===== Result =====\n");
		ft_print_list(*a, 'A');
		ft_printf("OK\n");
		ft_operations_counter(NULL, 'c', 2);
	}
	else
		ft_printf("KO\n");
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}
