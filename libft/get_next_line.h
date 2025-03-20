/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:45 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 19:56:22 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*ft_reader(int fd, char	*buffer);
char	*ft_liner(char **buffer);
void	ft_manager(int i, char **buffer);
char	*ft_helper(char *buffer, char *temp);
char	*get_next_line(int fd);

#endif