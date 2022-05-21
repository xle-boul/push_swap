/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/21 11:40:13 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../ft_printf/header/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# define NUMS "0123456789-+"


// sert a creer et gerer la liste chainee des elements dans A et B
typedef struct s_stack
{
	int				num;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// sert a gerer les maxima lors des passages entre A et B
typedef struct s_index
{
	int	number_of_el_to_pass;
	int	len_hi;
	int	len_lo;
	int	median;
	int	max;
	int	min;
}			t_index;

// operations possibles
void	swap(t_stack **head, char who);
void	push(t_stack **head_dest, t_stack **head_orig, char who);
void	rotate(t_stack **head, char who);
void	reverse_rotate(t_stack **head, char who);
void	swapswap(t_stack **a, t_stack **b);
void	rotrot(t_stack **a, t_stack **b);
void	revrotrot(t_stack **a, t_stack **b);

// lire les arguments et les traduire en liste chainee
void	ft_sort_error_handler(int error, t_stack **a, t_stack **b);
t_stack	*ft_arg_to_chained_list(int *ls, int count);
t_stack	*ft_create_new_node(int num);
void	ft_add_at_tail(t_stack **a, t_stack *new);
void	ft_assign_indexes(t_stack **head);
int		ft_check_arguments(char *str);
int		ft_check_doubles(int *ls, int count);
void	ft_sort_init(t_stack *a, int ac);

// gestion des erreurs et free
void	ft_error_handler(int error);
void	ft_free_list(t_stack *a);
void	ft_operations_counter(char *op, char who, int swtch);
void	ft_fini(t_stack *a, t_stack *b);

// utilitaires pour trouver des index et/ou des positions
int		max(t_stack *head);
int		min(t_stack *head);
int		top(t_stack *head, int num);
int		bot(t_stack *head, int num);
int		list_length(t_stack *head);
int		next_num(t_stack *head, int num);
int		ft_check_if_sorted(t_stack *head);
int		ft_is_in_list(t_stack **head, int num);
t_stack	*first_node(t_stack **head);
t_stack	*last_node(t_stack **head);

// prints
void	ft_print_both_lists(t_stack *a, t_stack *b);
void	ft_print_list_index(t_stack *head);
void	ft_print_list(t_stack *head);
void	ft_print_index(t_index s);

// gestion du sort pour toute liste inferieure a 11 elements
void	ft_sort_3(t_stack **head, char who);
void	ft_sort_to_10(t_stack **a, t_stack **b);
void	ft_sort_to_b(t_stack **a, t_stack **b);

// utilitaires du sort < 11
int		from_top(t_stack **head, int num);
int		from_bot(t_stack **head, int num);
int		ft_find_shortest_path(t_stack *head, int num);

// gestion du sort pour toute liste superieure a 11 elements
void	ft_quick_sort_hub(t_stack **a, t_stack **b);
void	ft_quick_sort_first_part(t_stack **a, t_stack **b);
void	ft_quick_sort_second_part(t_stack **a, t_stack **b);


// gestion des mouvements de la premiere partie de quick sort
void	ft_push_to_top(t_stack **head, t_index s);
void	ft_push_to_bottom(t_stack **head, t_index s);
void	ft_quick_sort_step_1(t_stack **a, t_stack **b, t_index step1);
void	ft_quick_sort_step_2(t_stack **a, t_stack **b, t_index step2);
void	ft_quick_sort_step_3(t_stack **a, t_stack **b, t_index step3);
void	ft_quick_sort_step_4(t_stack **a, t_stack **b, t_index step4);
t_index	ft_set_indexes_step1(t_stack **head);
t_index	ft_set_indexes_step2(t_stack **head, char c);
t_index	ft_set_indexes_step3(t_index s, char c);
t_index	ft_set_indexes_step4(t_stack **head, char c);

// utilitaires pour le quick sort
int		max_index(t_stack *head);
int		min_index(t_stack *head);
int		last_index(t_stack *head);
int		ft_next_index(t_stack *head);
void	ft_reassort_a(t_stack **a, t_stack **b, t_index s);
void	ft_reassort_a_and_b(t_stack **a, t_stack **b, t_index s, t_index t);
void	ft_empty_a(t_stack **a, t_stack **b);

#endif