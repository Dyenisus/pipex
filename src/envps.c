/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:44:27 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 20:52:22 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	env_error_exit(char *message)
{
	ft_printf("Error: %s can not be extracted\n", message);
	exit(EXIT_FAILURE);
}

static char	*get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*path_searcher(char *cmds, char **paths)
{
	int		i;
	char	*full_path;
	char	*temp;

	if (!cmds || !*cmds)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmds);
		free(temp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL) ;
}

static void	extract_helper(char **cmd_paths, char **paths, char ***cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
	{
		cmd_paths[i] = path_searcher(cmds[i][0], paths);
		if (!cmd_paths[i])
		{
			bi_free(paths);
			bi_free(cmd_paths);
			tri_free(cmds);
			env_error_exit("CMD_PATHS");
		}
		i++;
	}
	cmd_paths[i] = NULL;
}

char	**extract_envps(char ***cmds, char **env, t_pipex *pipex)
{
	char	*envs;
	char	**paths;
	char	**cmd_paths;

	envs = get_env_path(env);
	if (!envs)
		env_error_exit("ENVS");
	paths = ft_split(envs, ':');
	if (!paths)
		env_error_exit("PATHS");
	cmd_paths = (char **)malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (!cmd_paths)
	{
		bi_free(paths);
		env_error_exit("CMD_PATHS");
	}
	extract_helper(cmd_paths, paths, cmds);
	bi_free(paths);
	return (cmd_paths);
}
