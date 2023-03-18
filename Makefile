
SRCS = main.c utils/ft_split.c utils/ft_atoi.c  utils/ft_free_mem.c
OBJ = ${SRCS:.c=.o}
NAME = push_swap
LIBRARY := utils/ft_printf/libftprintf.a
FTPRINTF := utils/ft_printf/
FLAG = -Wall -Werror -Wextra
CC = gcc -g3

all : 
	@make -C $(FTPRINTF)
	@$(CC) $(FLAG) $(SRCS) $(LIBRARY) -o $(NAME) 
# -lz -g PER MAC

clean: 
	@make fclean -C $(FTPRINTF)
	@rm -f $(OBJ)
	
fclean:	clean
	@rm -f $(NAME)

re:	fclean all clean