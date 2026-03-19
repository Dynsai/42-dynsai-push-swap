# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 16:31:18 by parenas-          #+#    #+#              #
#    Updated: 2026/03/19 14:45:28 by parenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I include/

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRCS		=	$(SRC_DIR)push_swap_main.c \
				$(SRC_DIR)push_swap_utils1.c \
				$(SRC_DIR)push_swap_list_utils1.c \
				$(SRC_DIR)push_swap_list_utils2.c \
				$(SRC_DIR)parse_input.c \
				$(SRC_DIR)ft_split.c

OBJS		=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test3: $(NAME)
	./$(NAME) $(shell bash -c "for i in 1 2 3; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

test5: $(NAME)
	./$(NAME) $(shell bash -c "for i in 1 2 3 4 5; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

test100: $(NAME)
	./$(NAME) $(shell bash -c "for i in {1..100}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

test500: $(NAME)
	./$(NAME) $(shell bash -c "for i in {1..500}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

v10: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..10}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

vletters: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 42 abc 7 hello 3

vspaces: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) "   "

vnmixed: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 1 22 3 "4 551 6 51 81996 26587 173" 67

vtotal: $(NAME)
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..10}; ...")
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 42 abc 7 hello 3
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) "   "
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 1 22 3 "4 551 6 51 81996 26587 173" 67

.PHONY: all clean fclean re test3 test5 test100 test500 v10 vletters vspaces vnmixed vtotal