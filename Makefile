# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:16:31 by xle-boul          #+#    #+#              #
#    Updated: 2022/05/25 23:38:15 by xle-boul         ###   ########.fr        #
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
NAME_CHK_BONUS = checker_bonus

SRC_DIR := sources
CHK_DIR := sources
BONUS_DIR := bonus

OBJ_DIR := obj_ps
CHK_OBJ_DIR := obj_checker
BONUS_OBJ_DIR := obj_bonus

SRC_FILES := $(filter-out $(wildcard $(SRC_DIR)/get_next_line* $(SRC_DIR)/check*),$(wildcard $(SRC_DIR)/*.c))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
SRC_CHK := $(filter-out $(wildcard $(CHK_DIR)/sort_* $(CHK_DIR)/push_swap.c),$(wildcard $(SRC_DIR)/*.c))
OBJ_CHK := $(patsubst $(CHK_DIR)/%.c,$(CHK_OBJ_DIR)/%.o,$(SRC_CHK))
SRC_BONUS := $(wildcard $(BONUS_DIR)/*.c)
OBJ_BONUS := $(patsubst $(BONUS_DIR)/%.c,$(BONUS_OBJ_DIR)/%.o,$(SRC_BONUS))

CC = gcc
FLAGS = -Werror -Wall -Wextra

INCLUDES = includes
HEADER = push_swap.h
HEADER_CHK = checker.h
GNL = get_next_line.h

LIB_DIR = ft_printf/
LIB_OBJS_DIR = ft_printf/objs/
LIB = libftprintf.a

all: $(NAME) $(NAME_CHK)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(CHK_OBJ_DIR)/%.o : $(CHK_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(CHK_OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(BONUS_OBJ_DIR)/%.o : $(BONUS_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES) $(LIB)
	@printf "\n$(YELLOW)Compiling push_swap...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_FILES) $(LIB) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)push_swap compiled!\n$(END)Run program: $(RED)./push_swap <numbers>\n$(END)"

$(NAME_CHK): $(OBJ_CHK) $(LIB)
	@printf "\n$(YELLOW)Compiling checker...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_CHK) $(LIB) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)checker compiled!\n$(END)Run program: $(RED)./checker$(END)"

$(NAME_CHK_BONUS): $(OBJ_BONUS) $(LIB)
	@printf "\n$(YELLOW)Compiling checker_bonus...$(END)\n"
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIB) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)checker_bonus compiled!\n$(END)Run program: $(RED)./checker$(END)"

$(LIB):
	@printf "\n$(YELLOW)Compiling $(LIB)...$(END)\n"
	@make bonus --no-print-directory $(LIB) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

bonus: $(NAME_CHK_BONUS)

clean:
	@printf "\n$(YELLOW)Cleaning objects...$(END)\n"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(CHK_OBJ_DIR)
	@rm -rf $(BONUS_OBJ_DIR)
	@printf "$(GREEN)Done!$(END)\n"

fclean: clean
	@printf "\n$(YELLOW)Cleaning $(NAME), $(NAME_CHK), $(LIB) and libft.a...$(END)\n"
	@rm -f $(LIB)
	@rm -f $(NAME)
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_CHK_BONUS)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@printf "$(GREEN)All clean!$(END)\n"

re: fclean $(NAME)

checker_clean:
	@printf "\n$(YELLOW)Cleaning objects and $(NAME_CHK)...$(END)\n"

checker_fclean: bonus_clean
	@printf "\n$(YELLOW)Cleaning $(LIB) and $(LIB_MLX)...$(END)\n"
	@rm -rf $(LIB)
	@rm -f $(LIB_MLX)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@make --no-print-directory -C $(MLX_DIR) clean
	
bonus_re: bonus_fclean bonus

norm:
	@norminette *.c $(wildcard $(SRC_DIR)/*.c) ft_printf includes checker

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