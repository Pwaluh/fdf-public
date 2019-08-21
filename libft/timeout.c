/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:57:41 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:46:44 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				timeout(t_thread_pool *pool)
{
		double			timeout;
		double			tpassed;
		time_t			start;
		time_t			end;

		timeout = 1.0;
		tpassed = 0.0;
		time(&start);
		while(tpassed < timeout && pool->alive_threads)
		{
			post_all_semaphore(pool->jobqueue.has_jobs);
			time(&end);
			tpassed = difftime(end, start);
		}
}
