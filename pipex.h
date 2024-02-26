/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:45:41 by lvodak            #+#    #+#             */
/*   Updated: 2024/02/12 22:50:26 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	pid_t					*id;
	struct s_pipe_list		*pipe;
}	t_pipes;

typedef struct s_inf
{
	int		i;
	int		last;
}	t_inf;

char	**get_path(char **envp);
char	*access_path(char *cmd, char **envp);
t_pipes	pipe_struct(char **argv, int child_nbr, char **envp);
void	explain_status(int child_status);
void	free_pipes(t_pipes *pipes);

#endif