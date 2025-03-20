/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:28:47 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 20:08:09 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	***cmds;
	char	**envp;
	char	**original_envp;
	int		infile;
	int		outfile;
	int		cmd_count;
	int		pipe_fd[2];
}	t_pipex;

void	bi_free(char **bi);
void	free_pipex(t_pipex *pipex);
void	tri_free(char ***tri);
void	free_args(char **args, int i);
char	**split_args(const char *s);
char	***extract_cmds(int argc, char **argv, t_pipex *pipex);
char	**extract_envps(char ***cmds, char **env, t_pipex *pipex);
void	handle_files(int argc, char **argv, t_pipex *pipex);
void	create_pipe(t_pipex *pipex);
void	child(t_pipex *pipex);
void	child_two(t_pipex *pipex);
void	parent(t_pipex *pipex);
void	init_pipex(int argc, char **argv, char **env, t_pipex **pipex);

#endif