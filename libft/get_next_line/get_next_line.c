/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:41 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:42 by yesoytur         ###   ########.fr       */
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !buffer[0])
		buffer = ft_calloc(1, 1);
	buffer = ft_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_liner(&buffer);
	if (!buffer || ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
