/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/26 12:10:48 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_printf/header/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "get_next_line.h"

# define NUMS "0123456789-+"

// sert a creer et gerer la liste chainee des elements dans A et B
typedef struct s_stack
{
	int				num;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_bool
{
	bool	color;
	bool	print;
}				t_bool;


// get next line
char	*get_next_line(int fd);

// atoi specialement pour push_swap
long	ft_atoi_ps(const char *str);

// fonctions de check
void	ft_check_doubles(int *ls, int count);
void	ft_error_handler(int error, int *ls);
void	ft_error_handler_checker(char *line, t_stack **a, t_stack **b);
int		ft_check_arguments(char *str);
void	ft_error_handler_checker_color(char *line, t_stack **a, t_stack **b);

// fonctions de fin de programme
int		ft_check_if_sorted(t_stack *head);
void	ft_end_checker(char *line, t_stack **a, t_stack **b);
void	ft_free_array(int **splits, int max);
void	ft_free_list(t_stack *head);
void	ft_operations_counter(char *op, char who, int swtch);

// fonction qui impriment
void	ft_print_list(t_stack *head, char color);
void	ft_print_list_index(t_stack *head);
void	ft_print_both_lists(t_stack *a, t_stack *b);

// operations imposees
void	swap(t_stack **head, char who);
void	push(t_stack **head_dest, t_stack **head_orig, char who);
void	rotate(t_stack **head, char who);
void	reverse_rotate(t_stack **head, char who);
void	swapswap(t_stack **a, t_stack **b,int swtch);
void	rotrot(t_stack **a, t_stack **b, int swtch);
void	revrotrot(t_stack **a, t_stack **b, int swtch);

// lire les arguments et les traduire en liste chainee
t_stack	*ft_arg_to_chained_list(int *ls, int count);
void	ft_assign_indexes(t_stack **head);

// fonction qui ecoute sur l'entree standard (avec les 2 flags)
void	ft_listen_to_stdin_both_flags(t_stack *a);
void	ft_move_from_input(char *line, t_stack **a, t_stack **b);
void	ft_move_from_input_2(char *line, t_stack **a, t_stack **b);

// avec le flag print seulement
void	ft_listen_to_stdin_print_flags(t_stack *a);
void	ft_end_checker_print(char *line, t_stack **a, t_stack **b);

// avec le flag color seulement
void	ft_listen_to_stdin_color_flags(t_stack *a);
void	ft_move_from_input_no_print(char *line, t_stack **a, t_stack **b);
void	ft_end_checker_color(char *line, t_stack **a, t_stack **b);

// sans flags
void	ft_end_checker_no_flags(char *line, t_stack **a, t_stack **b);
void	ft_listen_to_stdin_no_flags(t_stack *a);

#endif