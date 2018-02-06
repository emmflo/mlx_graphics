#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "mlx.h"
# ifdef __linux__
#  include <X11/X.h>
# endif
# include "libft.h"

typedef struct	s_gradient
{
	int		start;
	int		end;
}				t_gradient;

typedef struct	s_img
{
	char	*data;
	void	*img;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;
	int	height;
	int	width;
}				t_img;

typedef struct	s_window {
	void	*mlx_ptr;
	void	*win_ptr;	
	int		size_x;
	int		size_y;
	char	*title;
	t_img	*img_front;
	t_img	*img_back;
	t_img	*img_current;
	t_img	*img_next;
	t_list	*text_buffer;
}				t_window;

typedef struct	s_point {
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct s_point_int {
	int		x;
	int		y;
	int		z;
}				t_point_int;

typedef struct	s_line {
	t_point_int	start;
	t_point_int	end;
	double		z_index;
	t_gradient	color;
}		t_line;



typedef struct	s_line_int {
	t_point_int	a;
	t_point_int	b;
}				t_line_int;

typedef struct	s_rect_int {
	int		x;
	int		y;
	int		w;
	int		h;
}		t_rect_int;

typedef struct	s_hsv
{
	double	hue;
	double	saturation;
	double	value;
}		t_hsv;

typedef struct	s_text
{
	int	x;
	int	y;
	int	color;
	char	*str;
}		t_text;

t_window	*g_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		g_update(t_window *win);
t_img		*g_new_img(void *mlx_ptr, int width, int height);
void		g_put_pixel(t_img *img, t_point_int pt, int color);
void		g_draw_line(t_img *img, t_point_int a, t_point_int b, t_gradient color);
void		g_rect_fill(t_img *img, t_rect_int rect, int color);
void		g_window_fill(t_window *win, int color);
void		g_img_fill(t_img *img, int color);
int		lerp_rbg(t_gradient color, double t);
t_gradient	invert_gradient(t_gradient color);
t_line_int	pt_to_l(t_point_int a, t_point_int b);
void		g_rect_hsv_gradient(t_img *img, t_rect_int rect, double value);
int		g_hsv_to_color(t_hsv hsv);
int		g_rgb_to_color(int r, int g, int b);
void		g_render_delete_text_buffer(t_window *win);
void		g_add_to_text_buffer(t_window *win, t_text *text);
t_text		*g_make_text(int x, int y, int color, char *str);
void		g_img_copy(t_img *dest, t_img *src);
void		g_rect_hue_gradient(t_img *img, t_rect_int rect);

#endif
