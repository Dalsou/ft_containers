# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 10:24:52 by afoulqui          #+#    #+#              #
#    Updated: 2022/01/25 12:48:31 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

STACK_LST	=	stack_tests.cpp

VECTOR_LST	=	vector_tests.cpp \
				capacity_functions_tests.cpp \
				element_functions_tests.cpp \
				iterator_functions_tests.cpp \
				iterator_test.cpp \
				modifier_functions_tests.cpp \
				non_member_functions_tests.cpp \
				vector_constructor_tests.cpp \
				vector_operator_tests.cpp

MAP_LST		=	map_tests.cpp \
				map_iterator_tests.cpp \
				map_constructor_tests.cpp \
				map_iterator_functions_tests.cpp \
				map_capacity_tests.cpp \
				map_element_tests.cpp \
				map_modifier_tests.cpp \
				map_observer_tests.cpp \
				map_operation_tests.cpp \
				map_non_member_tests.cpp 
				
SRC_DIR		=	$(shell find . -type d)
STACK_SRCS	=	$(foreach dir, $(SRC_DIR), $(STACK_LST))
VECTOR_SRCS	=	$(foreach dir, $(SRC_DIR), $(VECTOR_LST))
MAP_SRCS	=	$(foreach dir, $(SRC_DIR), $(MAP_LST))

OBJ_DIR		=	objs/
STACK_OBJS	=	$(addprefix $(OBJ_DIR), $(STACK_LST:.cpp=.o))
VECTOR_OBJS	=	$(addprefix $(OBJ_DIR), $(VECTOR_LST:.cpp=.o))
MAP_OBJS	=	$(addprefix $(OBJ_DIR), $(MAP_LST:.cpp=.o))

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

stack:		$(STACK_OBJS)
				@$(CC) $(FLAGS) $(STACK_OBJS) -o stack.out
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation Stack    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

vector:		$(VECTOR_OBJS)
				@$(CC) $(FLAGS) $(VECTOR_OBJS) -o vector.out 
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation Vector   *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

map:		$(MAP_OBJS)
				@$(CC) $(FLAGS) $(MAP_OBJS) -o map.out 
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation Map    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

# ----------------- #
#       CLEAN       #
# ----------------- #

RM			=	rm -rf

clean:	
			@$(RM) $(OBJ_DIR)
			@echo "\033[36;1m vector.out map.out stack.out ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) vector.out map.out stack.out
			@echo "\033[36;1m vector.out map.out stack.out ------>>  fclean\033[0m\n"

.PHONY:		all clean fclean re

