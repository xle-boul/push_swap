/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 23:12:27 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../ft_printf/header/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# define NUMS "0123456789"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

void	ft_error_handler(int error);
t_stack	*ft_arg_to_chained_list(int *ls, t_stack *head_a, int count);
t_stack	*ft_create_new_node(int	num);
void	ft_add_at_tail(t_stack **head_a, t_stack *new);
int		ft_check_arguments(char *str);
int		ft_check_doubles(int *ls, int count);
void	ft_free_list(t_stack *head_a);

void	swap_a(t_stack *head_a);
void	push_a(t_stack *head_a, t_stack *head_b);
void	rotate_a(t_stack *head_a);
void	reverse_rotate_a(t_stack *head_a);

void	swap_b(t_stack *head_b);
void	push_b(t_stack *head_a, t_stack *head_b);
void	rotate_b(t_stack *head_b);
void	reverse_rotate_b(t_stack *head_b);

void	ss(t_stack *head_a, t_stack *head_b);
void	rr(t_stack *head_a, t_stack *head_b);
void	rrr(t_stack *head_a, t_stack *head_b);

#endif