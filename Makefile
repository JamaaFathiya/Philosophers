CC= gcc -pthread
FLAGS= -Wall -Wextra -Werror
RM= rm -rf

HEADER= philo.h
FILES= main core init  utils philo
OBJ=$(FILES:=.o)
SRC=$(FILES:=.c)
NAME=philo

ifeq ($(DEBUG), 1)
OPT = -g
endif

#BACKGROUND COLORS
BRED = \x1b[41m
BGREEN = \x1b[42m
BYELLOW = \x1b[43m

#COLORS
White = \033[0;37m
YELLOW = \x1b[33m
GREEN = \e[92;5;118m
RED = \033[0;31m
END = \033[0m

BOLD = \x1b[1m
UNDER = \x1b[4m


.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) $(opt) -I ./ -o $(NAME)
	@printf " [$(BOLD)$(GREEN):)$(END)] [$(BOLD)$(GREEN)SUCCESS$(END)]\n"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) $(OPT) -I ./ -c $< -o $@

bonus: 
	@make -C bonus

clean: 
	@$(RM) $(OBJ)
#	@make clean -C bonus
	@printf " [$(BOLD)$(YELLOW):)$(END)] [$(BOLD)$(YELLOW)CLEAN$(END)]\n"

fclean: clean
	@$(RM) $(NAME)
#	@make fclean -C bonus
	@printf " [$(BOLD)$(YELLOW):)$(END)] [$(BOLD)$(YELLOW)FCLEAN$(END)]\n"

re: fclean all
