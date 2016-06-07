# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#*   Updated: 2016/05/24 14:43:43 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

#OUT =				MAC
#OUT =				LINUX
OUT =				$(shell uname)

#COMPILE_SDL =		YES
COMPILE_SDL =		NO

#available on ubuntu or debian ect....
XORGDEV = $(shell dpkg -s xorg-dev 2>&-)

NAME =				wolf3d

SRC =				./sources/main.c \
					./sources/start.c \
					./sources/wolf_map.c \
					./sources/wolf3d.c \
					./sources/edit_wolf.c \
					./sources/delta_time.c \
					./sources/get_next_line.c \
					./sources/wolf_get_path.c \
					./sources/exit_wolf.c \
					./sources/wolf_check_map.c \
					./sources/error_text.c \
					./sources/wolf_complete_case.c \
					./sources/display_map.c \
					./sources/load_texture.c \
					./sources/clear_texture.c \
					./sources/trace.c \
					./sources/trace_monocolor.c \
					./sources/init_sdl.c \
					./sources/destroy_sdl_env.c \
					./sources/wolf_run.c

OBJS =				./main.o \
					./start.o \
					./wolf_map.o \
					./wolf3d.o \
					./edit_wolf.o \
					./delta_time.o \
					./get_next_line.o \
					./wolf_get_path.o \
					./exit_wolf.o \
					./wolf_check_map.o \
					./error_text.o \
					./wolf_complete_case.o \
					./display_map.o \
					./load_texture.o \
					./clear_texture.o \
					./trace.o \
					./trace_monocolor.o \
					./init_sdl.o \
					./destroy_sdl_env.o \
					./wolf_run.o

LIBFT =				./libft/libft.a

PATHSDL =			SDL2-2.0.4

PATHFRAMEWORKSDL =	SDL2.framework

MAKEFILESDL =		$(shell ls SDL2-2.0.4/Makefile 2>&-)

DEBUGSEGFAULT =		-fsanitize=address

EXTRAFLAGS =		-Wall -Wextra -Werror #$(DEBUGSEGFAULT)

CC =				gcc

RM =				rm -f

ifneq (,$(filter $(OUT),MAC Darwin))

ifeq ($(COMPILE_SDL),YES)
DYNLIB =			libSDL2-2.0.0.dylib
PATHDYNLIB =		./$(PATHSDL)/build/.libs/$(DYNLIB)
LFLAGS =			-L$(PATHSDL)/build/.libs -lSDL2
EDITLIB =			install_name_tool -change /usr/local/lib/$(DYNLIB) @executable_path/$(PATHDYNLIB) $(NAME)

else
LFLAGS =			-L./$(PATHFRAMEWORKSDL)/Versions/Current -F. -framework SDL2 -framework Cocoa
EDITLIB =			install_name_tool -change @rpath/$(PATHFRAMEWORKSDL)/Versions/A/SDL2 @executable_path/SDL2.framework/SDL2 $(NAME) && install_name_tool -change @executable_path/../Frameworks/$(PATHFRAMEWORKSDL)/SDL2 @executable_path/$(PATHFRAMEWORKSDL)/SDL2 $(NAME)

endif

else
PATHDYNLIB =		./$(PATHSDL)/build/.libs/libSDL2-2.0.so.0
SPECIFYLIB =		-Wl,-R`pwd`/$(PATHSDL)/build/.libs
LFLAGS =			$(SPECIFYLIB) -L$(PATHSDL)/build/.libs -lSDL2 -lm

endif

all: $(NAME)

ifneq (,$(filter $(OUT),MAC Darwin))

ifeq ($(COMPILE_SDL),YES)
$(NAME): $(PATHDYNLIB) $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)
	$(EDITLIB)

$(PATHDYNLIB):
	@echo "$(PATHDYNLIB)"
	cd $(PATHSDL) && ./configure && make -j

else
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)
	$(EDITLIB)

endif

else
$(NAME): $(PATHDYNLIB) $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)


ifeq ($(XORGDEV),)
$(PATHDYNLIB):
	@echo "Package xorg-dev must be installed"
	@kill -INT 0

else
$(PATHDYNLIB):
	cd $(PATHSDL) && ./configure && make

endif

endif

$(OBJS): $(LIBFT)
	$(CC) $(EXTRAFLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

ifeq ($(COMPILE_SDL),YES)
fclean: clean cleansdl
	$(RM) $(NAME) $(LIBFT)
	make clean -C ./libft/
	$(RM) ./$(PATHSDL)/config.log ./$(PATHSDL)/sdl2-config.cmake ./$(PATHSDL)/sdl2.pc

else
fclean: clean cleansdl
	$(RM) $(NAME) $(LIBFT)
	$(RM) ./$(PATHSDL)/config.log ./$(PATHSDL)/sdl2-config.cmake ./$(PATHSDL)/sdl2.pc

endif

ifeq ($(MAKEFILESDL),)
cleansdl:
	@echo "SDL clean"

else
cleansdl:
	make distclean -C ./$(PATHSDL)

endif

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/

r: clean all

re: fclean all
