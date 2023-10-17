SRC = main.cpp ScalarConverter.cpp

OSRC=$(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)
	@clear

# $(NAME): ascci_art $(OSRC)
$(NAME): $(OSRC)
	@c++ $(CFLAGS) $(OSRC) -o $@

%.o : %.cpp
	@c++ $(CFLAGS) -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re:fclean all

ascci_art:
	@clear
	@printf "$(GREEN)                                                                                                        \n\
                                                                                                        \n\
                                                                                                        \n\
        CCCCCCCCCCCCCPPPPPPPPPPPPPPPPP   PPPPPPPPPPPPPPPPP             000000000             66666666   \n\
     CCC::::::::::::CP::::::::::::::::P  P::::::::::::::::P          00:::::::::00          6::::::6    \n\
   CC:::::::::::::::CP::::::PPPPPP:::::P P::::::PPPPPP:::::P       00:::::::::::::00       6::::::6     \n\
  C:::::CCCCCCCC::::CPP:::::P     P:::::PPP:::::P     P:::::P     0:::::::000:::::::0     6::::::6      \n\
 C:::::C       CCCCCC  P::::P     P:::::P  P::::P     P:::::P     0::::::0   0::::::0    6::::::6       \n\
C:::::C                P::::P     P:::::P  P::::P     P:::::P     0:::::0     0:::::0   6::::::6        \n\
C:::::C                P::::PPPPPP:::::P   P::::PPPPPP:::::P      0:::::0     0:::::0  6::::::6         \n\
C:::::C                P:::::::::::::PP    P:::::::::::::PP       0:::::0 000 0:::::0 6::::::::66666    \n\
C:::::C                P::::PPPPPPPPP      P::::PPPPPPPPP         0:::::0 000 0:::::06::::::::::::::66  \n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::06::::::66666:::::6 \n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::06:::::6     6:::::6\n\
 C:::::C       CCCCCC  P::::P              P::::P                 0::::::0   0::::::06:::::6     6:::::6\n\
  C:::::CCCCCCCC::::CPP::::::PP          PP::::::PP               0:::::::000:::::::06::::::66666::::::6\n\
   CC:::::::::::::::CP::::::::P          P::::::::P                00:::::::::::::00  66:::::::::::::66 \n\
     CCC::::::::::::CP::::::::P          P::::::::P                  00:::::::::00      66:::::::::66   \n\
        CCCCCCCCCCCCCPPPPPPPPPP          PPPPPPPPPP                    000000000          666666666     \n\
                                                                                                        \n\
                                                                      $(RED) exercise 00    by: abouabra\n\
                                                                                                        \n$(RESET)"
                                                                                                  
.PHONY: all clean fclean re
