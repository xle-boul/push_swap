# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:16:31 by xle-boul          #+#    #+#              #
#    Updated: 2022/05/31 11:18:55 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
UNDERLINE = \e[4m
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

LIB_DIR = libft/
LIB_OBJS_DIR = libft/objs/
LIB = libft.a

LIB_PRINTF_DIR = ft_printf/
LIB_PRINTF_OBJS_DIR = ft_printf/objs/
LIB_PRINTF = libftprintf.a

all: $(NAME) $(NAME_CHK)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(CHK_OBJ_DIR)/%.o : $(CHK_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(CHK_OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(BONUS_OBJ_DIR)/%.o : $(BONUS_DIR)/%.c $(INCLUDES)/
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES) $(LIB) $(LIB_PRINTF)
	@printf "\n$(YELLOW)Compiling push_swap...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_FILES) $(LIB) $(LIB_PRINTF) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)push_swap compiled!\n$(END)Run program: $(RED)./push_swap <numbers>\n$(END)"

$(NAME_CHK): $(OBJ_CHK) $(LIB) $(LIB_PRINTF)
	@printf "\n$(YELLOW)Compiling checker...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_CHK) $(LIB) $(LIB_PRINTF) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)checker compiled!\n$(END)Run program: $(RED)./checker $(BLUE)<numbers>$(RED) then insert operations.\n$(END)To finish inserting operations, press $(RED)ENTER $(END)or $(RED)CTRL-D$(END).\n"

$(NAME_CHK_BONUS): $(OBJ_BONUS) $(LIB) $(LIB_PRINTF)
	@printf "\n$(YELLOW)Compiling checker_bonus...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_BONUS) $(LIB) $(LIB_PRINTF) -I $(INCLUDES)/ -o $@
	@printf "\n$(GREEN)checker_bonus compiled!\n$(END)Run program: $(RED)./checker_bonus $(BLUE)<numbers>$(RED) then insert operations.$(END)\nTo finish inserting operations, press $(RED)ENTER $(END)or $(RED)CTRL-D$(END).\nAvailable flags:$(GREEN)\n\t-c: adds colors to the output$(END)$(WHITE)\n\t-d: displays the optimization details and the amount of elements transferred in stack B$(END)$(CYAN)\n\t-i: displays the sorted stack A with indexes rather than numbers given$(END)\n\t$(YELLOW)-n: displays the amount of operations done\n\t$(END)$(MAGENTA)-p: displays the stacks in between each operation call\n$(END)"

$(LIB):
	@printf "\n$(YELLOW)Compiling $(LIB)...$(END)\n"
	@make --no-print-directory $(LIB) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

$(LIB_PRINTF):
	@printf "\n$(YELLOW)Compiling $(LIB_PRINTF)...$(END)\n"
	@make --no-print-directory $(LIB_PRINTF) -C $(LIB_PRINTF_DIR)
	@mv $(LIB_PRINTF_DIR)$(LIB_PRINTF) .

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
	@rm -f $(LIB_PRINTF)
	@rm -f $(NAME)
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_CHK_BONUS)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@printf "$(GREEN)All clean!$(END)\n"

re: fclean all

norm:
	@norminette

help:
	@printf "$(RED)\t\t\t$(UNDERLINE)Makefile rules:$(END)\n\n"
	@printf "$(CYAN)'make'$(END): \t\tCompile mandatory part\n"
	@printf "$(CYAN)'make push_swap'$(END): \tCompile mandatory part but only push_swap\n"
	@printf "$(CYAN)'make checker'$(END): \tCompile mandatory part but only checker\n"
	@printf "$(CYAN)'make clean'$(END): \t\tGet rid of objects\n"
	@printf "$(CYAN)'make fclean'$(END): \t\tGet rid of objects, programs and libraries\n"
	@printf "$(CYAN)'make re'$(END): \t\tGet rid of everything and recompile mandatory part\n\n"
	@printf "$(MAGENTA)'make bonus'$(END): \t\tCompile bonus part\n\n"
	@printf "$(YELLOW)'make norm'$(END): \t\tCheck norminette\n"
	@printf "\n\t\t\t$(RED)$(UNDERLINE)Checker Bonus Flags:$(END)\n$(GREEN)-c: adds colors to the output$(END)$(WHITE)\n-d: displays the optimization details and the amount of elements transferred in stack B$(END)$(CYAN)\n-i: displays the sorted stack A with indexes rather than numbers given$(END)\n$(YELLOW)-n: displays the amount of operations done\n$(END)$(MAGENTA)-p: displays the stacks in between each operation call\n$(END)\n\n"


.PHONY: all bonus clean fclean re norm help