# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 10:24:52 by afoulqui          #+#    #+#              #
#    Updated: 2022/01/21 14:56:50 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME		=	vector.out

SRC_LST		=	stack.cpp
				# vector.cpp \
				# capacity_functions_tests.cpp \
				# element_functions_tests.cpp \
				# iterator_functions_tests.cpp \
				# iterator_test.cpp \
				# modifier_functions_tests.cpp \
				# non_member_functions_tests.cpp \
				# vector_constructor_tests.cpp \
				# vector_operator_tests.cpp
				
SRC_DIR		=	$(shell find tests -type d)
SRCS		=	$(foreach dir, $(SRC_DIR), $(SRC_LST))

OBJ_DIR		=	objs/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_LST:.cpp=.o))

vpath %.cpp $(foreach dir, $(SRC_DIR)/, $(dir):)

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC			=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

$(OBJ_DIR)%.o: %.cpp 
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(FLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
				@$(CC) $(FLAGS) $(OBJS) -o $(NAME)		
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation $(NAME)    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

all:		$(NAME)

# ----------------- #
#       CLEAN       #
# ----------------- #

RM			=	rm -rf

clean:	
			@$(RM) $(OBJ_DIR)
			@echo "\033[36;1m $(NAME) ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[36;1m $(NAME) ------>>  fclean\033[0m\n"

re:			fclean all

.PHONY:		all clean fclean re