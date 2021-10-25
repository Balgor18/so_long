#include <stdlib.h>
#include <unistd.h>

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			buf[1024];
}			t_gnl;

struct	s_data
{
	size_t	rest_size;
	size_t	list_size;
	size_t	rd_size;
	char	buf[1024];
	t_gnl	*gnl;
	int error;
};

int	ft_lstaddnew_front(t_gnl **alst)
{
	t_gnl	*new_elem;

	new_elem = malloc(sizeof(t_gnl));
	if (!new_elem)
		return (0);
	new_elem->next = *alst;
	*alst = new_elem;
	return (1);
}

void	ft_lstdelone(t_gnl *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->buf);
		free(lst);
		lst = NULL;
	}
}

void	ft_lstclear(t_gnl **lst, void (*del)(void*))
{
	t_gnl	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int	get_rest_line(char **line, char *buf, size_t *size)
{
	char	*tmp;
	size_t	dif;

	tmp = ft_memchr(buf, '\n', *size);
	if (tmp)
	{
		dif = tmp - buf;
		*line = malloc(sizeof(char *) * (dif + 1));
		if (!*line)
			return (-1);
		*line = ft_memcpy(*line, buf, dif);
		*line[dif] = '\0';
		*size = *size - dif - 1;
		buf = ft_memmove(buf, tmp + 1, *size);
	}
	else
		return (0);
	return (dif);
}

static void	fonction_quifaisuntruc(t_gnl **gnl, char *line)
{
	t_gnl *tmp;

	while (*gnl)
	{
		ft_memcpy(line - 1024, (*gnl)->buf, 1024);
		line -= 1024;
		tmp = (*gnl)->next;
		free(*gnl);
		*gnl = tmp;
	}
}

/*
** size[3] => [rest_size, size, end_size]
*/

# include <stdio.h>

static int	init_and_copy_line(char **line, size_t size[3], struct s_data *data, char *rest)
{

	dprintf(2, "size[0] >>%lu<< size[1] >>%lu<< size[2] >>%lu<<\n", size[0], size[1], size[2]);
	*line = malloc(sizeof(char *) * (size[0] + size[1] + size[2] + 1));
	if (!*line)
	{
		ft_lstclear(&(data->gnl), &free);
		return (-1);
	}
	dprintf(2, "TEST1\n");
	ft_memcpy(*line + size[1] + size[0], data->gnl->buf, size[2]);
	dprintf(2, "TEST2\n");
	*line[size[0] + size[1] + size[2] + 1] = '\0';
	dprintf(2, "TEST3\n");
	fonction_quifaisuntruc(&(data->gnl->next), *line + size[1] + size[0]);
	dprintf(2, "TEST4\n");
	ft_memcpy(*line, rest, size[0]);
	dprintf(2, "TEST5\n");
	return (0);
}

static int	add_gnl(char **line, char *rest, size_t rest_size, struct s_data *data)
{
	char				*tmp;

	tmp = ft_memchr(data->gnl->buf, '\n', data->rd_size);
	if (tmp != NULL)
	{
		dprintf(2, "HEY >>%c<<\n", *(data->gnl->buf));
		data->rd_size -= tmp - data->gnl->buf;
		if (!init_and_copy_line(line, (size_t[3]){rest_size, data->list_size, data->rd_size}, data, rest))
		{
			return (-1); // malloc failed
		}
		ft_memmove(rest, tmp + 1, data->rd_size - 1);
		return (data->rd_size);
	}
	else
	{
		if (!ft_lstaddnew_front(&(data->gnl)))
		{
			ft_lstclear(&(data->gnl), &free);
			return (-1);
		}
		data->list_size += 1024;
	}
	return(0);
}

int	get_next_line(int fd, char **line , int reset)
{
	static char			rest[1024];
	static size_t		size = 0;
	struct s_data		data;

	data = (struct s_data){0};
	if (reset)
		size = 0;
	data.error = get_rest_line(line, data.buf, &size);
	if (data.error == -1)
		return (data.error);
	else if (data.error)
		return (data.error);
	data.rd_size = 1;
	while (data.rd_size > 0)
	{
		if (!ft_lstaddnew_front(&(data.gnl)))
		{
			ft_lstclear(&(data.gnl), &free);
			return (-1);
		}
		data.error = read(fd, data.gnl->buf, 1024);
		if (data.error == -1)
			return (-1); // what do if error
		if (!data.error && size) // nomore_backslashn;
		{
			init_and_copy_line(line, (size_t[3]){size, data.list_size, 0}, &data, rest);
		}
		else
		{
			data.rd_size = data.error;
			data.error = add_gnl(line, rest, size, &data);
			if (data.error == -1)
				return (data.error);
			else if (data.error > 0)
				return (data.rd_size);
		}
	}
	return (0);
}
