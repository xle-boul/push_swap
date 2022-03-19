# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:16:31 by xle-boul          #+#    #+#              #
#    Updated: 2022/03/19 15:54:31 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
RESET	= \033[0m
END		= \e[0m

NAME = push_swap

NAME_CHK = checker

SRC_DIR := sources
CHK_DIR := checker

OBJ_DIR := obj
CHK_OBJ_DIR := obj_checker

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) push_swap.c
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
SRC_CHK := $(wildcard $(CHK_DIR)/*.c) checker.c
OBJ_CHK := $(patsubst $(CHK_DIR)/%.c,$(CHK_OBJ_DIR)/%.o,$(SRC_CHK))

CC = gcc
FLAGS = -Werror -Wall -Wextra

INCLUDES = includes
HEADER = push_swap.h
HEADER_CHK = checker.h

LIB_DIR = ft_printf/
LIB_OBJS_DIR = ft_printf/objs/
LIB = libftprintf.a

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)/$(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(CHK_OBJ_DIR)/%.o : $(CHK_DIR)/%.c $(INCLUDES)/$(HEADER_CHK)
	@mkdir -p $(CHK_OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES) $(LIB)
	@printf "\n$(YELLOW)Compiling push_swap...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_FILES) $(LIB) -I $(INCLUDES) -o $@
	@printf "\n$(GREEN)push_swap compiled!\n$(END)Run program: $(RED)./push_swap <numbers>\n$(END)"

$(NAME_CHK): $(OBJ_CHK) $(LIB)
	@printf "\n$(YELLOW)Compiling checker...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_CHK) $(LIB) -I $(INCLUDES) -o $(NAME_CHK)
	@printf "\n$(GREEN)checker compiled!\n$(END)Run program: $(RED)./checker$(END)"

$(LIB):
	@printf "\n$(YELLOW)Compiling $(LIB)...$(END)\n"
	@make bonus --no-print-directory $(LIB) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

all: $(NAME)

clean:
	@printf "\n$(YELLOW)Cleaning objects and $(NAME)...$(END)\n"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "\n$(YELLOW)Cleaning $(LIB) and $(LIB_MLX)...$(END)\n"
	@rm -f $(LIB)
	@make --no-print-directory -C $(LIB_DIR) fclean

re: fclean $(NAME)

checker: $(NAME_CHK)

checker_clean:
	@printf "\n$(YELLOW)Cleaning objects and $(NAME_CHK)...$(END)\n"
	@rm -f $(NAME_CHK)
	@rm -rf $(CHK_OBJ_DIR)

checker_fclean: bonus_clean
	@printf "\n$(YELLOW)Cleaning $(LIB) and $(LIB_MLX)...$(END)\n"
	@rm -rf $(LIB)
	@rm -f $(LIB_MLX)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@make --no-print-directory -C $(MLX_DIR) clean
	
bonus_re: bonus_fclean bonus

norm:
	@norminette *.c sources bonus ft_printf includes

clean_all: fclean bonus_fclean

help:
	@printf "$(RED)Makefile rules:$(END)\n\n"
	@printf "$(CYAN)'make'$(END): \t\tCompile mandatory part\n"
	@printf "$(CYAN)'make clean'$(END): \t\tGet rid of mandatory objects and program\n"
	@printf "$(CYAN)'make fclean'$(END): \t\tGet rid of mandatory objects, program and libraries\n"
	@printf "$(CYAN)'make re'$(END): \t\tGet rid of everything and recompile mandatory part\n\n"
	@printf "$(MAGENTA)'make bonus'$(END): \t\tCompile bonus part\n"
	@printf "$(MAGENTA)'make bonus_clean'$(END): \tGet rid of bonus objects and program\n"
	@printf "$(MAGENTA)'make bonus_fclean'$(END): \tGet rid of bonus objects, program and libraries\n"
	@printf "$(MAGENTA)'make bonus_re'$(END): \tGet rid of everything and recompile bonus part\n\n"
	@printf "$(YELLOW)'make norm'$(END): \t\tCheck norminette\n"
	@printf "$(YELLOW)'clean_all'$(END): \t\tReset folder\n"

.PHONY: clean fclean bonus_re bonus_clean bonus_fclean re clean-all norm help