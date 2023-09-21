##
## EPITECH PROJECT, 2023
## Sans titre(Espace de travail)
## File description:
## Makefile
##

NAME_GUI			=	zappy_gui

NAME_SERVER			=	zappy_server

NAME_AI				=	zappy_ai

SRCS_GUI			=	 $(wildcard GUI/src/*.cpp)

SRCS_SERVER			= 	$(wildcard SERVER/src/*.c) \
						$(wildcard SERVER/src/commandsGUI/*.c) \
						$(wildcard SERVER/src/commandsAI/*.c)

SRCS_AI				=	 $(wildcard AI/src/*.py)

CXXFLAGS				= -W -Wall -Wextra -Werror -g -D _GNU_SOURCE

# LDFLAGS	= `pkg-config --libs --cflags raylib` -lsfml-network -lsfml-system
LDFLAGS	= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lsfml-network -lsfml-system

# This is a minimal set of ANSI/VT100 color codes
_END		=	\033[0m
_BOLD		=	\033[1m
_UNDER		=	\033[4m
_REV		=	\033[7m

# Colors
_GREY		=	\033[30m
_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_BLUE		=	\033[34m
_PURPLE		=	\033[35m
_CYAN		=	\033[36m
_WHITE		=	\033[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\033[40m
_IRED		=	\033[41m
_IGREEN		=	\033[42m
_IYELLOW	=	\033[43m
_IBLUE		=	\033[44m
_IPURPLE	=	\033[45m
_ICYAN		=	\033[46m
_IWHITE		=	\033[47m

all:	gui serv ai

gui:
	@echo "${_BOLD}$(_PURPLE)* * * * * START COMPILATION OF SERVER * * * * *$(_END)"
	g++ $(SRCS_GUI) -o $(NAME_GUI) -std=c++17 $(LDFLAGS)
	@echo "${_BOLD}$(_GREEN)* * * * * COMPILATION OF GUI COMPLETED * * * * *$(_END)"

serv:
	@echo "${_BOLD}$(_PURPLE)* * * * * START COMPILATION OF SERVER * * * * *$(_END)"
	gcc $(SRCS_SERVER) -o $(NAME_SERVER) -g -lm
	@echo "${_BOLD}$(_GREEN)* * * * * COMPILATION OF SERVER COMPLETED * * * * *$(_END)"

ai:
	@echo "${_BOLD}$(_PURPLE)* * * * * START COMPILATION OF AI * * * * *$(_END)"
	@touch $(NAME_AI)
	@chmod +x $(NAME_AI)
	@echo "#!/usr/bin/env python3" >> $(NAME_AI)
	@echo "from AI.src.main import main" >> $(NAME_AI)
	@echo "if __name__ == '__main__':" >> $(NAME_AI)
	@echo "	exit(main())" >> $(NAME_AI)
	@echo "${_BOLD}$(_GREEN)* * * * * COMPILATION OF AI COMPLETED * * * * *$(_END)"

clean:
		rm -f $(OBJS_GUI)
		rm -f $(OBJS_SERVER)
		rm -f $(OBJS_AI)
		@echo "${_BOLD}$(_BLUE)* * * * *  CLEANED  * * * * *$(_END)"

fclean:		clean
		rm -f $(NAME_GUI)
		rm -f $(NAME_SERVER)
		rm -f $(NAME_AI)
		rm -rf AI/src/__pycache__
		@echo "${_BOLD}$(_BLUE)* * * * *  FCLEANED  * * * * *$(_END)"

re:		fclean all

.PHONY:		all clean fclean re ai serv gui