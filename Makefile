NAME = push_swap

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = src

SRCS = src/main.c
SRCS += src/sort/sort.c src/sort/simplify.c src/sort/radix_sort.c src/sort/sort5.c src/sort/sort3.c src/sort/sort2.c src/sort/move_top_element.c
SRCS += src/array/contains_duplicates.c src/array/array_is_sorted.c src/array/index_of.c src/array/array_sort.c
SRCS += src/output/output_operation_list.c
SRCS += src/deque/deque_find_min.c src/deque/deque_is_sorted.c src/deque/deque_pop.c src/deque/deque_size.c src/deque/list_new.c src/deque/deque_clear.c src/deque/deque_new.c src/deque/deque_sort.c src/deque/deque_push.c src/deque/deque_peek.c src/deque/deque_append.c src/deque/deque_find_max.c src/deque/deque_deep_copy.c src/deque/deque_rotate.c
SRCS += src/load/load_stacks_from_string.c src/load/checked_atoi.c src/load/checked_atou.c src/load/load_stacks_from_strings.c src/load/load_stacks.c src/load/optionals.c
SRCS += src/stack/stack_push.c src/stack/stack_rotate.c src/stack/stack_rrotate.c src/stack/stack_swap.c
SRCS += src/error/die.c src/error/error_repr.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR)
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

.PHONY: run
run: build
	./$(NAME)

.PHONY: build
build: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# Compilation
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_MAKE_PATH)


.PHONY: re
re: fclean build

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	make clean -C $(LIBFT_MAKE_PATH)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_MAKE_PATH)

# VERBOSITY = --verbose

# LSP stuff, don't worry about it
.PHONY: update
update: fclean
	mkdir -p $(BUILD_DIR)
	bear $(VERBOSITY) --output $(BUILD_DIR)/compile_commands.json -- make build

.PHONY: test
test: $(LIBFT)
	cmake -S test -B build/test
	cmake --build build/test
	GTEST_COLOR=1 ctest --test-dir build/test

.PHONY: vtest
vtest: $(LIBFT)
	cmake -S test -B build/test
	cmake --build build/test
	GTEST_COLOR=1 ctest --test-dir build/test -V

CPPCHECKFLAGS  = --language=c
# not available on distant server CPPCHECKFLAGS += --check-level=exhaustive
CPPCHECKFLAGS += --cppcheck-build-dir=build
CPPCHECKFLAGS += --project=build/compile_commands.json
.PHONY: check
check: update
	cppcheck $(CPPCHECKFLAGS)
	norminette $(SRC_DIR)
	norminette lib

# aliases
.PHONY: b c u r t vt
b: build
c: clean
u: update
r: run
t: test
vt: vtest

-include $(DEPS)
