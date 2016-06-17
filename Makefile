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

NAME =				rtv1

SRC =				./sources/main.c \
					./sources/start.c \
					./sources/init_sdl.c \
					./sources/destroy_sdl.c \
					./sources/exit_rtv1.c \
					./sources/thread.c \
					./sources/raytracing.c \
					./sources/get_next_line.c \
					./sources/analyse_scene.c \
					./sources/analyse_3d_value.c \
					./sources/analyse_objects.c

OBJS =				./main.o \
					./start.o \
					./init_sdl.o \
					./destroy_sdl.o \
					./exit_rtv1.o \
					./thread.o \
					./raytracing.o \
					./get_next_line.o \
					./analyse_scene.o \
					./analyse_3d_value.o \
					./analyse_objects.o

LIBFT =				./libft/libft.a

LIBDRAW =			./libdraw/draw.a

PATHSDL =			SDL2-2.0.4

PATHFRAMEWORKSDL =	SDL2.framework

MAKEFILESDL =		$(shell ls SDL2-2.0.4/Makefile 2>&-)

DEBUGSEGFAULT =		-fsanitize=address

EXTRAFLAGS =		#-Wall -Wextra -Werror #$(DEBUGSEGFAULT)

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
$(NAME): $(PATHDYNLIB) $(LIBFT) $(LIBDRAW) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LIBDRAW) $(LFLAGS) -o $(NAME)
	$(EDITLIB)

$(PATHDYNLIB):
	@echo "$(PATHDYNLIB)"
	cd $(PATHSDL) && ./configure && make -j

else
$(NAME): $(LIBFT) $(LIBDRAW) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LIBDRAW) $(LFLAGS) -o $(NAME)
	$(EDITLIB)

endif

else
$(NAME): $(PATHDYNLIB) $(LIBFT) $(LIBDRAW) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LIBDRAW) $(LFLAGS) -o $(NAME)


ifeq ($(XORGDEV),)
$(PATHDYNLIB):
	@echo "Package xorg-dev must be installed"
	@kill -INT 0

else
$(PATHDYNLIB):
	cd $(PATHSDL) && ./configure && make

endif

endif

$(OBJS): $(LIBFT) $(LIBDRAW)
	$(CC) $(EXTRAFLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(LIBDRAW):
	make -C ./libdraw/

ifeq ($(COMPILE_SDL),YES)
fclean: clean cleansdl
	$(RM) $(NAME) $(LIBFT) $(LIBDRAW)
	make clean -C ./libft/
	make clean -C ./libdraw/
	$(RM) ./$(PATHSDL)/config.log ./$(PATHSDL)/sdl2-config.cmake ./$(PATHSDL)/sdl2.pc

else
fclean: clean cleansdl
	$(RM) $(NAME) $(LIBFT) $(LIBDRAW)
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
	make clean -C ./libdraw/

cleanr:
	$(RM) $(OBJS) $(NAME)

r: cleanr all

re: fclean all
