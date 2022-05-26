/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_listen_to_stdin_both_flags_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:49:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:05:48 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_move_from_input_2(char *line, t_stack **a, t_stack **b)
{
	if (line[0] == '\0')
		ft_end_checker(line, a, b);
	else
		ft_error_handler_checker(line, a, b);
}

void	ft_move_from_input(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		swap(a, 'a');
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		swap(b, 'b');
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		push(b, a, 'b');
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		push(a, b, 'a');
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		rotate(a, 'a');
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		rotate(b, 'b');
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(a, 'a');
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(b, 'b');
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		swapswap(a, b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		rotrot(a, b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		revrotrot(a, b, 0);
	else
		ft_move_from_input_2(line, a, b);
}

void	ft_listen_to_stdin_both_flags(t_stack *a)
{
	t_stack	*b;
	char	*line;

	b = NULL;
	ft_printf(GREEN"===== Starting... =====\n"END);
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
