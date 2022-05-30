/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 21:11:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// fin de la chaine de checker. imprime OK ou KO et free les stacks
void	ft_end_checker(char *line, t_stk **a, t_stk **b)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}
