/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_counter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:25:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 00:33:42 by xle-boul         ###   ########.fr       */
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

void	ft_print_details(int color, int b_count, int rr_count, int rrr_count)
{
	if (color == 0)
	{
		ft_printf("\t%d items were transferred to B stack during the sort\n",
			b_count);
		ft_printf("\tSaved %d operations with 'rr'\n", rr_count);
		ft_printf("\tSaved %d operations with 'rrr'\n", rrr_count);
		ft_printf("\tOptimized %d operations total\n", rr_count + rrr_count);
	}
	else
	{
		ft_printf(MAGENTA
			"\t%d items were transferred to B stack during the sort\n"
			END, b_count);
		ft_printf(YELLOW"\tSaved %d operations with 'rr'\n"END, rr_count);
		ft_printf(CYAN"\tSaved %d operations with 'rrr'\n"END, rrr_count);
		ft_printf(GREEN
			"\tOptimized %d operations total\n"END, rr_count + rrr_count);
	}
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
