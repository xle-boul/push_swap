/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:26:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 13:34:04 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_bad_input(char *line, t_stk **a, t_stk **b)
{
	write(1, "Error\nBad input\n", 17);
	ft_free_list(*a);
	ft_free_list(*b);
	free(line);
	exit(EXIT_FAILURE);
}

void	ft_error_handler_checker(int error, int *ls)
{
	if (error == 0)
		write(1, "Error\nPlease insert more than one number as argument\n", 54);
	if (error == 1)
		write(1, "Error\nPlease only provide numbers to arguments\n", 48);
	if (error == 2)
		write(1, "Error\nPlease make sure every number is unique\n", 47);
	if (error == 3)
		write(1, "Error\nAll numbers are NOT in scope (int)\n", 42);
	if (error == 4)
		write(1, "Error\nMalloc failed\n", 21);
	if (ls != NULL)
		free(ls);
	exit(EXIT_FAILURE);
}

void	ft_error_handler_free_checker(int error, t_stk *head)
{
	if (error == 0)
		write(1, "Error\nmalloc failed at ft_list_create\n", 39);
	ft_free_list(head);
	exit(EXIT_FAILURE);
}
