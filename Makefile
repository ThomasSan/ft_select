# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 11:57:14 by tsanzey           #+#    #+#              #
#    Updated: 2016/02/03 16:41:23 by tsanzey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
SRC = main.c get_next_line.c get_input.c set_terminal.c lst_manip.c misc.c \
		display.c basic_keys.c extra_keys.c signal.c colored_print.c \
		ft_special_prints.c ft_lst_print.c

OBJ = $(SRC:%.c=obj/%.o)

CXX = clang
CXXFLAGS = -Wall -Werror -Wextra

INC = -I includes
LIB = libft/

all: $(NAME)

$(NAME): obj $(OBJ)
	@make -s -C $(LIB)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(INC) -L$(LIB) -lft -ltermcap
	@echo "\033[0;32m ______________________   ____________________.____     _______________________________"
	@echo "\033[0;32m \_   _____/\__    ___/  /   _____/\_   _____/|    |    \_   _____/\_   ___ \__    ___/"
	@echo "\033[0;32m  |    __)    |    |     \_____  \  |    __)_ |    |     |    __)_ /    \  \/ |    |   "
	@echo "\033[0;32m  |     \     |    |     /        \ |        \|    |___  |        \\     \____|    |   "
	@echo "\033[0;32m  \___  /     |____|____/_______  //_______  /|_______ \/_______  / \______  /|____|   "
	@echo "\033[0;32m      \/          /_____/       \/         \/         \/        \/         \/          "

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< -I$(LIB)

obj:
	mkdir -p obj/

clean:
	@rm -rf obj

fclean: clean
	@echo "\033[0;31m  (         (                 (     "
	@echo "\033[0;31m  )\ )      )\ )      *   )   )\ )  "
	@echo "\033[0;31m (()/(  (  (()/( (    )  /(( (()/(  "
	@echo "\033[0;31m  /(_)) )\  /(_)))\  ( )(_))\ /(_)) "
	@echo "\033[0;31m (_))_ ((_)(_)) ((_)(_(_()|(_|_))_  "
	@echo "\033[0;31m  |   \| __| |  | __|_   _| __|   \ "
	@echo "\033[0;31m  | |) | _|| |__| _|  | | | _|| |) |"
	@echo "\033[0;31m  |___/|___|____|___| |_| |___|___/ "
	@echo "\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re
