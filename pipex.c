/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:44:55 by lvodak            #+#    #+#             */
/*   Updated: 2024/10/06 20:41:04 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/signal.h> //?
#include <sys/wait.h> // wait
#include <stdio.h> //perror

void	cls_fd(int prev_fd, int *p_fd, int *fd_inout, t_inf info)
{
	(void)prev_fd;
	if (close(p_fd[0]) == -1)
		return (perror("close1"), exit(EXIT_FAILURE));
	if ((info.i != info.last))
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
	if (prev_fd != STDIN_FILENO)
		if (dup2(prev_fd, STDIN_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	if (info.i == info.last)
		if (dup2(fd_inout[1], STDOUT_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	if (info.i != info.last)
		if (dup2(p_fd[1], STDOUT_FILENO) == -1)
			return (perror("dup2"), exit(EXIT_FAILURE));
	cls_fd(prev_fd, p_fd, fd_inout, info);
}

void	execute_pipes(t_pipes pipes, int *fds, char **envp, int prev_fd)
{
	int	i;
	int	p_fd[2];

	i = -1;
	while (++i < pipes.p_nb)
	{
		if (i != pipes.p_nb - 1)
			pipe(p_fd);
		pipes.id[i] = fork();
		if (pipes.id[i] == -1)
			return (perror("fork"), exit(EXIT_FAILURE));
		if (pipes.id[i] == 0)
		{
			dup_fds(prev_fd, p_fd, fds, (t_inf){i, pipes.p_nb - 1});
			if (execve(pipes.pipe[i].path, pipes.pipe[i].cmd, envp) == -1)
				return (perror("command not executed"), exit(EXIT_FAILURE));
		}
		if (i != 0)
			close(prev_fd);
		if (i != pipes.p_nb - 1)
			close(p_fd[1]);
		prev_fd = p_fd[0];
	}
}

t_pipes	ft_no_here_doc(char **argv, int argc, char **envp, int (*fd_inout)[2])
{
	t_pipes	pipes;

	pipes = pipe_struct(argv, argc - 3, (char **)envp);
	if (!pipes.pipe)
		return ((t_pipes){0, 0, 0});
	(*fd_inout)[0] = open(argv[1], O_RDWR);
	(*fd_inout)[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (pipes);
}

int	main(int argc, char *argv[], char const *envp[])
{
	int		i;
	int		prev_fd;
	int		fd_inout[2];
	t_pipes	pipes;

	if (argc != 5)
		return (ft_putstr_fd("Error: invalid arguments number\n", 2), 0);
	pipes = ft_no_here_doc(argv, argc, (char **)envp, &fd_inout);
	prev_fd = fd_inout[0];
	if (fd_inout[0] == -1 || fd_inout[1] == -1)
		return (perror("open"), exit(EXIT_FAILURE), 0);
	execute_pipes(pipes, fd_inout, (char **)envp, prev_fd);
	i = -1;
	while (++i < pipes.p_nb)
		waitpid(pipes.id[i], &prev_fd, 0);
	free_pipes(&pipes);
}
