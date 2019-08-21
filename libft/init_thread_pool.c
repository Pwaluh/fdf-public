/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_pool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:24:28 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:45:49 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_thread_pool	*pool_struct(void)
{
	t_thread_pool		*pool;

	pool = (t_thread_pool*)ft_memalloc(sizeof(t_thread_pool));
	if (pool == NULL)
	{
		ft_putendl("init_pool(): Could not allocate memory for thread pool");
		return (NULL);
	}
	pool->alive_threads = 0;
	pool->working_threads = 0;
	pool->threads_keepalive = 1;
	return (pool);
}

static void				threads(t_thread_pool *pool, int n)
{
	int					i;

	pool->threads = (t_thread**)ft_memalloc(n * sizeof(t_thread *));
	if (pool->threads == NULL)
	{
		ft_putendl("init_pool(): Could not allocate memory for threads");
		destroy_jobqueue(&pool->jobqueue);
		ft_memdel((void**)pool);
	}
	pthread_mutex_init(&(pool->th_count_lock), NULL);
	pthread_cond_init(&pool->th_all_idle, NULL);
	i = 0;
	while (i < n)
	{
		init_thread(pool, &pool->threads[i], i);
		i = i + 1;
	}
}

t_thread_pool			*init_pool(int n)
{
	t_thread_pool		*pool;

	n = n < 0 ? 0 : n;
	pool = pool_struct();
	if (init_jobqueue(&pool->jobqueue) == -1)
	{
		ft_putendl("init_pool(): Could not allocate memory for job queue");
		ft_memdel((void**)&pool);
		return (NULL);
	}
	threads(pool, n);
	while (pool->alive_threads != n)
		;
	return (pool);
}

int						add_work(t_thread_pool *pool, \
								void (*func)(void*), void *argument)
{
	t_job				*newjob;

	newjob = (t_job*)ft_memalloc(sizeof(t_job));
	if (newjob == NULL)
	{
		ft_putendl("add_work(): Could not allocate memory for new job");
		return (-1);
	}
	newjob->function = func;
	newjob->arg = argument;
	push_jobqueue(&pool->jobqueue, newjob);
	return (0);
}

void					destroy_pool(t_thread_pool *pool)
{
	volatile int		threads_total;
	int					i;

	if (pool)
	{
		threads_total = pool->alive_threads;
		pool->threads_keepalive = 0;
		timeout(pool);
		while (pool->alive_threads)
		{
			post_all_semaphore(pool->jobqueue.has_jobs);
			sleep(1);
		}
		destroy_jobqueue(&pool->jobqueue);
		i = 0;
		while (i < threads_total)
		{
			thread_destroy(pool->threads[i]);
			i = i + 1;
		}
		free(pool->threads);
		free(pool);
	}
}
