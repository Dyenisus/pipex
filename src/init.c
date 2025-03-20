/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:38 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 20:52:10 by yesoytur         ###   ########.fr       */
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
	(*pipex) = (t_pipex *)malloc(sizeof(t_pipex));
	if (!(*pipex))
		pipex_error_exit();
	(*pipex)->cmd_count = 2;
	(*pipex)->cmds = extract_cmds(argc, argv, *pipex);
	(*pipex)->original_envp = env;
	(*pipex)->envp = extract_envps((*pipex)->cmds, env, *pipex);
	handle_files(argc, argv, *pipex);
	create_pipe(*pipex);
	parent(*pipex);
}
