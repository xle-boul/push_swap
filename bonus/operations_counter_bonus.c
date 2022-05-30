/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_counter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:25:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 01:12:36 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

// compte le nombre d'operations effectuees et les imprime sur
// la sortie standard
int	ft_operations_counter(char *op, char who, int swtch)
{
	static int	count = 0;

	if (swtch == 0)
	{
		if (who == 'a')
			ft_printf("%s%c\n", op, who);
		else if (who == 'b')
			ft_printf("%s%c\n", op, who);
		if (who == 'c' || who == 'a' || who == 'b' || who == 'v')
			count++;
	}
	else if (swtch == 1)
	{
		ft_printf("%s\n", op);
		count++;
	}
	return (count);
}

void	ft_details_counts(int swtch, int color, int who)
{
	static int	b_count = 0;
	static int	rr_count = 0;
	static int	rrr_count = 0;

	if ((swtch == 0 && who == 'b') || (swtch == 0 && who == 'v'))
		b_count++;
	else if (swtch == 1)
		rr_count++;
	else if (swtch == 2)
		rrr_count++;
	else if (swtch == 3)
		ft_print_details(color, b_count, rr_count, rrr_count);
}
