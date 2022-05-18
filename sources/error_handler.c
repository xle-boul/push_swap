/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/14 13:55:19 by xle-boul         ###   ########.fr       */
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

void	ft_pre_conditions(t_stack *a, t_stack *b, t_data *data)
{
	if (last_index(a) < a->idx)
		ft_printf("Error\nLast element in A should be greater than first element in A\nLast = %d, first = %d\n", last_index(a), a->idx);
	// else if (last_index(b) > data->min)
	// 	ft_printf("Error\nLast element of B should be greater than the minimum of the segment\nB = %d, min = %d\n", last_index(b), data->min);
	else if (b->idx > a->idx)
		ft_printf("Error\nFirst element of A should be greater than last element of B\b A = %d B = %d\n", a->idx, b->idx);
	else
		return;
	ft_free_list(a);
	ft_free_list(b);
	ft_free_list_data(data);
	exit(EXIT_FAILURE);
}

void	ft_post_condition(t_stack *a, t_stack *b, int count, t_data *data)
{
	if (count > data->to_transfer)
	{
		ft_printf("Error\nCount should be smaller than the amount of elements to transfer\ncount = %d, xfer = %d\n", count, data->to_transfer);
		ft_free_list(a);
		ft_free_list(b);
		ft_free_list_data(data);
		exit(EXIT_FAILURE);
	}
	return ;
}
