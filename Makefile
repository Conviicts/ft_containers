NAME			= ft_containers

SRCS			= 	vector.cpp	\
					stack.cpp	\
					map.cpp		\
					main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
CXXFLAGS		= -g -Wall -Werror -Wextra -I./includes -std=c++98


all:			$(NAME)

.cpp.o:
				$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

stl:			
				@$(MAKE) all CXXFLAGS:="-DSTL -I./includes -std=c++98 -g -Wall -Werror -Wextra"

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			test all clean fclean re