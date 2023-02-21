NAME = push_swap

SRC = mandatory/parsing_utils.c  mandatory/ft_split.c mandatory/parsing.c mandatory/main.c \
		mandatory/operations.c mandatory/utils.c \

FT_PRINTF_LIB = libftprintf.a
FT_PRINTF = $(addprefix ft_printf/,$(FT_PRINTF_LIB))

CFLAGS = -Wall -Wextra -Werror
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
