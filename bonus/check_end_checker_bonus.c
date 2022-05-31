/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 11:33:52 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_error_handler_checker(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (bl.color == false)
		write(2, "Error\nBad input\n", 17);
	else
		write(2, RED"Error\nBad input\n"END, 28);
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_FAILURE);
}

// fin de la chaine de checker. imprime OK ou KO et free les stacks
// prend en compte les flags pour imprimer l'une ou l'autre information
// dans cette fonction:
	// -c, -d sont pris en compte
void	ft_end_checker(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
	{
		ft_end_index_print(bl, *a);
		ft_end_success_print(bl);
		if (bl.color == false && bl.details == true)
			ft_details_counts(3, 0, 0);
		else if (bl.color == true && bl.details == true)
			ft_details_counts(3, 1, 0);
	}
	else
		ft_simple_end_print(bl);
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}
