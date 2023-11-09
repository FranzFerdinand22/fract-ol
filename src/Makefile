# env
PROGRAM = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
RM = rm -rf

# sources
SRC = main.c \
		init.c \
		render.c \
		utils.c \
		events.c \
		render_utils.c 

OBJ = $(SRC:.c=.o)

# make
all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJ) $(LIBS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
 
clean:
						@$(RM) $(OBJ)
						@echo "Object files deleted!"

fclean:			clean
						@$(RM) $(PROGRAM)
						@echo "All deleted!"

re:				fclean all
