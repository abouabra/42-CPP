SRC = AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp Intern.cpp

OSRC=$(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Intern

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
	@clear
	@printf "$(GREEN)                                                                                                        \n\
                                                                                                        \n\
                                                                                                        \n\
        CCCCCCCCCCCCCPPPPPPPPPPPPPPPPP   PPPPPPPPPPPPPPPPP             000000000     555555555555555555 \n\
     CCC::::::::::::CP::::::::::::::::P  P::::::::::::::::P          00:::::::::00   5::::::::::::::::5 \n\
   CC:::::::::::::::CP::::::PPPPPP:::::P P::::::PPPPPP:::::P       00:::::::::::::00 5::::::::::::::::5 \n\
  C:::::CCCCCCCC::::CPP:::::P     P:::::PPP:::::P     P:::::P     0:::::::000:::::::05:::::555555555555 \n\
 C:::::C       CCCCCC  P::::P     P:::::P  P::::P     P:::::P     0::::::0   0::::::05:::::5            \n\
C:::::C                P::::P     P:::::P  P::::P     P:::::P     0:::::0     0:::::05:::::5            \n\
C:::::C                P::::PPPPPP:::::P   P::::PPPPPP:::::P      0:::::0     0:::::05:::::5555555555   \n\
C:::::C                P:::::::::::::PP    P:::::::::::::PP       0:::::0 000 0:::::05:::::::::::::::5  \n\
C:::::C                P::::PPPPPPPPP      P::::PPPPPPPPP         0:::::0 000 0:::::0555555555555:::::5 \n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::0            5:::::5\n\
C:::::C                P::::P              P::::P                 0:::::0     0:::::0            5:::::5\n\
 C:::::C       CCCCCC  P::::P              P::::P                 0::::::0   0::::::05555555     5:::::5\n\
  C:::::CCCCCCCC::::CPP::::::PP          PP::::::PP               0:::::::000:::::::05::::::55555::::::5\n\
   CC:::::::::::::::CP::::::::P          P::::::::P                00:::::::::::::00  55:::::::::::::55 \n\
     CCC::::::::::::CP::::::::P          P::::::::P                  00:::::::::00      55:::::::::55   \n\
        CCCCCCCCCCCCCPPPPPPPPPP          PPPPPPPPPP                    000000000          555555555     \n\
                                                                                                        \n\
                                                                      $(RED) exercise 03    by: abouabra\n\
                                                                                                        \n$(RESET)"
                                                                                                  
.PHONY: all clean fclean re
