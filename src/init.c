/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:38 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/23 10:38:48 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	pipex_error_exit(void)
{
	ft_printf("Error: Pipex could not be initialized\n");
	exit(EXIT_FAILURE);
}

void	init_pipex(int argc, char **argv, char **env, t_pipex **pipex)
{
	(*pipex) = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!(*pipex))
		pipex_error_exit();
	if (!argv[2][0] || !argv[3][0])
	{
		free_pipex((*pipex));
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(EXIT_FAILURE);
	}
	(*pipex)->cmd_count = 2;
	(*pipex)->cmds = extract_cmds(argc, argv, *pipex);
	(*pipex)->original_envp = env;
	(*pipex)->envp = extract_envps((*pipex)->cmds, env, *pipex);
	handle_files(argc, argv, *pipex);
	create_pipe(*pipex);
	parent(*pipex);
}
