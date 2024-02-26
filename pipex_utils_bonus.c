/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:04:49 by lvodak            #+#    #+#             */
/*   Updated: 2024/02/13 20:57:19 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

t_pipes	pipe_struct(char **argv, int child_nbr, char **envp, int here_doc)
{
	t_pipes		pipes;
	t_pipe_list	*child;
	char		**cmd;
	int			i;

	i = 0;
	pipes = (t_pipes){child_nbr, 0, 0, 0};
	if (here_doc)
		pipes = (t_pipes){child_nbr, argv[1], 0, 0};
	child = malloc(sizeof(t_pipe_list) * child_nbr);
	pipes.id = malloc(sizeof(pid_t) * child_nbr);
	pipes.pipe = child;
	if (!child || !pipes.id)
		return ((t_pipes){0, 0, 0, child});
	while (i < child_nbr)
	{
		cmd = ft_split(argv[i + 2], ' ');
		child[i] = (t_pipe_list){cmd[0], cmd};
		if (access(cmd[0], F_OK))
			child[i] = (t_pipe_list){access_path(cmd[0], envp), cmd};
		if (!child[i].cmd)
			return (free(pipes.id), free(child), (t_pipes){0, 0, 0, 0});
		i++;
	}
	return (pipes);
}

void	cls_fd(int prev_fd, int *p_fd, int *fd_inout, t_inf info)
{
	if (close(p_fd[0]) == -1)
		return (perror("close1"), exit(EXIT_FAILURE));
	if ((info.i != info.last || prev_fd == -1))
		if (close(p_fd[1]) == -1)
			return (perror("close2"), exit(EXIT_FAILURE));
	if ((prev_fd != -1 || (prev_fd == -1 && info.i != info.last)))
		if (close(fd_inout[1]) == -1)
			return (perror("close3"), exit(EXIT_FAILURE));
	if (info.i != info.last)
		if (close(fd_inout[0]) == -1)
			return (perror("close4"), exit(EXIT_FAILURE));
}

void	dup_fds(int prev_fd, int p_fd[2], int *fd_inout, t_inf info)
{
	if (prev_fd != -1 && prev_fd != STDIN_FILENO)
		if (dup2(prev_fd, STDIN_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	if (info.i == info.last)
		if (dup2(fd_inout[1], STDOUT_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	if (info.i != info.last)
		if (dup2(p_fd[1], STDOUT_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	if (prev_fd == -1)
		ex_heredoc(p_fd, info.lim);
	cls_fd(prev_fd, p_fd, fd_inout, info);
}
