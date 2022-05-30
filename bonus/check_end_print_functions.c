/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_print_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:14:31 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 00:38:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

// prend en charge les flags -c et -n
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

// prend en compte le flag -c seul
void	ft_simple_end_print(t_bool bl)
{
	if (bl.color == false)
		ft_printf("\nKO\n");
	else
		ft_printf(RED"\nKO\n"END);
}

// prend en compte les flags -i et -c
void	ft_end_index_print(t_bool bl, t_stk *a)
{
	if (bl.index == true)
	{
		if (bl.color == false)
		{
			ft_printf("\n\t Result: displaying indexes\nStack A = ");
			ft_print_list_index(a);
		}
		else
		{
			ft_printf("\n\t"RED"Result: displaying indexes\n"END
				""BLUE"Stack A = "END""GREEN);
			ft_print_list_index(a);
			ft_printf(END);
		}
	}
}
