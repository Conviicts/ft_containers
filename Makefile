NAME			= ft_containers

SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
CXXFLAGS		= -g -Wall -Werror -Wextra -I./ -std=c++98


all:			$(NAME)

.cpp.o:
				$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			test all clean fclean re