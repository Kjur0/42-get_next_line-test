# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/24 18:57:37 by kjurkows          #+#    #+#              #
#    Updated: 2026/07/25 17:59:52 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	get_next_line-test

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
CXX				=	c++
CXXFLAGS		=	-std=c++17 -Wall -Wextra -Werror -g
BONUS_FLAGS		=	-D BONUS

GNL_DIR			=	./get_next_line
SRCS_DIR		=	./srcs
OBJS_DIR		=	./build

GTEST_FLAGS		=	-lgtest -lpthread
INCLUDES		=	-I$(GNL_DIR)

SRCS			=	_main.cpp \
					assets.cpp \
					errors.cpp \
					stdin.cpp
GNL_SRCS		=	get_next_line.c \
					get_next_line_utils.c
GNL_BONUS_SRCS	=	get_next_line_bonus.c \
					get_next_line_utils_bonus.c

OBJS			=	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)
GNL_OBJS		=	$(GNL_SRCS:%.c=$(OBJS_DIR)/gnl/%.o)
GNL_BONUS_OBJS	=	$(GNL_BONUS_SRCS:%.c=$(OBJS_DIR)/gnl/%.o)

RM				=	rm -rf

RED				=	\033[;31m
GREEN			=	\033[;32m
YELLOW			=	\033[;33m
BLUE			=	\033[;34m
MAGENTA			=	\033[;35m
CYAN			=	\033[;36m
RESET			=	\033[0m
POSITION		=	\033[2K\r

all: $(OBJS) $(GNL_OBJS)
	@echo -n "$(CYAN)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) $(GNL_OBJS:%.o=%1.o) $(GTEST_FLAGS) -o $(NAME)1 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(OBJS) $(GNL_OBJS:%.o=%2.o) $(GTEST_FLAGS) -o $(NAME)2 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(OBJS) $(GNL_OBJS:%.o=%3.o) $(GTEST_FLAGS) -o $(NAME)3 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(OBJS) $(GNL_OBJS:%.o=%4.o) $(GTEST_FLAGS) -o $(NAME)4 -fsanitize=address
	@echo "$(POSITION)$(GREEN)Compiled $(NAME)!$(RESET)"

bonus: $(OBJS) $(GNL_BONUS_OBJS)
	@echo -n "$(CYAN)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(BONUS_FLAGS) $(OBJS) $(GNL_BONUS_OBJS:%.o=%1.o) $(GTEST_FLAGS) -o $(NAME)1 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(BONUS_FLAGS) $(OBJS) $(GNL_BONUS_OBJS:%.o=%2.o) $(GTEST_FLAGS) -o $(NAME)2 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(BONUS_FLAGS) $(OBJS) $(GNL_BONUS_OBJS:%.o=%3.o) $(GTEST_FLAGS) -o $(NAME)3 -fsanitize=address
	@$(CXX) $(CXXFLAGS) $(BONUS_FLAGS) $(OBJS) $(GNL_BONUS_OBJS:%.o=%4.o) $(GTEST_FLAGS) -o $(NAME)4 -fsanitize=address
	@echo "$(POSITION)$(GREEN)Compiled $(NAME)!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@echo -n "$(CYAN)Compiling $(basename $(notdir $<))...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $<!$(RESET)"

$(OBJS_DIR)/gnl/%.o: $(GNL_DIR)/%.c | $(OBJS_DIR)
	@echo -n "$(CYAN)Compiling $(basename $(notdir $<))...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(@:%.o=%1.o)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(INCLUDES) -c $< -o $(@:%.o=%2.o)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(INCLUDES) -c $< -o $(@:%.o=%3.o)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=2048 $(INCLUDES) -c $< -o $(@:%.o=%4.o)
	@echo "$(POSITION)$(GREEN)Compiled $<!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/gnl

clean:
	@echo -n "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@echo "$(POSITION)$(GREEN)Cleaned object files!$(RESET)"

fclean: clean
	@echo -n "$(YELLOW)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)1
	@$(RM) $(NAME)2
	@$(RM) $(NAME)3
	@$(RM) $(NAME)4
	@echo "$(POSITION)$(GREEN)Cleaned $(NAME)!$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
