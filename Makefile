MAKEFLAGS += --no-print-directory -s
NAME = hotrace
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude

SRC_DIR = src
SRC = \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/hashing.c \
	   $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/reading.c

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:$(SRC_DIR)/%.c=%.o))

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "---***BUILD COMPLETE***---"

$(OBJDIR)/%.o: $(SRC_DIR)/%.c | $(OBJDIR)
	@echo "---***COMPILING***---"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo "---***Cleaned Object Files***---"

fclean: clean
	@rm -f $(NAME)
	@echo "---***Cleaned Everything***---"

re: fclean all

.PHONY: all clean fclean re

