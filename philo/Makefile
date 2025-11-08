NAME := philo
# Directories
INCDIR := includes
SRCDIR := src
OBJDIR := obj

# Source files and Objects
SRC := main.c init_table.c utils_philo.c validate_input.c start_routines.c\
	   	philo_routine.c waiter_routine.c\

SRC := $(SRC:%=$(SRCDIR)/%)
OBJS := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Flags
CC := clang
# Add gdwarf-4 due to compatibility problems in my personal pc
CFLAGS := -Wall -Wextra -Werror -g2 -gdwarf-4
CPPFLAGS := $(addprefix -I, $(INCDIR))

# Useful variables
RM := rm -f
RMDIR := rm -fr
DUP_DIR = mkdir -p $(@D)
MANDATORY_MARK = .mandatory

all: $(NAME) 

# Mandatory
$(NAME): $(MANDATORY_MARK)

$(MANDATORY_MARK): $(OBJS)
	@$(RM) $(BONUS_MARK)
	$(CC) $(OBJS) -pthreads -o $(NAME)
	@touch $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(DUP_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RMDIR) $(OBJDIR)
	@$(RM) $(MANDATORY_MARK)

fclean: clean
	$(RM) $(NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
