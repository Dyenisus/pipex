# Library Name
NAME := libft.a

# Compiler and flags
CC	:= cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs
RM := rm -f

# Directories
SRC_DIR := .
CORE_DIR := core
BONUS_DIR := bonus
GNL_DIR := get_next_line
PRINTF_DIR := ft_printf
OBJ_DIR := obj

# Header files
INCLUDES := -I $(SRC_DIR)

# Source files
CORE_FILES := $(shell find $(CORE_DIR) -type f -name "*.c" ! -name "*_bonus.c")
BONUS_FILES := $(shell find $(BONUS_DIR) -type f -name "*_bonus.c")
GNL_FILES := $(shell find $(GNL_DIR) -type f -name "*.c" ! -name "*_bonus.c")
PRINTF_FILES := $(shell find $(PRINTF_DIR) -type f -name "*.c")

# Object files (stored in libft/obj/)
CORE_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(CORE_FILES:.c=.o)))
BONUS_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_FILES:.c=.o)))
GNL_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_FILES:.c=.o)))
PRINTF_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_FILES:.c=.o)))

# Color 
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

# Default rule: Compile core + get_next_line + ft_printf
all: $(NAME)

$(NAME): $(CORE_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(CORE_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

bonus: $(NAME) $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling $(NAME) with bonus...$(RESET)"
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(CORE_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rules
clean:
	$(RM) $(CORE_OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all