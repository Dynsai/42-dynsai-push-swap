# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 16:31:18 by parenas-          #+#    #+#              #
#    Updated: 2026/03/20 15:28:12 by parenas-         ###   ########.fr        #
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
				$(SRC_DIR)push_swap_parse_utils.c \
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

t3: $(NAME)
	./$(NAME) $(shell bash -c "for i in 1 2 3; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

t5: $(NAME)
	./$(NAME) $(shell bash -c "for i in 1 2 3 4 5; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

t100: $(NAME)
	./$(NAME) $(shell bash -c "for i in {1..100}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

t500: $(NAME)
	./$(NAME) $(shell bash -c "for i in {1..500}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

v10: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..10}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

v100: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..100}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '")

vletters: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 42 abc 7 hello 3

vspaces: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) "   "

vdup: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 2 1 3 "5 1 7 4" 5

vnmixed: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 1 22 3 "4 551 6 51 81996 26587 173" 67

vtotal: $(NAME)
	@echo "####################### Test 1 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..10}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '") \
	> /dev/null | grep -A12 "HEAP SUMMARY"

	@echo "####################### Test 2 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) $(shell bash -c "for i in {1..100}; do od -An -N4 -tu4 /dev/urandom | tr -d ' ' | awk '{print \$$1 % 4294967296 - 2147483648}'; done | tr '\n' ' '") \
	> /dev/null | grep -A12 "HEAP SUMMARY"

	@echo "####################### Test 3 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 42 abc 7 hello 3 \
	> /dev/null | grep -A12 "HEAP SUMMARY"

	@echo "####################### Test 4 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) "   " \
	> /dev/null | grep -A12 "HEAP SUMMARY"

	@echo "####################### Test 5 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 2 1 3 "5 1 7 4" 5 \
	> /dev/null | grep -A12 "HEAP SUMMARY"

	@echo "####################### Test 6 #######################"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) 1 22 3 "4 551 6 51 81996 26587 173" 67 \
	> /dev/null | grep -A12 "HEAP SUMMARY"

.PHONY: all clean fclean re t3 t5 t100 t500 v10 v100 vletters vspaces vdup vnmixed vtotal