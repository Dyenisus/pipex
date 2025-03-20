/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:47:36 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 20:52:27 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Usage: ./pipex "infile" "ls -l" "grep something" "outfile"

static void	cmd_error_exit(void)
{
	ft_printf("Error: Cmds could not be extracted\n");
	exit(EXIT_FAILURE);
}

char	***extract_cmds(int argc, char **argv, t_pipex *pipex)
{
	int		i;
	int		j;
	char	***cmds;

	cmds = (char ***)malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!cmds)
		cmd_error_exit();
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		cmds[j] = split_args(argv[i++]);
		if (!cmds[j])
		{
			tri_free(cmds);
			cmd_error_exit();
		}
		j++;
	}
	cmds[j] = NULL;
	return (cmds);
}
