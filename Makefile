NAME	=	gnl
BONUS	=	bonus

SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			main.c

OBJS 	=	$(SRCS:.c=.o)

SRCS_BONUS =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				main_bonus.c

OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

CC		= 	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=32

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS):	$(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME) $(BONUS)

re:		fclean all
.PHONY:	all clean fclean re