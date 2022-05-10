NAME			= philo

SRCS_DIR      	= ./srcs/
HEAD_DIR		= ./includes/
HEAD_LIST		= philo.h

HEAD         	= $(addprefix $(HEAD_DIR), $(HEAD_LIST))

SRCS_FILES    	= main.c validation.c init.c time.c philo.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		  	= $(SRCS:%.c=%.o)

CC		      = cc
CFLAGS		  = -Wall -Wextra -Werror #-fsanitize=thread -g
RM			  =	rm -rf

.PHONY: all clean fclean re 

all: $(NAME)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean $(OBJS_DIR) fclean all 