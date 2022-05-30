/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:14:45 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_error_handler_checker(char *line, t_stack **a, t_stack **b, t_bool bl)
{
	if (bl.color == false)
		ft_printf("Error\nBad input\n");
	else
		ft_printf(RED"Error\nBad input\n"END);
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_FAILURE);
}

void	ft_end_success_print(t_bool bl)
{
	if (bl.color == true && bl.ops == true)
	{
		ft_printf(GREEN"\nOK\n");
		ft_printf("Done in %d moves\n"END,
			ft_operations_counter(NULL, 'd', 2));
	}
	else if (bl.color == false && bl.ops == true)
	{
		ft_printf("\nOK\n");
		ft_printf("Done in %d moves\n",
			ft_operations_counter(NULL, 'd', 2));
	}
	else if (bl.color == false && bl.ops == false)
		ft_printf("\nOK\n");
	else if (bl.color == true && bl.ops == false)
		ft_printf(GREEN"\nOK\n"END);
}

void	ft_end_checker(char *line, t_stack **a, t_stack **b, t_bool bl)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
		ft_end_success_print(bl);
	else
	{
		if (bl.color == false)
			ft_printf("\nKO\n");
		else
			ft_printf(RED"\nKO\n"END);
	}
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_SUCCESS);
}
