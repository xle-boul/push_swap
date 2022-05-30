/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 14:11:35 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_printf/header/ft_printf.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define NUMS "0123456789-+"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

// sert a creer et gerer la liste chainee des elements dans A et B
typedef struct s_stack
{
	int				num;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stk;

typedef struct s_bool
{
	bool	color;
	bool	print;
	bool	ops;
}				t_bool;

// get next line
char	*get_next_line(int fd);

// atoi specialement pour push_swap
long	ft_atoi_ps(const char *str);

// fonctions de check
void	ft_error_handler(int error, int *ls);
void	ft_error_handler_free(int error, t_stk *head);
void	ft_error_handler_checker(char *line, t_stk **a, t_stk **b, t_bool bl);
void	ft_check_doubles(int *ls, int count);
int		ft_check_arguments(char *str);

// fonctions de fin de programme
int		ft_check_if_sorted(t_stk *head);
void	ft_free_array(int **splits, int max);
void	ft_free_list(t_stk *head);
int		ft_operations_counter(char *op, char who, int swtch);

// fonction qui impriment
void	ft_print_list(t_stk *head, char color, t_bool bl);
void	ft_print_list_index(t_stk *head);
void	ft_print_both_lists(t_stk *a, t_stk *b, t_bool bl);

// operations imposees
void	swap(t_stk **head, char who);
void	push(t_stk **head_dest, t_stk **head_orig, char who);
void	rotate(t_stk **head, char who);
void	reverse_rotate(t_stk **head, char who);
void	swapswap(t_stk **a, t_stk **b, int swtch);
void	rotrot(t_stk **a, t_stk **b, int swtch);
void	revrotrot(t_stk **a, t_stk **b, int swtch);

// lire les arguments et les traduire en liste chainee
int		max_value(t_stk *head);
t_stk	*ft_arg_to_chained_list(int *ls, int count);
void	ft_assign_indexes(t_stk **head);
int		min_value(t_stk *head);
int		next_num(t_stk *head, int num);

// fonction qui ecoute sur l'entree standard (avec les 2 flags)
void	ft_listen_to_stdin(t_stk **a, t_bool bl);
void	ft_move_from_input(char *line, t_stk **a, t_stk **b, t_bool bl);
void	ft_move_from_input_2(char *line, t_stk **a, t_stk **b, t_bool bl);
void	ft_end_checker(char *line, t_stk **a, t_stk **b, t_bool bl);

#endif