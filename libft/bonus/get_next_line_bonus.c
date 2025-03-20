/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:02:44 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_helper(char *buffer, char *temp)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	if (!new_buffer)
	{
		free(temp);
		return (NULL);
	}
	return (new_buffer);
}

void	ft_manager(int i, char **buffer)
{
	char	*n_buffer;

	if ((*buffer)[i])
		n_buffer = ft_strdup(&(*buffer)[i]);
	else
		n_buffer = NULL;
	free(*buffer);
	*buffer = n_buffer;
}

char	*ft_reader(int fd, char	*buffer)
{
	int		readed_bytes;
	char	*temp;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	readed_bytes = 1;
	while (readed_bytes > 0)
	{
		readed_bytes = read(fd, temp, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[readed_bytes] = '\0';
		buffer = ft_helper(buffer, temp);
		if (!buffer)
			return (NULL);
		if (readed_bytes == 0 || ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*ft_liner(char **buffer)
{
	int		i;
	char	*line;

	if (!*buffer || !(*buffer)[0])
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	ft_manager(i, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	buffer[fd] = ft_reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_liner(&buffer[fd]);
	if (!buffer[fd] || ft_strlen(buffer[fd]) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
