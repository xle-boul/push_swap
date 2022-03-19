/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:13 by xle-boul         ###   ########.fr       */
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
		while(NUMS[j])
		{
			if (str[i] == NUMS[j])
				check++;
			j++;
		}
		if (check != 1)
			return (-1);
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
			return (-1);
		i++;
	}
	return (0);
}

void	ft_error_handler(int error)
{
	if (error == 0)
		ft_printf("Error\nPlease insert more than one number as argument");
	if (error == 1)
		ft_printf("Error\nPlease only provide numbers to arguments");
	if (error == 2)
		ft_printf("Error\nPlease make sure every number is unique");
	exit(EXIT_FAILURE);
}