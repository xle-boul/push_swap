/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 13:24:21 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_arguments(char *str)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (str[i])
	{
		check = 0;
		j = 0;
		while (str[i] == '-' || str[i] == '+')
			i++;
		while (NUMS[j])
		{
			if (str[i] == NUMS[j])
				check++;
			j++;
		}
		if (check != 1)
			ft_error_handler(1, NULL);
		i++;
	}
	return (0);
}

void	ft_check_doubles(int *ls, int count)
{
	int	i;
	int	j;
	int	doubles;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		doubles = 0;
		while (j < count)
		{
			if (ls[i] == ls[j])
				doubles++;
			j++;
		}
		if (doubles != 0)
			ft_error_handler(2, ls);
		i++;
	}
}

void	ft_error_handler(int error, int *ls)
{
	if (error == 0)
		write(2, "Error\nPlease insert more than one number as argument\n", 54);
	if (error == 1)
		write(2, "Error\nPlease only provide numbers to arguments\n", 48);
	if (error == 2)
		write(2, "Error\nPlease make sure every number is unique\n", 47);
	if (error == 3)
		write(2, "Error\nAll numbers are NOT in scope (int)\n", 42);
	if (error == 4)
		write(2, "Error\nMalloc failed\n", 21);
	if (ls != NULL)
		free(ls);
	exit(EXIT_FAILURE);
}

void	ft_error_handler_free(int error, t_stk *head)
{
	if (error == 0)
		write(2, "Error\nmalloc failed at ft_list_create\n", 39);
	ft_free_list(head);
	exit(EXIT_FAILURE);
}
