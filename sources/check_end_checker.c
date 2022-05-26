/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/25 22:43:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error_handler_checker(char *line, t_stack **a, t_stack **b)
{
	ft_printf("Error\nBad input\n");
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_FAILURE);
}

void	ft_end_checker(char *line, t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
		ft_printf("\nOK\n");
	else
		ft_printf("KO\n");
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_SUCCESS);
}
