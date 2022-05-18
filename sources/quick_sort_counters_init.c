/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_counters_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:22 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/18 11:39:55 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// reprend les donnees des differents sous-segments pour un usage ulterieur
t_splits	ft_second_counters_init(t_ct *n, t_data *data)
{
	t_splits	s;

	s.min_low_a = data->min;
	s.min_high_a = s.min_low_a + n->count_low_a;
	s.min_low_b = s.min_high_a + n->count_high_a;
	s.min_high_b = s.min_low_b + n->count_low_b;
	s.max_low_a = s.min_high_a - 1;
	s.max_high_a = s.min_low_b - 1;
	s.max_low_b = s.min_high_b - 1;
	s.max_high_b = data->max;
	return (s);
}

// prepare la structure t_ct qui gère les compteurs des differents segments
t_ct	ft_counters_init(t_data *data)
{
	t_ct	n;
	
	n.steps = data->to_transfer;
	n.count_high_a = 0;
	n.count_high_b = 0;
	n.count_low_a = 0;
	n.count_low_b = 0;
	n.new_med_a = n.steps / 4 + data->min;
	n.new_med_b = n.steps / 4 + data->med;
	return (n);
}