#################################################
### OPTION
##################################################

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
NAME_TEST = testouille
SRC_PATH = srcs

SRC_M_DISPLAY_PATH = ft_display
SRC_M_STRING_PATH = ft_string

OBJ_PATH = srcs
INC_PATH = includes
LIB_PATH = libft
INC=libft/includes

INCLUDES=  ./includes/ft_string.h ./includes/ft_display.h
#################################################
### COLOR
##################################################

COL_BLACK		= \033[1;30m
COL_RED			= \033[1;31m
COL_GREEN		= \033[1;32m
COL_YELLOW		= \033[1;33m
COL_BLUE		= \033[1;34m
COL_PURPLE		= \033[1;35m
COL_WHITE		= \033[1;37m

#################################################
### SOURCES
##################################################

SRC_M_DISPLAY = ft_putchar.c ft_putstr.c ft_putnbr.c

SRC_M_STRING =  ft_strlen.c ft_strcmp.c ft_strcpy.c ft_strcat.c replace.c\
		ft_atoi.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isseparator.c

#################################################
### OBJECT
##################################################

OBJ_M_DISPLAY =     $(patsubst %.c, %.o, $(SRC_M_DISPLAY))
OBJ_M_STRING =      $(patsubst %.c, %.o, $(SRC_M_STRING))

#################################################
### FORMAT PATH
##################################################

SRC_DISPLAY = $(addprefix ./$(SRC_M_DISPLAY_PATH)/, $(SRC_M_DISPLAY))
OBJ_DISPLAY = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_DISPLAY))

SRC_STRING = $(addprefix ./$(SRC_M_STRING_PATH)/, $(SRC_M_STRING))
OBJ_STRING = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_STRING))


OBJS =  $(OBJ_DISPLAY) $(OBJ_STRING)

#################################################
### RULES
##################################################

.PHONY: all libft clean fclean re

all: $(NAME)

$(NAME) : $(OBJ_DISPLAY) $(OBJ_STRING) $(INCLUDES)
	ar rc $(NAME) $(OBJS)

$(OBJ_DISPLAY): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_DISPLAY_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_STRING): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_STRING_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

test_bitch :
	$(CC) $(CFLAGS) main.c -I $(INC_PATH) -L . -lft -o $(NAME_TEST)

test_linkedlist :
	$(CC) $(CFLAGS) test_linked_list.c -I $(INC_PATH) -L . -lft -o SALOPE_DE_LINKED_LIST

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re : fclean all
