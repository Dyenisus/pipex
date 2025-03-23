# **************************************************************************** #
#                                  PIPEX MAKEFILE                              #
# **************************************************************************** #

# Executable
NAME		:= pipex

# Compiler and Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

# Paths
SRC_DIR		:= src
OBJ_DIR		:= obj
INCL_DIR	:= .
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

# Headers
INCLUDES	:= -I$(INCL_DIR) -I$(LIBFT_DIR)

# Source and Object Files
SRCS := $(addprefix $(SRC_DIR)/, cmds.c envps.c file.c free.c init.c pipe.c pipex.c process.c split_args.c)
OBJS		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Colors
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
RESET		:= \033[0m

# Default Target
all: $(NAME)

# Executable Rule
$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDES)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Object Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create obj folder if needed
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Clean Pipex Object Files
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files cleaned.$(RESET)"

# Clean Everything
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)All cleaned.$(RESET)"

# Recompile Everything
re: fclean all

# Norminette Check (optional)
norm:
	norminette $(SRC_DIR) $(INCL_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re norm
