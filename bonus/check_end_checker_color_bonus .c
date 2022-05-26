/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_checker_color_bonus .c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:49:34 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 01:28:05 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_end_checker_color(char *line, t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 0 && *b == NULL)
	{
		ft_printf(GREEN"OK\n"END);
	}
	else
		ft_printf(RED"KO\n"END);
	ft_free_list(*a);
	ft_free_list(*b);
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}
