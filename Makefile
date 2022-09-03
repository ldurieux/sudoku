SRCS	= \
			main.c \
			srcs/sudoku_print_grid.c \
			srcs/sudoku_print_cells.c \
			srcs/sudoku_make.c \
			srcs/sudoku_solve.c \
			srcs/sudoku_cleanup.c \
			srcs/sudoku_solve_simple.c \
			srcs/sudoku_solve_backtrack.c \
			srcs/sudoku_collapse.c \
			srcs/sudoku_is_solved.c \
			srcs/sudoku_is_impossible.c \
			srcs/cell_count.c \
			srcs/cell_remove.c \
			srcs/cell_value.c \
			srcs/cell_contains.c \
			srcs/cell_set.c \

LIBS	=	-lft \

HEADERS	=	includes/

LIB_NAMES	= $(subst -l,lib,$(LIBS))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(lib).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

OBJS		= ${SRCS:.c=.o}
DEPS		= ${SRCS:.c=.d}
CC			= gcc
CCFLAGS		= -Wall -Wextra -g
DEPSFLAGS	= -MMD -MP
NAME		= sudoku
RM			= rm -f
MAKE		= make -C
WRAP		= 

.PHONY: all clean fclean re

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CC) $(WRAP) $(CCFLAGS) -I$(HEADERS) $(LIB_HEADERS) -o $@ $(OBJS) $(LIB_LD) $(LIBS)

$(LIB_PATHS) :
		$(MAKE) $(notdir $(basename $@))

all : $(NAME)

clean :
		-$(RM) $(OBJS) $(DEPS)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			make -C $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCFLAGS) $(DEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@ $(LIB_LD) $(LIBS)
