/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:56:53 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sort du programme proprement, en liberant la memoire allouee
void	ft_fini(t_stk *a, t_stk *b)
{
	ft_free_list(a);
	ft_free_list(b);
	exit (EXIT_SUCCESS);
}
