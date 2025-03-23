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
CORE_FILES   := $(addprefix $(CORE_DIR)/, \
	ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
	ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c)

BONUS_FILES := $(addprefix $(BONUS_DIR)/, \
	ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c \
	ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c get_next_line_bonus.c)

GNL_FILES := $(addprefix $(GNL_DIR)/, \
	get_next_line.c)

PRINTF_FILES := $(addprefix $(PRINTF_DIR)/, \
	ft_printf.c ft_utils2.c ft_utils.c)

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