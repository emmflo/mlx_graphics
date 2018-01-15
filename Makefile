OBJDIR := objs
OBJLIST := \
	draw.o \
	draw_line.o \
	draw_fill.o \
	draw_utils.o \
	window.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJLIST))
CC := clang
SRCDIR := srcs
INCDIR := includes
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR) -I../minilibx/ -I../libft/includes
NAME := libmlx_graphics.a

.PHONY : all clean fclean binclean re

all : $(NAME)
	
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean :
	rm -rf $(OBJDIR)

binclean:
	rm -f $(NAME)

fclean : clean binclean

re : fclean all
