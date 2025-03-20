/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:13:08 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 20:53:43 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	process_error_exit(char *process, char *message, t_pipex *pipex)
{
	ft_printf("Error: %s process can not be %s\n", process, message);
	free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	child(t_pipex *pipex)
{
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
		process_error_exit("Child", "dup infile", pipex);
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) < 0)
		process_error_exit("Child", "dup pipe_fd[1]", pipex);
	close(pipex->infile);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (execve(pipex->envp[0], pipex->cmds[0], pipex->original_envp) == -1)
		process_error_exit("Child", "execve", pipex);
}

void	child_two(t_pipex *pipex)
{
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) < 0)
		process_error_exit("Child_two", "dup pipe_fd[0]", pipex);
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
		process_error_exit("Child_two", "dup outfile", pipex);
	close(pipex->outfile);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (execve(pipex->envp[1], pipex->cmds[1], pipex->original_envp) == -1)
		process_error_exit("Child_two", "execve", pipex);
}

void	parent(t_pipex *pipex)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		process_error_exit("Child", "fork", pipex);
	if (pid1 == 0)
		child(pipex);
	pid2 = fork();
	if (pid2 < 0)
		process_error_exit("Child_two", "fork", pipex);
	if (pid2 == 0)
		child_two(pipex);
	close((pipex)->pipe_fd[0]);
    close((pipex)->pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
