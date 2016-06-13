#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/23 00:01:04 by                   #+#    #+#             *#
#*   Updated: 2016/02/11 12:25:46 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			draw.a

SRCS =			./draw_make_matrix.c \
				./draw_init_matrix.c \
				./draw_make_vector.c \
				./draw_add_vector.c \
				./draw_multiply_matrix.c \
				./draw_apply_matrix.c \
				./draw_array_layout.c \
				./draw_multiply_vector.c \
				./draw_add_scale.c \
				./draw_add_pos.c \
				./draw_get_rgb.c \
				./draw_get_hexa.c \
				./draw_find_color_gradient.c \
				./draw_divide_color.c

OBJS =			./draw_make_matrix.o \
				./draw_init_matrix.o \
				./draw_make_vector.o \
				./draw_add_vector.o \
				./draw_multiply_matrix.o \
				./draw_apply_matrix.o \
				./draw_array_layout.o \
				./draw_multiply_vector.o \
				./draw_add_scale.o \
				./draw_add_pos.o \
				./draw_get_rgb.o \
				./draw_get_hexa.o \
				./draw_find_color_gradient.o \
				./draw_divide_color.o

FLAGS = 		-Wall -Wextra -Werror

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all
