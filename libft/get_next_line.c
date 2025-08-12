/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:21:47 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 11:01:23 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_read_file(int fd, char *buffer)
{
	char	*new_chunk;
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (!ft_strchr(buffer, '\n') && bytes_read == BUFFER_SIZE)
	{
		new_chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_chunk)
		{
			ft_free(&buffer);
			return (NULL);
		}
		bytes_read = read(fd, new_chunk, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&new_chunk), ft_free(&buffer));
		buffer = ft_strjoin(buffer, new_chunk);
		ft_free(&new_chunk);
	}
	return (buffer);
}*/

char	*ft_read_file(int fd, char *buffer)
{
	char	*new_chunk;
	int		bytes_read;
	char	*temp;

	bytes_read = BUFFER_SIZE;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (!ft_strchr(buffer, '\n') && bytes_read == BUFFER_SIZE)
	{
		new_chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_chunk)
			return (ft_free(&buffer), NULL);
		bytes_read = read(fd, new_chunk, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&new_chunk), ft_free(&buffer), NULL);
		temp = ft_strjoin_modif(buffer, new_chunk);
		ft_free(&new_chunk);
		if (!temp)
			return (ft_free(&buffer), NULL);
		buffer = temp;
	}
	return (buffer);
}

char	*ft_write_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_extra(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i])
	{
		next_line[j] = buffer[i];
		j++;
		i++;
	}
	ft_free(&buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_write_line(buffer);
	buffer = ft_extra(buffer);
	return (line);
}

/*int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char *line;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}*/
