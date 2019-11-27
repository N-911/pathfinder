NAME = pathfinder

INC = lib_pathfinder.h

INCI = inc/lib_pathfinder.h

SRC = 	mx_check_errors.c  \
	mx_error_doesnt_exist.c \
	mx_error_argc.c \
        mx_error_is_empty.c \
	mx_error_line1.c \
	mx_fill_struct.c \
	mx_index_v.c \
	mx_floyd_warshall.c \
	main.c \
	mx_parse_string.c \
	mx_back_tracking.c \
	mx_find_all_paths.c \
	mx_print_path.c \
	mx_pr_int.c \
	mx_init_m_d.c \
	mx_fill_m_a_struct.c \
	mx_split.c

SRCS = $(addprefix src/, \
	mx_check_errors.c \
	mx_error_doesnt_exist.c \
	mx_error_argc.c \
	mx_error_is_empty.c \
	mx_error_line1.c \
	mx_fill_struct.c \
	mx_index_v.c \
	mx_floyd_warshall.c \
	main.c \
	mx_parse_string.c \
	mx_back_tracking.c \
	mx_find_all_paths.c \
	mx_print_path.c \
	mx_pr_int.c \
	mx_init_m_d.c \
	mx_fill_m_a_struct.c \
	mx_split.c)

OBJ = 	mx_check_errors.o \
	mx_error_doesnt_exist.o \
	mx_error_argc.o \
	mx_error_is_empty.o \
	mx_error_line1.o \
	mx_fill_struct.o \
	mx_index_v.o \
	mx_floyd_warshall.o \
	main.o \
	mx_parse_string.o \
	mx_back_tracking.o \
	mx_find_all_paths.o \
	mx_print_path.o \
	mx_pr_int.o \
	mx_init_m_d.o \
	mx_fill_m_a_struct.o \
	mx_split.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mkdir -p obj
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C libmx
	@rm -rf $(NAME)

clean:
	@make clean -C libmx
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf $(OBJ)
	@rm -rf ./obj
reinstall: uninstall all
