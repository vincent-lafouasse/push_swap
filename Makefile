NAME = push_swap

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = src

SRCS = $(shell find "$(SRC_DIR)" -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP

LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_MAKE_PATH = $(LIBFT_PATH)
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)
LIBFT_LIB_PATH = $(LIBFT_PATH)

CPPFLAGS += -I$(LIBFT_PATH)/include
LDFLAGS = -L$(LIBFT_LIB_PATH)
LDLIBS = -lft
LIBS = $(LIBFT)

.PHONY: all
all: build
	echo $(SRCS)

.PHONY: run
run: all
	./a.out

.PHONY: build
build: $(NAME)

$(NAME): 
