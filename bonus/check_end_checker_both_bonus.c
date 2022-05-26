/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker_both_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 11:59:17 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_error_handler_checker(char *line, t_stack **a, t_stack **b)
{
	ft_printf("Error\nbad input\n");
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_FAILURE);
}

void	ft_end_checker(char *line, t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
	{
		ft_printf(GREEN"\n===== Result =====\n"END);
		ft_print_list(*a, 'A');
		ft_printf(GREEN"OK\n");
		ft_operations_counter(NULL, 'c', 2);
		ft_printf(END);
	}
	else
		ft_printf(RED"KO\n"END);
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}
