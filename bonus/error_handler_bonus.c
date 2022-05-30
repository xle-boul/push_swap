/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 21:13:26 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
		ft_printf("Error\nPlease insert more than one number as argument\n");
	if (error == 1)
		ft_printf("Error\nPlease only provide numbers to arguments\n");
	if (error == 2)
		ft_printf("Error\nPlease make sure every number is unique\n");
	if (error == 3)
		ft_printf("Error\nAll numbers are NOT in scope (int)\n");
	if (error == 4)
		ft_printf("Error\nMalloc failed\n");
	if (ls != NULL)
		free(ls);
	exit(EXIT_FAILURE);
}

void	ft_error_handler_free(int error, t_stack *head)
{
	if (error == 0)
		ft_printf("Error\nmalloc failed at ft_list_create\n");
	ft_free_list(head);
	exit(EXIT_FAILURE);
}
