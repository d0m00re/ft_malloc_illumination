CC=gcc
CFLAGS= -Wall -Wextra -Werror
LIB_PATH=libft
INC=includes
INC_PATH= ./$(LIB_PATH)/$(INC)
NAME= libft_malloc.so
LIB_PATH= libft
BIN_PATH= bin

INCLUDES = ./includes/linked_list_itf.h ./includes/memory_manage.h   ./includes/setting.h         ./includes/utilities.h

SRC_PATH=srcs
OBJ_PATH=srcs

SRC_M_LST_ITF_PATH = linked_list_itf
SRC_M_UTILITIES_PATH = utilities

ifeq ($(HOSTTYPE),)
        HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIB = ./libft_malloc_$(HOSTTYPE).so

################################################
### SOURCES
###############################################

SRC_M_LST_ITF = lstcreate_elem.c lstcreate_push_ll_end.c
SRC_M_ITF	= $(addprefix ./$(SRC_M_LST_ITF_PATH)/, $(SRC_M_LST_ITF))

SRC_M_UTILITIES = add_main_chunk_data.c find_next_size_page.c init_main_control.c   reallocator.c\
allocator.c           freecator.c           pre_allocation.c      search_in_allocator.c\
f_malloc.c f_free.c f_realloc.c show_alloc_mem.c alloc_desalloc.c desalocator_useless_mem.c\
view_area.c ll_del_last.c

SRC_M_UTILI = $(addprefix ./$(SRC_M_UTILITIES_PATH)/, $(SRC_M_UTILITIES))

###############################################
### OBJECT
##############################################
OBJ_M_LST_ITF= $(patsubst %.c, %.o, $(SRC_M_LST_ITF))
OBJ_M_ITF= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_LST_ITF))

OBJ_M_UTILITIES= $(patsubst %.c, %.o, $(SRC_M_UTILITIES))
OBJ_M_UTILI= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_UTILITIES))

OBJ_ALL= $(OBJ_M_ITF) $(OBJ_M_UTILI)


####################################################
#################### RULES ########################

.PHONY: all libft clean fclean re

all: $(NAME)
	@ln -fs $(LIB) $(NAME)

$(NAME): lib $(OBJ_M_ITF) $(OBJ_M_UTILI) $(INCLUDES)
	@$(CC) $(CFLAGS) -shared $(OBJ_M_ITF) $(OBJ_M_UTILI) -I $(INC) -I $(INC_PATH) $(LIB_PATH)/libft.a -o $(LIB)

$(OBJ_M_ITF): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_LST_ITF_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_M_UTILI): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_UTILITIES_PATH)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC_PATH) -I $(INC) -c $< -o $@

lib:
	@cd $(LIB_PATH) && make

clean: cleanlib
	@rm -rf $(OBJ_ALL) main.o

cleanlib:
	@cd $(LIB_PATH) && make clean
	@echo "$(COL_WHITE)[ CLEAN LIBFT ]\n"

fclean: fcleanlib clean
	@rm -rf $(NAME) $(LIB)

fcleanlib: cleanlib
	@cd $(LIB_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

re: fclean all
