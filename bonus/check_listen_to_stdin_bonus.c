/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_listen_to_stdin_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:49:12 by xle-boul          #+#    #+#             */
/*   Updated: 2022/05/31 01:07:48 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

// suite de la fonction switch, qui choisit que faire lors
// de la fin des instructions.
// permet de reperer la fin des instructions donnees grace a line[0] == '\0'
void	ft_move_from_input_2(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (line == NULL || line[0] == '\0')
		ft_end_checker(line, a, b, bl);
	else
		ft_error_handler_checker(line, a, b, bl);
}

// fonction switch, sans le flag -p
void	ft_operations_switch(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		swap(a, 'c');
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		swap(b, 'c');
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		push(b, a, 'v');
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		push(a, b, 'c');
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		rotate(a, 'c');
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		rotate(b, 'c');
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(a, 'c');
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(b, 'c');
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		swapswap(a, b, 1);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		rotrot(a, b, 1);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		revrotrot(a, b, 1);
	else
		ft_move_from_input_2(line, a, b, bl);
}

// fonction switch, avec le flag -p present.
void	ft_operations_switch_print(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		swap(a, 'a');
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		swap(b, 'b');
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		push(b, a, 'b');
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		push(a, b, 'a');
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		rotate(a, 'a');
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		rotate(b, 'b');
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(a, 'a');
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		reverse_rotate(b, 'b');
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		swapswap(a, b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		rotrot(a, b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		revrotrot(a, b, 0);
	else
		ft_move_from_input_2(line, a, b, bl);
}

// fonction intermediaire pour appliquer ou non le flag -p.
// appelera la fonction switch pour traiter les instructions
// le printf "\e[A\e[K" sert a remonter d'une ligne et l'effacer
// dans bash. Sinon les inputs sont imprimes et les commandes dans le
// programme aussi, du coup chaque operation se voit imprimee 2 fois
void	ft_move_from_input(char *line, t_stk **a, t_stk **b, t_bool bl)
{
	if (line != NULL && bl.print == true)
	{
		ft_printf("\e[A\e[K");
		ft_operations_switch_print(line, a, b, bl);
		ft_print_both_lists(*a, *b, bl);
	}
	else if (line != NULL && bl.print == false)
		ft_operations_switch(line, a, b, bl);
	else if (line == NULL || line[0] == '\0')
		ft_move_from_input_2(line, a, b, bl);
}

// fonction qui cree une loop infinie qui ecoute sur le STDIN
// utilise get_next_line legerement modifie pour reprendre les operations
// envoie chaque operation (groupe de lettres suivi d'un \n) dans une
// fonction switch qui va trier et appliquer selon la correspondance
// des lettres recues et des differentes operations possibles
void	ft_listen_to_stdin(t_stk **a, t_bool bl)
{
	t_stk	*b;
	char	*line;

	b = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		ft_move_from_input(line, a, &b, bl);
		free(line);
	}
}
