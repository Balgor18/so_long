#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

enum e_error
{
	E_SUCCESS = 0,
	E_MALLOC_FAIL = -1,
	E_READ_FAIL = 2,
};

const char *e_message[] =
{
	"-",
	"Malloc Has FAILED!",
	"Read Has FAILED!"
};

typedef struct	s_gnl
{
	struct s_gnl	*next;
	char			buf[10];
}				t_gnl;

struct	s_data
{
	size_t	line_size;
	size_t	rd_size;
	size_t	list_buff_size;
	char	*ptrchr;

	int		error;
	t_gnl	*gnl;

};

struct 	s_mem
{
	char	str[10];
	size_t	size;
	int		status;
};

void	ft_print_buffer_chains(t_gnl *gnl)
{
	dprintf(2, "%s--------------------------------------\n", "\033[33m");
	dprintf(2, "\n\tBUFFER LIST:\n");
	while (gnl)
	{
		dprintf(2, ">>[%.10s] |%p|\n", gnl->buf, gnl->next);
		gnl = gnl->next;
	}
	dprintf(2, "--------------------------------------%s\n",  "\033[0m");
}

void	ft_print_data(struct s_data *data, char *line)
{
	dprintf(2, "\n%s_______________________________________\n",  "\033[32m");
	dprintf(2, "========================================\n");
	dprintf(2, "\tSTRUCTURE DATA\n");
	dprintf(2, "Line [%s]\n\n", line);
	dprintf(2, "Read Value [%lu]\n", data->rd_size);
	dprintf(2, "Line Size [%lu]\n", data->line_size);
	dprintf(2, "Buffer list Size [%lu]\n", data->list_buff_size);
	dprintf(2, "Pointer on newline >%p<\n", data->ptrchr);
	dprintf(2 , "ERROR Value : [%s]\n", e_message[data->error * -1]);
	ft_print_buffer_chains(data->gnl);

}

