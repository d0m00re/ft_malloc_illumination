#include "utilities.h"

static void view_one_area(void *elem, size_t size_data)
{
        unsigned int    size;
        t_ll_itf                *i;
        t_ll_itf                *o;
        void                    *data;

        data = elem;
        i = data;
        size_data++;
        while (i)
        {
                size = 0;
                while (i && size < i->size)
                {
                        o = (data + size);
                        if (o->type == MAIN_CHUNK_REF)
                                ft_putstr("\n1 ");
                        else if (o->type == MAIN_CHUNK_DATA)
                                ft_putstr("\n\t2 ");
                        else if (o->type == SUB_CHUNK_DATA)
                                ft_putstr("3 ");
                        else if (o->type == SUB_FREE_DATA)
				ft_putstr("4 ");
			else if (o->type == 5)
				ft_putstr("5 ");
			size += 16;
		}
		ft_putstr("------------------------- ");
		data = i->next;
		i = i->next;
        }
}

void view_area(void)
{
	ft_putstr("\ntiny : ");
	view_one_area(g_alloc->tiny, SIZE_TINY_ZONE);
	ft_putstr("\nmedium : ");
	view_one_area(g_alloc->medium, SIZE_MEDIUM_ZONE);
	ft_putstr("\nlarge : ");
	view_one_area(g_alloc->large, SIZE_PAGE);
}
