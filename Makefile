SRCS	?= push_swap.c \
		  parsing/parsing.c \
		  parsing/parsing_create_tab.c \
		  parsing/parsing_utils.c \
		  rules/rules.c \
		  rules/rules_2.c \
		  rules/rules_3.c \
		  rules/call_rules.c \
		  rules/call_rules_2.c \
		  rules/call_rules_3.c \
		  algorithm/utils/rotate_stack.c \
		  algorithm/utils/search_values.c \
		  algorithm/quicksort.c \
		  algorithm/quicksort_utils.c \
		  algorithm/less_than_six.c \
		  algorithm/empty_b.c \
		  sources/srcs_double_list/ft_double_lstadd_back.c \
		  sources/srcs_double_list/ft_double_lstadd_front.c \
		  sources/srcs_double_list/ft_double_lstclear.c \
		  sources/srcs_double_list/ft_double_lstdelone.c \
		  sources/srcs_double_list/ft_double_lstlast.c \
		  sources/srcs_double_list/ft_double_lstnew.c 

BSRCS	?= checker_bonus/checker.c \
		  checker_bonus/launch_move.c \
		  checker_bonus/launch_special_moves.c \
		  checker_bonus/check_valid_move.c \
		  checker_bonus/utils.c \
		  parsing/parsing.c \
		  parsing/parsing_create_tab.c \
		  parsing/parsing_utils.c \
		  rules/rules.c \
		  rules/rules_2.c \
		  rules/rules_3.c \
		  rules/call_rules.c \
		  rules/call_rules_2.c \
		  rules/call_rules_3.c \
		  algorithm/utils/rotate_stack.c \
		  sources/srcs_double_list/ft_double_lstadd_back.c \
		  sources/srcs_double_list/ft_double_lstadd_front.c \
		  sources/srcs_double_list/ft_double_lstclear.c \
		  sources/srcs_double_list/ft_double_lstdelone.c \
		  sources/srcs_double_list/ft_double_lstlast.c \
		  sources/srcs_double_list/ft_double_lstnew.c 

OBJS 	?= ${SRCS:.c=.o}

BOBJS 	?= ${BSRCS:.c=.o}

NAME 	?= push_swap

BONUS ?= checker

COMPILER ?= clang

RM		?= rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= sources/libft/libft.a \
		  sources/libft/ft_printf/libftprintf.a


.c.o:		${OBJS}
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME}

${NAME}:	${OBJS}
			make -C sources/libft
			${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBRARY} 

bonus:	${BOBJS}
			make -C sources/libft
			${COMPILER} ${CFLAGS} ${BOBJS} -o ${BONUS} ${LIBRARY} 

clean: 
			${RM} ${OBJS} ${BOBJS} 
			make -C sources/libft clean

fclean: 	clean
			${RM} ${NAME} ${BONUS}
			make -C sources/libft fclean

re:
			make fclean
			make

.PHONY: 	all clean fclean re