void	ft_print_res(struct s_mem *rest)
{
	dprintf(2, "\tREST = (%lu) [%.127s]\n", rest->size, rest->str);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
//		dprintf(2,">>[%c] avec n [%lu]<<\n", *p, n);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	printf("------\nenter memcpyn\ndest = |%s|\nsrc = |%s|\n------\n",dest, src);
	if (!dest && !src) // <= Que ce passe t-il if dest est vide? mais pas source. Proteger ou ne pas proteger tel est la question.
		return (NULL);
//	dprintf(2, "++++++DEST >%d< ++++++SRC >%d< ++++++++SIZE >%lu< +++++=\n", ((char *)dest)[0],((const char *)src)[0], n);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
//	dprintf(2, "++++++ END >%d< +++++++SRC >%C< +++++++++++=\n", ((char *)dest)[0], ((const char *)src)[0]);
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

void	ft_lstdelall(t_gnl **lst)
{
	t_gnl	*tmp;

	dprintf(2, "LSTDELALL!\n");
	while (*lst)
	{
		dprintf(2, "@@\n");
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
}

int	ft_lstaddnew_front(struct s_data *data)
{
	t_gnl	*new_elem;

	// dprintf(2, "##NEW ELEMENT\n");
	new_elem = malloc(sizeof(t_gnl));
	if (!new_elem)
	{
		data->error =  E_MALLOC_FAIL;
		return (0);
	}
	*new_elem = (t_gnl){0};
	new_elem->next = data->gnl;
	data->gnl = new_elem;
	return (1);
}

void ft_cpy_buffer_list(t_gnl **gnl, char *line)
{
	t_gnl *tmp;

	while (*gnl)
	{
		ft_memcpy(line - 10, (*gnl)->buf, 10);
		line -= 10;
		tmp = (*gnl)->next;
		free(*gnl);
		*gnl = tmp;
	}
}

int ft_create_newline_from_buffer(struct s_data *data, struct s_mem *rest, char **line)
{
	int newline_size;
	printf("segfault 0.4.0\n");
	newline_size = rest->size + data->line_size;

	// dprintf(2, "##CREATE_BUFF >>%d<<\n", newline_size);
	// ft_print_data(data, *line);
	// ft_print_res(rest);

	// MALLOC
	*line = malloc(sizeof(char) * (newline_size + 1));
	// CHECK FAILLURE
	if (!*line)
	{
		ft_lstdelall(&(data->gnl));
		data->error = E_MALLOC_FAIL;
		return (-1);
	}
	// SET LAST BACKSLASH ZERO
	(*line)[newline_size] = '\0';

	// COPY REST
	ft_memcpy(*line, rest->str, rest->size);
	printf("segfault 0.4.1\n");
	// NEW REST
	// dprintf(2, "#create nw copy rest\n");
	// ft_print_data(data, *line);
	// ft_print_res(rest);


	// COPY BUFFERS STARTING FROM THE END
	ft_cpy_buffer_list(&(data->gnl->next), *line + rest->size + data->list_buff_size);
	printf("segfault 0.4.2\n");
	// COPY TILL NEWLINE FROM THE LAST BUF
	ft_memcpy(*line + data->line_size + rest->size , data->gnl->buf, data->line_size - data->list_buff_size);
	printf("segfault 0.4.3\n");
	// NEW REST
	// dprintf(2, "#create nw rest\n");
	// ft_print_data(data, *line);
	// ft_print_res(rest);

	if (data->rd_size)
	{
		printf("%zu\ndata->ptrchr = %s\ndata->gnl->buf = %s\n", data->rd_size, data->ptrchr, data->gnl->buf);
		printf("%p\n%p\n", data->ptrchr, data->gnl->buf);
		printf("%zu\n", data->ptrchr - data->gnl->buf);
		rest->size = data->rd_size - (data->ptrchr - data->gnl->buf) - 1;
		printf("rest->size %zu\n", rest->size);
		printf("segfault 0.4.3.0\n");
		printf("---------\nrest->str = |%s|\ndata->ptrchr = |%s|\nrest->size %zu\n---------\n",rest->str, data->ptrchr, rest->size);
		ft_memcpy(rest->str, data->ptrchr + 1 , rest->size);
		printf("segfault 0.4.3.1\n");
	}
	else // ALL COPIED
	{
		rest->size = 0;
	}
	printf("segfault 0.4.4\n");
	// dprintf(2, "#after nw creation\n");
	// ft_print_data(data, *line);
	// ft_print_res(rest);

	return (newline_size);
}

int ft_no_newline_in_rest(struct s_data *data, struct s_mem *rest, char **line)
{
	// CHECK newline
	data->ptrchr = ft_memchr(rest->str, '\n', rest->size);

	// dprintf(2, "NW_REST\n");
	// ft_print_data(data, *line);
	// ft_print_res(rest);

	// IF no \n and not EOF
	if (!data->ptrchr && rest->status)
		return (1);
	// IF \n
	else if (data->ptrchr)
	{
		// CALC LINE_SIZE
		data->line_size = data->ptrchr - rest->str;
	}
	// IF EOF
	else
	{
		// CALC LINE_SIZE
		data->line_size = rest->size;
	}

	//MALLOC
	*line = malloc(sizeof(char *) * (data->line_size + 1));
	// CHECK FAILURE
	if (!*line)
	{
		data->error = E_MALLOC_FAIL;
		return (-1);
	}

	// CPY LINE
	ft_memcpy(*line, rest->str, data->line_size);
	(*line)[data->line_size] = '\0';


	// NEW REST => rest_size - strlen(line_size) - '\n'
	rest->size = rest->size - data->line_size - 1;
	ft_memmove(rest->str, rest->str + data->line_size + 1, rest->size);

	return (0);

}

int ft_no_buffer_in_read(struct s_data *data, struct s_mem *rest, int fd)
{
	int ret;

	// dprintf(2, "TO_BE_READ >>%zu<<\n", data->rd_size);
	ret = read(fd, data->gnl->buf, 10);

	// dprintf(2, "READED >>%i<<\n", ret);
	// IF READ ERROR
	if (ret < 0)
	{
		data->error = E_READ_FAIL;
		return (0);
	}
	// ft_print_data(data, NULL);
	data->rd_size = ret;
	// IF LAST READ TODO => DO NOT KNOW HOW TO FINISH;
	if (ret < 10)
	{
		rest->status = 1;
		return (ret != 0);
	}
	return (1);
}

int ft_no_newline_in_buffer(struct s_data *data, struct s_mem *rest)
{
	data->ptrchr = ft_memchr(data->gnl->buf, '\n', data->rd_size);

	printf("--------\nhey |%s|\nstatus = %d\n--------\n", data->ptrchr, rest->status);
	// IF no n and not EOF
	if (data->ptrchr && rest->status)
	{
		data->line_size += data->rd_size;
		dprintf(2, "NO \\N U EOF NW_BUFF \n");
		// ft_print_data(data, NULL);
		// ft_print_res(rest);

		return (1);
	}
	// IF \n
	else if (data->ptrchr)
	{
		data->line_size += data->ptrchr - data->gnl->buf;
		data->rd_size = data->rd_size - (data->ptrchr - data->gnl->buf) - 1;
		dprintf(2, "\\N NW_BUFF \n");
		// ft_print_data(data, NULL);
		// ft_print_res(rest);
		return (0);
	}
	// EOF
	else if (rest->status)
	{
		data->line_size += data->rd_size;
		data->rd_size = 0;
		dprintf(2, "EOF NW_BUFF \n");
		// ft_print_data(data, NULL);
		// ft_print_res(rest);
		return(0);
	}
	// exit(127);
	return (1);
}

int	get_next_line(int fd, char **line , int reset)
{
	static struct s_mem	rest = (struct s_mem){};
	struct s_data		data;

	// INITIALIZATION
	printf("segfault 0\n");
	data = (struct s_data){0};
	*line = NULL;

	// RESET DE GNL
	if (reset)
	{
		rest.size = 0;
		rest.status = 0;
	}
	printf("segfault 0.1\n");
	// IF REST

	if (rest.size && !ft_no_newline_in_rest(&data, &rest, line)) // SEARCH IN REST -> stop if error || no newline
	{
		return (data.line_size);
	}
	// READ
	else if (!rest.status)
	{
		printf("segfault 0.2\n");
		// dprintf(2, "##READING\n");
		// ft_print_res(&rest);
		// ft_print_data(&data, *line);

		while (!data.error // CHECK ERROR :
			&& ft_lstaddnew_front(&data) // INIT BUFFER -> stop if error
			&& ft_no_buffer_in_read(&data, &rest, fd) // READ IN BUFFER -> stop if error || no read
			&& ft_no_newline_in_buffer(&data, &rest)) // SEARCH IN BUFFER -> stop if error || newline
			{
				data.list_buff_size += data.rd_size;
			}
		// dprintf(2, "##CHECK ERROR\n");
		// ft_print_res(&rest);
		// ft_print_data(&data, *line);
		// Check if error
		printf("%zu\ndata->ptrchr = %s\ndata->gnl->buf = %s\n", data.rd_size, data.ptrchr, data.gnl->buf);
		printf("segfault 0.3\n");
		if (data.error)
		{
			ft_lstdelall(&(data.gnl));
			/*?*/ free(*line);
			*line = NULL;
			return (data.error);
		}
		// NOTHING LEFT TO READ
		else if (!rest.size && !data.rd_size && !data.line_size)
		{
			dprintf(2, "NOTHING to read\n");
			*line = NULL;
			return (0);
		}
		printf("segfault 0.4\n");
		//CREATE THE LINE or return ERROR
		return (ft_create_newline_from_buffer(&data, &rest, line));
	}
	printf("segfault 1\n");
	return (0);
}
