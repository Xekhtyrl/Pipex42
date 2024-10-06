/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:04:49 by lvodak            #+#    #+#             */
/*   Updated: 2024/04/01 23:59:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	*temp;
	char	**path;

	while (*envp)
	{
		temp = ft_strnstr(*envp, "PATH=", ft_strlen(*envp));
		if (temp)
		{
			path = ft_split(temp + 5, ':');
			return (path);
		}
		envp++;
	}
	return (0);
}

char	*access_path(char *old_cmd, char **envp)
{
	char	*path;
	char	*cmd;
	char	**pos_path;
	int		i;

	pos_path = get_path(envp);
	if (!pos_path)
		return (0);
	cmd = ft_strjoin("/", old_cmd);
	i = 0;
	while (pos_path[i])
	{
		path = ft_strjoin(pos_path[i], cmd);
		if (access(path, F_OK) == 0)
		{
			while (pos_path[i])
				free(pos_path[i++]);
			return (free(pos_path), free(cmd), path);
		}
		if (path)
			free(path);
		free(pos_path[i]);
		i++;
	}
	return (free(cmd), free(pos_path), perror("path"), NULL);
}

t_pipes	pipe_struct(char **argv, int child_nbr, char **envp)
{
	t_pipes		pipes;
	t_pipe_list	*child;
	char		**cmd;
	int			i;

	i = 0;
	pipes = (t_pipes){child_nbr, 0, 0};
	child = malloc(sizeof(t_pipe_list) * child_nbr);
	pipes.id = malloc(sizeof(pid_t) * child_nbr);
	pipes.pipe = child;
	if (!child || !pipes.id)
		return ((t_pipes){0, 0, child});
	while (i < child_nbr)
	{
		cmd = ft_split(argv[i + 2], ' ');
		child[i] = (t_pipe_list){cmd[0], cmd};
		if (!access(cmd[0], W_OK) || access(cmd[0], F_OK))
			child[i] = (t_pipe_list){access_path(cmd[0], envp), cmd};
		if (!child[i].cmd)
			return (free(pipes.id), free(child), (t_pipes){0, 0, 0});
		i++;
	}
	return (pipes);
}
