/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/30 14:37:35 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/header/ft_printf.h"

# define NUMS "0123456789-+"
# define SWEET_SPOT 27
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

// sert a gerer les maxima lors des passages entre A et B
typedef struct s_index
{
	int	number_of_el_to_pass;
	int	splits;
	int	max_hi;
	int	max_lo;
	int	min_hi;
	int	min_lo;
	int	passages;
}			t_index;

// operations possibles
void	swap(t_stk **head, char who);
void	push(t_stk **head_dest, t_stk **head_orig, char who);
void	rotate(t_stk **head, char who);
void	reverse_rotate(t_stk **head, char who);
void	swapswap(t_stk **a, t_stk **b, int swtch);
void	rotrot(t_stk **a, t_stk **b, int swtch);
void	revrotrot(t_stk **a, t_stk **b, int swtch);

// lire les arguments et les traduire en liste chainee
t_stk	*ft_arg_to_chained_list(int *ls, int count);
void	ft_assign_indexes(t_stk **head);
int		ft_check_arguments(char *str);
void	ft_check_doubles(int *ls, int count);

// gestion des erreurs et free
void	ft_error_handler(int error, int *ls);
void	ft_error_handler_free(int error, t_stk *head);
void	ft_free_list(t_stk *a);
void	ft_operations_counter(char *op, char who, int swtch);
void	ft_fini(t_stk *a, t_stk *b);

// utilitaires pour trouver des index et/ou des positions
int		max(t_stk *head);
int		min(t_stk *head);
int		min_value(t_stk *head);
int		list_length(t_stk *head);
int		next_num(t_stk *head, int num);
t_stk	*first_node(t_stk **head);
t_stk	*last_node(t_stk **head);
int		from_top(t_stk **head, int num);
int		from_bot(t_stk **head, int num);
int		last_index(t_stk *head);
int		next_index(t_stk *head);
int		ft_check_if_sorted(t_stk *head);
int		ft_is_in_list(t_stk **head, int num);
int		ft_find_shortest_path(t_stk *head, int num);

// prints
void	ft_print_both_lists(t_stk *a, t_stk *b);
void	ft_print_list_index(t_stk *head);
void	ft_print_list(t_stk *head, char color);

// gestion du sort pour toute liste inferieure a 28 elements
void	ft_sort_init(t_stk *a);
void	ft_sort_3(t_stk **head, char who);
void	ft_sort_to_27(t_stk **a, t_stk **b);
void	ft_sort_to_b(t_stk **a, t_stk **b);

// assignation des index
t_index	ft_set_indexes_first_step(t_stk **head);
t_index	ft_set_indexes_step(t_index s);
t_index	ft_set_indexes_last_step(t_index s, t_stk *head);

// gestion du sort
void	ft_transfer_to_b(t_stk **a, t_stk **b, t_index s);
void	ft_bring_back_to_a(t_stk **a, t_stk **b);
void	ft_reassort_a(t_stk **a, t_stk **b, t_index s);
void	ft_reassort_a_and_b(t_stk **a, t_stk **b, t_index s, t_index t);
void	ft_reassemble_init(t_stk **a, t_stk **b);

// atoi adapte
long	ft_atoi_ps(const char *str);
#endif