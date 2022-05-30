/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_counter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:25:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 21:41:08 by xle-boul         ###   ########.fr       */
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
		if (who == 'c' || who == 'a' || who == 'b')
			count++;
	}
	else if (swtch == 1)
	{
		ft_printf("%s\n", op);
		count++;
	}
	return (count);
}
