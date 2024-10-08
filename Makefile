NAME = push_swap

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = src
LIB_DIR = lib

__SRCS = main.c
__SRCS += load/load_stacks_from_string.c load/checked_atoi.c load/checked_atou.c load/load_stacks_from_strings.c load/load_stacks.c load/optionals.c
__SRCS += stack/stack_push.c stack/stack_rotate.c stack/stack_rrotate.c stack/stack_swap.c
__SRCS += sort/sort.c sort/simplify.c sort/radix_sort.c sort/sort5.c sort/sort3.c sort/sort2.c sort/move_top_element.c
__SRCS += output/output_operation_list.c
__SRCS += array/contains_duplicates.c array/array_is_sorted.c array/index_of.c array/array_sort.c
__SRCS += deque/deque_find_min.c deque/deque_is_sorted.c deque/deque_pop.c deque/deque_size.c deque/list_new.c deque/deque_clear.c deque/deque_new.c deque/deque_sort.c deque/deque_push.c deque/deque_peek.c deque/deque_append.c deque/deque_find_max.c deque/deque_deep_copy.c deque/deque_rotate.c
__SRCS += error/die.c error/error_repr.c

SRCS = $(addprefix $(SRC_DIR)/, $(__SRCS))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR)
CPPFLAGS += -MMD -MP

LIBFT_PATH = ./$(LIB_DIR)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_MAKE_PATH = $(LIBFT_PATH)
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)

CPPFLAGS += -I$(LIBFT_PATH)/include
LDLIBS = $(LIBFT)

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
	cmake -S test -B $(BUILD_DIR)/test
	cmake --build $(BUILD_DIR)/test
	GTEST_COLOR=1 ctest --test-dir $(BUILD_DIR)/test

.PHONY: vtest
vtest: $(LIBFT)
	cmake -S test -B $(BUILD_DIR)/test
	cmake --build $(BUILD_DIR)/test
	GTEST_COLOR=1 ctest --test-dir $(BUILD_DIR)/test -V

CPPCHECKFLAGS  = --language=c
# not available on distant server CPPCHECKFLAGS += --check-level=exhaustive
CPPCHECKFLAGS += --cppcheck-build-dir=$(BUILD_DIR)
CPPCHECKFLAGS += --project=$(BUILD_DIR)/compile_commands.json
.PHONY: check
check: update
	cppcheck $(CPPCHECKFLAGS)
	norminette $(SRC_DIR)
	norminette $(LIB_DIR)

# aliases
.PHONY: b c u r t vt
b: build
c: clean
u: update
r: run
t: test
vt: vtest

-include $(DEPS)
