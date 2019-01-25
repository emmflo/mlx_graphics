#include <stdlib.h>
#include "graphics.h"

void		g_img_copy(t_img *dest, t_img *src)
{
	int	i;

	if (dest == NULL && src == NULL)
		return ;
	i = 0;
	while (i < dest->width * dest->height * (*dest->bits_per_pixel / 8) &&
		i < src->width * src->height * (*src->bits_per_pixel / 8))
	{
		dest->data[i] = src->data[i];
		i++;
	}
}
