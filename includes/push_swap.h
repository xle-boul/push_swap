/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:56:44 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/19 10:35:24 by xle-boul         ###   ########.fr       */
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

// sert a creer une liste chainee qui va stocker les valeurs
// des differents maxima de chaque segment
typedef struct s_data
{
	int					med;
	int					min;
	int					max;
	int					to_transfer;
	struct s_data		*next;
}				t_data;

// sert a gerer les maxima lors du passage de A vers B
typedef struct s_index
{
	int	number_of_el_to_pass;
	int	future_len_a;
	int	future_median_b;
	int	future_max_b;
	int	future_min_b;
}			t_index;

// contient tous les compteurs pour le quick sort
typedef struct s_counters
{
	int	steps;
	int	count_high_a;
	int	count_high_b;
	int	count_low_a;
	int	count_low_b;
	int	new_med_a;
	int	new_med_b;
	int	count_a;
	int	count_b;
}			t_ct;

// contient tous les maxima des derniers splits
typedef struct s_splits
{
	int	min_low_a;
	int	max_low_a;
	int	min_low_b;
	int	max_low_b;
	int	min_high_a;
	int	max_high_a;
	int	min_high_b;
	int	max_high_b;
	int	med_low_a;
	int	med_low_b;
	int	med_high_a;
	int	med_high_b;
}				t_splits;

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
void	ft_free_list_data(t_data *head);
void	ft_free_list(t_stack *a);
void	ft_operations_counter(char *op, char who, int swtch);
void	ft_fini(t_stack *a, t_stack *b, t_data *data);

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
void	ft_print_data(t_index sort_b);
void	ft_print_med(t_data *head);
void	ft_print_list_index(t_stack *head);
void	ft_print_list(t_stack *head);

// gestion du sort pour toute liste inferieure a 11 elements
void	ft_sort_3(t_stack **head, char who);
void	ft_sort_to_10(t_stack **a, t_stack **b);
void	ft_sort_to_b(t_stack **a, t_stack **b);

// utilitaires du sort < 11
int		from_top(t_stack **head, int num);
int		from_bot(t_stack **head, int num);
int		ft_find_shortest_path(t_stack *head, int num);

// gestion du sort pour toute liste superieure a 11 elements
void	ft_transfer_to_b_init(t_stack **a, t_stack **b, t_data **data);
void	ft_quick_sort_first(t_stack **a, t_stack **b, t_data **data);
void	ft_move_data_pointer(t_data **data);
void	ft_second_split(t_stack **a, t_stack **b, t_data **data);

// utilitaires pour le quick sort
int		max_index(t_stack *head);
int		min_index(t_stack *head);
int		last_index(t_stack *head);
int		ft_next_index(t_stack *head);
void	ft_split_a_even_more(t_stack **a, t_stack **b, t_ct n);
void	ft_split_between_a_and_b(t_stack **a, t_stack **b, t_ct *n);
void	ft_push_to_top_of_a(t_stack **a, t_stack **b, t_ct *n);

// initiateurs de compteurs pour quick sort
t_splits	ft_second_counters_init(t_ct *n, t_data *data);
t_ct	ft_counters_init(t_data *data);

// gestion du classement a proprement parler
void	ft_sort_shit_split(t_stack **a, t_stack **b, int max, int min);

// utilitaires du classement
void	ft_bring_back_from_bottom_a(t_stack **a, int num);
void	ft_test_next_element(t_stack **a, t_stack **b, int *bottom_b);
void	ft_switch(t_stack **b, int swtch, int *bottom_b);

// gestion d'erreurs du quick sort
void	ft_pre_conditions(t_stack *a, t_stack *b, t_data *data);
void	ft_post_condition(t_stack *a, t_stack *b, int count, t_data *data);

int	ft_find_minimum(t_stack **head, int minimum, int target_high);
#endif