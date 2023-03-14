NAME = push_swap

SRC = mandatory/ft_atoi.c mandatory/parsing_utils.c  mandatory/ft_split.c mandatory/parsing.c mandatory/operations.c\
		mandatory/operations_b.c mandatory/utils.c  mandatory/list.c mandatory/sort.c \
		mandatory/sort_utils.c   mandatory/positions.c mandatory/main.c mandatory/chunks.c\

FT_PRINTF_LIB = libftprintf.a
FT_PRINTF = $(addprefix ft_printf/,$(FT_PRINTF_LIB))

CFLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

OBJ = $(SRC:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		make -C ft_printf
		$(CC) $(CFLAGS) $^ $(FT_PRINTF) -o $(NAME)

clean:
	make clean -sC ft_printf/
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ft_printf/

re: fclean all

.PHONY: re all clean fclean
