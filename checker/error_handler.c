/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:54:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/19 15:50:25 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error_handle(int error)
{
	if (error == 0)
		ft_printf("Error\nPlease insert more than one number as argument");
	exit(EXIT_FAILURE);
}
