/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:23:20 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 21:04:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	access_error_exit(char *message, t_pipex *pipex)
{
	free_pipex(pipex);
	ft_printf("Error: Access Denied for %s\n", message);
	exit(EXIT_FAILURE);
}

static void	file_error_exit(char *message, t_pipex *pipex)
{
	free_pipex(pipex);
	ft_printf("Error: %s could not be opened\n", message);
	exit(EXIT_FAILURE);
}

void	handle_files(int argc, char **argv, t_pipex *pipex)
{
	if (access(argv[1], F_OK) < 0 || access(argv[1], R_OK) < 0)
		access_error_exit(argv[1], pipex);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		file_error_exit(argv[1], pipex);
	if (access(argv[argc - 1], F_OK) == 0 && access(argv[argc - 1], W_OK) < 0)
		access_error_exit(argv[argc - 1], pipex);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile < 0)
		file_error_exit(argv[argc - 1], pipex);
}
