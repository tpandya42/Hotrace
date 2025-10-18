MAKEFLAGS += --no-print-directory -s
NAME = hotrace
CC = cc
CLAGS = -Wall -Werror -Wextra -Iinclude

SRC_DIR = src 
SRC = \
      $(SRC_DIR)/hashing.c \
      $(SRC_DIR)/main.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/reading.c

OBJ_DIR = obj 
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "---***BUILD COMPLETE***---"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	@echo "---***COMPILING***---"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)
	@echo "---***Cleaned Object File***---"

fclean: clean
	@rm -f $(NAME)
	@echo "---***Cleaned Everything***---"

re: fclean all

.PHONY: all clean fclean re 

