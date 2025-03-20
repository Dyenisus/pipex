# Executable name
NAME := pipex

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# Directories
IN_DIR := .
SRC_DIR := src
OBJ_DIR := obj

# Libft
LIBFT := libft/libft.a

# Header files
INCLUDES := -I $(IN_DIR)

# Source files
SRCS := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Color for output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Linking so_long with libft
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Compiling .c files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory if not exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile libft (which includes get_next_line + ft_printf)
$(LIBFT): 
	@$(MAKE) -C libft --no-print-directory

# Clean object files
clean:
	@rm -f $(OBJS)
	@make -C libft clean

# Full clean (removes everything)
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

# Recompile everything
re: fclean all