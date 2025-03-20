/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:44:32 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/20 21:10:59 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	count_args(const char *s, int count)
{
	int	in_quote;

	in_quote = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			count++;
			if (*s == '"' || *s == '\'' )
			{
				in_quote = *s;
				s++;
				while (*s && *s != in_quote)
					s++;
				if (*s == in_quote)
					s++;
			}
			while (*s && *s != ' ')
				s++;
		}
	}
	return (count);
}

static void	read_quoted_arg(const char **s, char *buffer, int *i, int in_quote)
{
	while (**s && **s != in_quote)
	{
		buffer[(*i)++] = **s;
		(*s)++;
	}
	if (**s == in_quote)
		(*s)++;
}

static void	read_unquoted_arg(const char **s, char *buffer, int *i)
{
	while (**s && **s != ' ')
	{
		buffer[(*i)++] = **s;
		(*s)++;
	}
}

static char	*extract_arg(const char **s)
{
	char	buffer[1024];
	int		i;
	int		in_quote;

	while (**s == ' ')
		(*s)++;
	in_quote = 0;
	if (**s == '"' || **s == '\'')
	{
		in_quote = **s;
		(*s)++;
	}
	i = 0;
	if (in_quote)
		read_quoted_arg(s, buffer, &i, in_quote);
	else
		read_unquoted_arg(s, buffer, &i);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

char	**split_args(const char *s)
{
	char	**args;
	int		i;

	args = malloc((count_args(s, 0) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			args[i] = extract_arg(&s);
			if (!args[i])
			{
				free_args(args, i);
				return (NULL);
			}
			i++;
		}
	}
	args[i] = NULL;
	return (args);
}
