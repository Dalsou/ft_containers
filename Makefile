# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME_FT		=	ft_containers
NAME_STD	=	std_containers

SRC			=	main.cpp 

OBJDIR_FT	=	ft_objs
OBJDIR_STD	=	std_objs

OBJ_FT 		=	$(addprefix $(OBJDIR_FT)/, $(SRC:.cpp=.o))
OBJ_STD		=	$(addprefix $(OBJDIR_STD)/, $(SRC:.cpp=.o))

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# ----------------- #
#     FUNCTIONS     #
# ----------------- #



std: 		fclean $(OBJ_STD)
				@$(CC) $(CFLAGS) -D TESTED_NAMESPACE=std $(OBJ_STD) -o $(NAME_STD)
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*       Compilation STD       *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

ft: 		fclean $(OBJ_FT)
				@$(CC) $(CFLAGS) $(OBJ_FT) -o $(NAME_FT) 
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*       Compilation FT        *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

$(OBJDIR_STD)/%.o: %.cpp
					@mkdir -p $(OBJDIR_STD)
					@$(CC) $(CFLAGS) -D TESTED_NAMESPACE=std -c $< -o $@

$(OBJDIR_FT)/%.o: %.cpp
					@mkdir -p $(OBJDIR_FT)
					@$(CC) $(CFLAGS) -c $< -o $@



# ----------------- #
#       CLEAN       #
# ----------------- #

RM			=	rm -rf

clean:
			@$(RM) $(OBJDIR_FT) $(OBJDIR_STD)
			@echo "\033[36;1m $(NAME_FT) $(NAME_STD) ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) $(NAME_FT) $(NAME_STD) $(NAME_FT).txt $(NAME_STD).txt diff.txt
			@echo "\033[36;1m $(NAME_FT) $(NAME_STD) ------>>  fclean\033[0m\n"

re: 		fclean ft std

.PHONY: 	clean fclean all re bonus test ft std
