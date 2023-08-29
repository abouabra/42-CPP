SRC = main.cpp ScavTrap.cpp ClapTrap.cpp

OSRC=$(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ScavTrap

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): ascci_art $(OSRC) 
	@c++ $(CFLAGS) $(OSRC) -o $@

%.o : %.cpp
	@c++ $(CFLAGS) -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re:fclean all

ascci_art:
	@printf "$(GREEN)                                                                                                        \n\
                                                                                                        \n\
        CCCCCCCCCCCCCPPPPPPPPPPPPPPPPP   PPPPPPPPPPPPPPPPP             000000000      333333333333333     \n\
     CCC::::::::::::CP::::::::::::::::P  P::::::::::::::::P          00:::::::::00   3:::::::::::::::33   \n\
   CC:::::::::::::::CP::::::PPPPPP:::::P P::::::PPPPPP:::::P       00:::::::::::::00 3::::::33333::::::3  \n\
  C:::::CCCCCCCC::::CPP:::::P     P:::::PPP:::::P     P:::::P     0:::::::000:::::::03333333     3:::::3  \n\
 C:::::C       CCCCCC  P::::P     P:::::P  P::::P     P:::::P     0::::::0   0::::::0            3:::::3  \n\
C:::::C                P::::P     P:::::P  P::::P     P:::::P     0:::::0     0:::::0            3:::::3  \n\
C:::::C                P::::PPPPPP:::::P   P::::PPPPPP:::::P      0:::::0     0:::::0    33333333:::::3   \n\
C:::::C                P:::::::::::::PP    P:::::::::::::PP       0:::::0 000 0:::::0    3:::::::::::3    \n\
C:::::C                P::::PPPPPPPPP      P::::PPPPPPPPP         0:::::0 000 0:::::0    33333333:::::3   \n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::0            3:::::3  \n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::0            3:::::3  \n\
 C:::::C       CCCCCC  P::::P              P::::P                 0::::::0   0::::::0            3:::::3  \n\
  C:::::CCCCCCCC::::CPP::::::PP          PP::::::PP               0:::::::000:::::::03333333     3:::::3  \n\
   CC:::::::::::::::CP::::::::P          P::::::::P                00:::::::::::::00 3::::::33333::::::3  \n\
     CCC::::::::::::CP::::::::P          P::::::::P                  00:::::::::00   3:::::::::::::::33   \n\
        CCCCCCCCCCCCCPPPPPPPPPP          PPPPPPPPPP                    000000000      333333333333333     \n\
                                                                                                        \n\
                                                                                                        \n\
                                                                     $(RED) exercise 01    by: abouabra       \n\
                                                                                                        \n$(RESET)"

.PHONY: all clean fclean re
