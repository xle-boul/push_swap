/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/20 22:04:57 by xle-boul         ###   ########.fr       */
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
			ft_error_handler(1);
		i++;
	}
	return (0);
}

int	ft_check_doubles(int *ls, int count)
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
			ft_error_handler(2);
		i++;
	}
	return (0);
}

void	ft_error_handler(int error)
{
	if (error == 0)
		ft_printf("Error\nPlease insert more than one number as argument\n");
	if (error == 1)
		ft_printf("Error\nPlease only provide numbers to arguments\n");
	if (error == 2)
		ft_printf("Error\nPlease make sure every number is unique\n");
	if (error == 3)
		ft_printf("Error\nDidn't bring back correctly from B\n");
	if (error == 4)
		ft_printf("Error\n>Ta mere\n");
	exit(EXIT_FAILURE);
}
