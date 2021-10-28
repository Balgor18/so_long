
#include "kali_gnl_with_comms.c"

// data->gnl->buf

int	ft_no_buffer_in_read(struct s_data *data, struct s_mem *rest, int fd)
{
	int	ret;

	ret = read(fd, data->gnl->buf, BUFF_SIZE);
	if (ret == -1)
	{
		data->error = E_READ_FAIL;
		return (0);
	}
	else if(ret > 0)
	{
		data->rd_size = ret;
	}
	else if (ret == 0)// EOF
	{
		data->rd_size = 0;
		rest->status = 1;
	}
	return (1);
}

int	ft_newline_in_buffer(struct s_data *data, struct s_mem *rest, char **line)
{
	data->ptrchr = ft_memchr(data->gnl->buf, '\n', data->rd_size);
	// data->ptrchr = 0x0
	// 	data->rd_size = data->rd_size - (data->ptrchr - data->gnl->buf) - 1;
	if (rest->status)
	{
		data->line_size += rest->size;
		*line = malloc(sizeof(char) * (data->line_size + 1));
		// CHECK FAILURE
		if (!*line)
		{
			data->error = E_MALLOC_FAIL;
			return (-1);
		}
		ft_memcpy(*line, rest->str, rest->size);
		(*line)[data->line_size] = '\0';

		ft_cpy_buffer_list_free(&(data->gnl), *line + data->line_size - 1, data->line_size - rest->size); // to do check
		rest->size = 0;
		return (1);
	}
	else if (data->ptrchr)
	{
		data->line_size += (data->ptrchr - data->gnl->buf) + rest->size;
		*line = malloc(sizeof(char) * (data->line_size + 1));
		// CHECK FAILURE
		if (!*line)
		{
			data->error = E_MALLOC_FAIL;
			return (-1);
		}
		ft_memcpy(*line, rest->str, rest->size);
		(*line)[data->line_size] = '\0';

		ft_memcpy(rest->str, data->ptrchr + 1, data->rd_size - (data->ptrchr - data->gnl->buf) - 1);
		ft_cpy_buffer_list_free(&(data->gnl), *line + data->line_size - 1, data->line_size - rest->size); // to do check
		rest->size = data->rd_size - (data->ptrchr - data->gnl->buf) - 1;
		return (1);
	}
	else
	{
		//MAYBE SOMETHING TO DO ?
	}
	return (0);
}
