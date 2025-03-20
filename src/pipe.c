/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:06:20 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 21:08:40 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	pipe_error_exit(t_pipex *pipex)
{
	free_pipex(pipex);
	ft_printf("Error: pipe could not be initialized\n");
	exit(EXIT_FAILURE);
}

void	create_pipe(t_pipex *pipex)
{
	int	i;

	i = pipe(pipex->pipe_fd);
	if (i < 0)
		pipe_error_exit(pipex);
}
