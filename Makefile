SRCS	?= srcs/mandatory/push_swap.c \
		  srcs/mandatory/parsing/parsing.c \
		  srcs/mandatory/parsing/parsing_create_tab.c \
		  srcs/mandatory/parsing/parsing_utils.c \
		  srcs/mandatory/rules/rules.c \
		  srcs/mandatory/rules/rules_2.c \
		  srcs/mandatory/rules/rules_3.c \
		  srcs/mandatory/rules/call_rules.c \
		  srcs/mandatory/rules/call_rules_2.c \
		  srcs/mandatory/rules/call_rules_3.c \
		  srcs/mandatory/algorithm/utils/rotate_stack.c \
		  srcs/mandatory/algorithm/utils/search_values.c \
		  srcs/mandatory/algorithm/quicksort.c \
		  srcs/mandatory/algorithm/quicksort_utils.c \
		  srcs/mandatory/algorithm/less_than_six.c \
		  srcs/mandatory/algorithm/empty_b.c \
		  includes/libraries/srcs_double_list/ft_double_lstadd_back.c \
		  includes/libraries/srcs_double_list/ft_double_lstadd_front.c \
		  includes/libraries/srcs_double_list/ft_double_lstclear.c \
		  includes/libraries/srcs_double_list/ft_double_lstdelone.c \
		  includes/libraries/srcs_double_list/ft_double_lstlast.c \
		  includes/libraries/srcs_double_list/ft_double_lstnew.c 

BSRCS	?= srcs/bonus/checker.c \
		  srcs/bonus/launch_move.c \
		  srcs/bonus/launch_special_moves.c \
		  srcs/bonus/check_valid_move.c \
		  srcs/bonus/utils.c \
		  srcs/mandatory/parsing/parsing.c \
		  srcs/mandatory/parsing/parsing_create_tab.c \
		  srcs/mandatory/parsing/parsing_utils.c \
		  srcs/mandatory/rules/rules.c \
		  srcs/mandatory/rules/rules_2.c \
		  srcs/mandatory/rules/rules_3.c \
		  srcs/mandatory/rules/call_rules.c \
		  srcs/mandatory/rules/call_rules_2.c \
		  srcs/mandatory/rules/call_rules_3.c \
		  srcs/mandatory/algorithm/utils/rotate_stack.c \
		  includes/libraries/srcs_double_list/ft_double_lstadd_back.c \
		  includes/libraries/srcs_double_list/ft_double_lstadd_front.c \
		  includes/libraries/srcs_double_list/ft_double_lstclear.c \
		  includes/libraries/srcs_double_list/ft_double_lstdelone.c \
		  includes/libraries/srcs_double_list/ft_double_lstlast.c \
		  includes/libraries/srcs_double_list/ft_double_lstnew.c 

OBJS 	?= ${SRCS:.c=.o}

BOBJS 	?= ${BSRCS:.c=.o}

NAME 	?= push_swap

BONUS ?= checker

COMPILER ?= clang

RM		?= rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= includes/libraries/libft/libft.a \
		  includes/libraries/libft/ft_printf/libftprintf.a


.c.o:		${OBJS}
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME}

${NAME}:	${OBJS}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBRARY} 

bonus:	${BOBJS}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${BOBJS} -o ${BONUS} ${LIBRARY} 

clean: 
			${RM} ${OBJS} ${BOBJS} 
			make -C includes/libraries/libft clean

fclean: 	clean
			${RM} ${NAME} ${BONUS}
			make -C includes/libraries/libft fclean

re:
			make fclean
			make

.PHONY: 	all clean fclean re
