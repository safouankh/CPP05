NAME		=	Form
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp

OBJS		=	$(SRCS:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o			:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	del /Q $(OBJS) 2>nul || echo.

fclean		:	clean
	del /Q $(NAME).exe $(NAME) 2>nul || echo.

re			:	fclean all

.PHONY		:	all clean fclean re