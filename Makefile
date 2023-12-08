NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rc
CC = cc
SRC = ft_printf.c \
		ft_printf_utils.c \
		ft_itoa.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -c $(SRC)
	$(AR) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
