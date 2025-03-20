/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:28:24 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 21:00:29 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Usage: ./pipex infile cmd1 cmd2 outfile
// env: HOME=/usr ,PATH=/usr:/usr/bin:/usr/bin/etc

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		ft_printf("Error: Invalid Arguments\n");
		ft_printf("Usage: ./pipex infile ''cmd1'' ''cmd2'' outfile\n");
		exit(EXIT_FAILURE);
	}
	init_pipex(argc, argv, env, &pipex);
	free_pipex(pipex);
	exit(EXIT_SUCCESS);
}
