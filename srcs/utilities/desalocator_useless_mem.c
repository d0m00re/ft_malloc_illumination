#include "utilities.h"


typedef struct s_fucking_control
{
	t_ll_itf *begining;
	size_t c_chunk_area;
	size_t c_free_area;
} t_fucking_control;

void init_struct_fucking_control(t_fucking_control *c, void *begining)
{
	c->begining = begining;
	c->c_chunk_area = 0;
	c->c_free_area = 0;
}

/*
** parcourir la structure de reference principal
** update structure
** free dans le cas ou on a aucune zone  alloue chunk
*/

int	is_empty_area(t_fucking_control *control)
{
	if (control->c_chunk_area == 0 && control->begining)
		return (1);
	return (0);
}

int	free_data_area(t_fucking_control *control)
{
	t_ll_itf *i;
	unsigned int c = 0;
	void *data;

	if (!is_empty_area(control))
		return (0);
	desalloc(control->begining->next, control->begining->size);
	c = 0;
	//i = control->begining;
//	ft_putchar('-'); ft_putnbr_ui(control->c_free_area); ft_putchar('-');
//	ft_putstr("(");
	data = control->begining;
	i = data;
	while (c <= control->c_free_area)
	{
  /*              if (i->type == MAIN_CHUNK_REF)
			ft_putstr("\n1 ");
		else if (i->type == MAIN_CHUNK_DATA)
			ft_putstr(" 2 ");
		else if (i->type == SUB_CHUNK_DATA)
			ft_putstr(" 3");
		else if (i->type == SUB_FREE_DATA)
			ft_putstr("4 ");
		else if (i->type == 5)
			ft_putstr("5 ");
		else
			ft_putstr("- ");*/
		i->type = 5;
		i = data + 16 * (1 + c);
		c++;		
	}
	ft_putstr(")\n");
	return (1);
}

void main_desalocator(void *elem, size_t size_data, t_fucking_control *control)
{
	unsigned int    size;
	t_ll_itf                *i;
	t_ll_itf                *o;
	void                    *data;

	data = elem;
	i = data;
	size_data++;
	init_struct_fucking_control(control, 0);
	while (i)
	{
		size = 0;
		while (i && size < i->size)
		{
			o = (data + size);
			if (o->type == MAIN_CHUNK_REF)
			{
				//ft_putstr("\n1 ");
				init_struct_fucking_control(control, 0);
			}
			else if (o->type == MAIN_CHUNK_DATA)
			{
				if (is_empty_area(control))
				{
					//ft_putstr("free ma salope ..... :) ");
					free_data_area(control);
				}
				//ft_putstr("\n\t2 ");
				init_struct_fucking_control(control, o);
			}
			else if (o->type == SUB_CHUNK_DATA)
			{
				//ft_putstr("3 ");
				control->c_chunk_area += 1;
			}
			else if (o->type == SUB_FREE_DATA)
			{
				//ft_putstr("4 ");
				control->c_free_area += 1;
			}
			else if (o->type == 5)
			{
				//ft_putstr("5 ");
			}
			size += 16;
		}
	//	ft_putstr("------------------------- ");
		data = i->next;
		i = i->next;
        }
}

void desalocator_useless_mem(void)
{
	t_fucking_control control;

	// free for tiny
	//ft_putstr("\ntiny : ");
	main_desalocator(g_alloc->tiny, SIZE_TINY_ZONE, &control);
	// free for medium
	//ft_putstr("\nmedium : ");
	main_desalocator(g_alloc->medium, SIZE_MEDIUM_ZONE, &control);
	//free for large
	//ft_putstr("\nlarge : ");
	main_desalocator(g_alloc->large, SIZE_PAGE, &control);
}
