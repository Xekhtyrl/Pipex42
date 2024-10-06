/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:57:33 by lvodak            #+#    #+#             */
/*   Updated: 2024/03/26 20:41:40 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipes(t_pipes *pipes)
{
	int	i;
	int	j;

	i = pipes->p_nb;
	while (--i >= 0)
	{
		j = 0;
		if (access(pipes->pipe[i].cmd[0], F_OK)
			|| !access(pipes->pipe[i].cmd[0], W_OK))
			free(pipes->pipe[i].path);
		while (pipes->pipe[i].cmd[j])
			free(pipes->pipe[i].cmd[j++]);
		free(pipes->pipe[i].cmd);
	}
	free(pipes->id);
	free(pipes->pipe);
}
