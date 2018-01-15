/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:38:28 by eflorenz          #+#    #+#             */
/*   Updated: 2018/01/10 19:38:38 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

t_window	*g_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_window	*win;

	if (!(win = (t_window*)malloc(sizeof(t_window))))
		return (NULL);
	win->win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
	win->size_x = size_x;
	win->size_y = size_y;
	win->title = strdup(title);
	win->img_front = g_new_img(mlx_ptr, size_x, size_y);
	win->img_back = g_new_img(mlx_ptr, size_x, size_y);
	win->img_current = win->img_front;
	win->img_next = win->img_back;
	win->mlx_ptr = mlx_ptr;
	win->text_buffer = NULL;
	return (win);
}

t_text		*g_make_text(int x, int y, int color, char *str)
{
	t_text	*text;

	if (!(text = (t_text*)malloc(sizeof(t_text))))
		return (NULL);
	text->x = x;
	text->y = y;
	text->color = color;
	text->str = ft_strdup(str);
	return (text);
}

void		g_add_to_text_buffer(t_window *win, t_text *text)
{
	t_list	*l_text;

	if (!(l_text = ft_lstnew(text, sizeof(t_text))))
		return ;
	ft_lstadd(&(win->text_buffer), l_text);
}

void		g_render_delete_text_buffer(t_window *win)
{
	t_list	*l_elem;
	t_list	*tmp;
	t_text	*elem;

	l_elem = win->text_buffer;
	while (l_elem != NULL)
	{
		elem = (t_text*)(l_elem->content);
		mlx_string_put(win->mlx_ptr, win->win_ptr, elem->x, elem->y, elem->color, elem->str);
		free(elem->str);
		free(elem);
		tmp = l_elem;
		l_elem = l_elem->next;
		free(tmp);
	}
	win->text_buffer = NULL;
}

int			g_update(t_window *win)
{
	t_img	*tmp;

	tmp = win->img_current;
	win->img_current = win->img_next;
	win->img_next = tmp;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (!(mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
					(win->img_current)->img, 0, 0)))
		return (0);
	return (1);
}
