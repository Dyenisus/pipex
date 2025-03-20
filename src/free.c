/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:04:09 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 21:04:49 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	bi_free(char **bi)
{
	int	i;

	if (!bi)
		return ;
	i = 0;
	while (bi[i])
		free(bi[i++]);
	free(bi);
}

void	tri_free(char ***tri)
{
	int	i;

	if (!tri)
		return ;
	i = 0;
	while (tri[i])
	{
		bi_free(tri[i]);
		i++;
	}
	free(tri);
}

void	free_args(char **args, int i)
{
	while (i-- > 0)
		free(args[i]);
	free(args);
}

void	free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmds)
		tri_free(pipex->cmds);
	if (pipex->envp)
		bi_free(pipex->envp);
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	free(pipex);
}
