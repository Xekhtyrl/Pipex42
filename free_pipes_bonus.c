/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:58:37 by lvodak            #+#    #+#             */
/*   Updated: 2024/02/12 20:48:19 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipes(t_pipes *pipes)
{
	int	i;
	int	j;

	i = pipes->p_nb;
	while (--i >= 0)
	{
		j = 0;
		if (access(pipes->pipe[i].cmd[0], F_OK))
			free(pipes->pipe[i].path);
		while (pipes->pipe[i].cmd[j])
			free(pipes->pipe[i].cmd[j++]);
		free(pipes->pipe[i].cmd);
	}
	free(pipes->id);
	free(pipes->pipe);
}
