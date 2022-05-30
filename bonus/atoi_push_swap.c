/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:18:32 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/27 21:13:37 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

typedef struct s_atoi
{
	int						i;	
	long long				lln;
	char					*str_bis;
	int						sign;
}				t_atoi;
/* converts a string to corresponding integer */

static char	*ft_trim_string(const char *str, t_atoi *n)
{
	n->sign = 0;
	n->i = 1;
	if (!str)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n->sign++;
		str++;
	}
	if (n->sign % 2 != 0)
		n->i = -1;
	return ((char *)str);
}

long	ft_atoi_ps(const char *str)
{
	t_atoi	n;

	n.lln = 0;
	n.str_bis = ft_trim_string(str, &n);
	if (!n.str_bis)
		return (0);
	while (48 <= *n.str_bis && *n.str_bis <= 57)
	{
		if (n.i == 1 && (n.lln * 10 + (*n.str_bis - 48)) < n.lln)
			return (-1);
		if (n.i == -1 && (n.lln * 10 + (*n.str_bis - 48)) < n.lln)
			return (0);
		n.lln = n.lln * 10 + (*n.str_bis - 48);
		if (n.i == 1 && n.lln > MAX_INT)
			ft_error_handler(3, NULL);
		else if (n.i == -1 && n.lln * n.i < MIN_INT)
			ft_error_handler(3, NULL);
		n.str_bis++;
	}
	return ((int)(n.lln * n.i));
}
