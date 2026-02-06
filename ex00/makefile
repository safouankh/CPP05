NAME		=	bureaucrat
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp \
				Bureaucrat.cpp

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o			:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	rm -fr $(OBJS)

fclean		:	clean
	rm -fr $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re