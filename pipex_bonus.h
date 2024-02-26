/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:45:41 by lvodak            #+#    #+#             */
/*   Updated: 2024/02/09 23:59:09 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line_bonus.h"
# include "libft/headers/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pipe_list
{
	char	*path;
	char	**cmd;
}	t_pipe_list;

typedef struct s_pipes
{
	int						p_nb;
	void					*lim;
	pid_t					*id;
	struct s_pipe_list		*pipe;
}	t_pipes;

typedef struct s_inf
{
	int		i;
	int		last;
	char	*lim;
}	t_inf;

char	**get_path(char **envp);
char	*access_path(char *cmd, char **envp);
t_pipes	pipe_struct(char **argv, int child_nbr, char **envp, int here_doc);
void	explain_status(int child_status);
void	dup_fds(int prev_fd, int p_fd[2], int *fd_inout, t_inf info);
void	cls_fd(int prev_fd, int *p_fd, int *fd_inout, t_inf info);
void	ex_heredoc(int p_fd[2], char *limiter);
void	free_pipes(t_pipes *pipes);

#endif