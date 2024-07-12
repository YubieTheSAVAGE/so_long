SRCS = sources/main.c sources/mlx_paths_vol0.c sources/mlx_paths_vol1.c sources/mlx_paths_vol2.c \
		sources/mlx_loader_vol0.c sources/mlx_animation_vol0.c sources/mlx_animation_vol1.c \
		sources/parsing_vol0.c sources/parsing_vol1.c sources/parsing_vol2.c sources/parsing_vol3.c \
		sources/so_long_utils0.c sources/so_long_utils1.c sources/so_long_utils2.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)
NAME = so_long
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT = libft/libft.a
# MLX = minilibx/libmlx.a

.c.o:
	@$(CC) $(FLAGS) -Imlx -c $< -o $(<:.c=.o)
	@printf "\033[32m[OK]\033[0m $<\n"

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make
	@printf "\033[32m[OK]\033[0m libft.a\n"
	@printf "\033[32m[OK]\033[0m libmlx.a\n"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx_Linux -o ${NAME} -lX11 -lXext
	@printf "\033[32m[OK]\033[0m $(NAME)\n"

clean:
	@$(RM) $(OBJS)
	@cd libft && make clean
	@printf "\033[32m[OK]\033[0m clean\n"

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean
	@printf "\033[32m[OK]\033[0m fclean\n"

re: fclean all	

.PHONY: all clean fclean re