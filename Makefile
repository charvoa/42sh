##
## Makefile for  in /home/charvo_a/42/lexer
##
## Made by Nicolas Charvoz
## Login   <charvo_a@epitech.net>
##
## Started on  Mon Apr 21 15:01:55 2014 Nicolas Charvoz
## Last update Sun May 18 15:34:49 2014 Nicolas Charvoz
## Last update Mon May  5 16:59:08 2014 garcia antoine
##

CC	= 	gcc

RM	= 	rm -f

TERM	=	./termcaps

LEXER	=	./lexer/src

USELESS	=	-g3

PARSER	=	./parser

PIPE	=	./pipe

EXEC	=	./execution

ENV	=	./env

PIPE	=	./pipe

CFLAGS  += 	-Wextra -Wall -W -g3
CFLAGS	+=	-Wbad-function-cast -Wcast-align

LMY	=	-L $(ENV)/libsources/ -lmy

LIBTERM	=	-lncurses

NAME	=	42sh

SRCS	=	$(TERM)/termcaps.c		\
		$(LEXER)/lexer.c		\
		$(LEXER)/check1.c		\
		$(LEXER)/check2.c		\
		$(LEXER)/epur_str.c		\
		$(LEXER)/useless.c		\
		$(ENV)/dlist.c			\
		$(ENV)/init.c			\
		$(ENV)/list.c			\
		$(ENV)/main.c			\
		$(ENV)/prompt.c			\
		$(ENV)/start_shell.c		\
		$(ENV)/util_env.c		\
		$(ENV)/strtotab.c		\
		$(PARSER)/parser.c		\
		$(PARSER)/struct_fill.c		\
		$(PARSER)/pars.c		\
		$(EXEC)/global_exec.c		\
		$(EXEC)/exec_simple_cmd.c	\
		$(EXEC)/redirections.c		\
		$(PIPE)/pipes.c			\


OBJS	= 	$(SRCS:.c=.o)

CLEAR	=	$(shell clear)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LMY) $(LIBTERM) $(LDFLAGS)
		echo $(CLEAR)
		@(cat .txt/42sh.txt)

clean:
		$(RM) $(OBJS)


fclean:		clean
		$(RM) $(NAME)

re:		fclean all

charvo_a:
		@(cat .txt/charvo_a.txt)

heitzl_s:
		@(cat .txt/heitzl_s.txt)

girard_s:
		@(cat .txt/girard_s.txt)

audibe_l:
		@(cat .txt/audibe_l.txt)

garcia_t:
		@(cat .txt/garcia_t.txt)

group:		charvo_a heitzl_s girard_s audibe_l garcia_t

.PHONY:		all clean fclean re charvo_a heitzl_s girard_s audibe_l garcia_t group
