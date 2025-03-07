CC = cc
CFLAGS = -Wall -Wextra ##-fsanitize=address

SRC = load_map.c flood_fill.c ft_mlx_imag.c Functions_are_not_included.c get_next_line.c get_next_line_utils.c

BSRC = bonus/load_map_bonus.c bonus/flood_fill_bonus.c bonus/ft_mlx_imag_bonus.c \
		bonus/Functions_are_not_included_bonus.c bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c bonus/main_bonus.c

OBJ = $(SRC:%.c=%.o)
BNAME = soolong
NAME = so_long
HFILE = so_long.h
HEADERFILEB =  bonus/so_long_bonus.h
BOBJF=$(BSRC:%.c=%.o)

all: $(NAME)

bonus: $(BNAME)

$(NAME): main.c $(OBJ)
	$(CC) $(CFLAGS) $^ -L ./mlx -lmlx -lXext -lX11 -o $@

$(BNAME): $(BOBJF)
	$(CC) $(CFLAGS) $^ -L ./bonus/mlx -lmlx -lXext -lX11 -o $@

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $< -o $@



%bonus.o: %bonus.c $(HEADERFILEB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BOBJF)

fclean: clean
	rm -f $(NAME) $(BNAME)

re:	fclean all

.PHONY: clean



