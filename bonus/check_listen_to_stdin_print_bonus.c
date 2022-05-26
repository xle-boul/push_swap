/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_listen_to_stdin_print_bonus copy.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:49:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:06:01 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_listen_to_stdin_print_flags(t_stack *a)
{
	t_stack	*b;
	char	*line;

	b = NULL;
	ft_printf("===== Starting... =====\n");
	ft_print_list(a, 'A');
	if (ft_check_if_sorted(a) == 0 && b == NULL)
			ft_end_checker(NULL, &a, &b);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		ft_move_from_input(line, &a, &b);
		if (ft_check_if_sorted(a) == 0 && b == NULL)
			ft_end_checker(line, &a, &b);
		free(line);
		ft_print_both_lists(a, b);
	}
}
