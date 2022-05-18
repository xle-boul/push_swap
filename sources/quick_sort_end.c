/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:56:53 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/17 21:34:09 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sort du programme proprement, en liberant la memoire allouee
void	ft_fini(t_stack *a, t_stack *b, t_data *data)
{
	ft_operations_counter(NULL, 0, 2);
	// ft_printf("\n");
	// ft_printf("a = ");
	// ft_print_list(a);
	// ft_printf("b = ");
	// ft_print_list(b);
	ft_free_list(a);
	ft_free_list(b);
	ft_free_list_data(data);
	exit (EXIT_SUCCESS);
}
