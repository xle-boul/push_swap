/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_listen_to_stdin_no_flags_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:21:11 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:10:57 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_move_from_input_2_no_flags(char *line, t_stack **a, t_stack **b)
{
	if (line[0] == '\0')
		ft_end_checker_no_flags(line, a, b);
	else
		ft_error_handler_checker(line, a, b);
}

void	ft_move_from_input_no_print(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		swap(a, 'c');
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		swap(b, 'c');
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		push(b, a, 'c');
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		push(a, b, 'c');
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		rotate(a, 'c');
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		rotate(b, 'c');
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(a, 'c');
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(b, 'c');
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		swapswap(a, b, 1);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		rotrot(a, b, 1);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		revrotrot(a, b, 1);
	else
		ft_move_from_input_2_no_flags(line, a, b);
}

void	ft_listen_to_stdin_no_flags(t_stack *a)
{
	t_stack	*b;
	char	*line;

	b = NULL;
	if (ft_check_if_sorted(a) == 0 && b == NULL)
			ft_end_checker(NULL, &a, &b);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		ft_move_from_input_no_print(line, &a, &b);
		if (ft_check_if_sorted(a) == 0 && b == NULL)
			ft_end_checker(line, &a, &b);
		free(line);
	}
}
