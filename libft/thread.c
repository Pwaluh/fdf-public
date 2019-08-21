/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:48:36 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:46:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						init_thread(t_thread_pool *pool, \
									t_thread **threads, int id)
{
	*threads = (t_thread*)ft_memalloc(sizeof(t_thread));
	if (threads == NULL)
	{
		ft_putendl("init_thread(): Could not allocate memory for thread");
		return (-1);
	}
	(*threads)->pool = pool;
	(*threads)->id = id;
	pthread_create(&(*threads)->pthread, NULL, (void*)thread_do, (*threads));
	pthread_detach((*threads)->pthread);
	return (0);
}

static void				do_job(t_job *job, t_thread_pool *pool)
{
	void				(*func_buff)(void*);
	void				*arg_buff;

	job = pull_jobqueue(&pool->jobqueue);
	if (job)
	{
		func_buff = job->function;
		arg_buff = job->arg;
		func_buff(arg_buff);
		free(job);
	}
}

void					*thread_do(t_thread *thread)
{
	t_thread_pool		*pool;
	t_job				*job;

	pool = thread->pool;
	pthread_mutex_lock(&pool->th_count_lock);
	pool->alive_threads = pool->alive_threads + 1;
	pthread_mutex_unlock(&pool->th_count_lock);
	while (thread->pool->threads_keepalive)
	{
		pthread_mutex_lock(&pool->th_count_lock);
		pool->working_threads = pool->working_threads + 1;
		pthread_mutex_unlock(&pool->th_count_lock);
		do_job(job, pool);
		pthread_mutex_lock(&pool->th_count_lock);
		pool->working_threads = pool->working_threads - 1;
		if (!pool->working_threads)
			pthread_cond_signal(&pool->th_all_idle);
		pthread_mutex_unlock(&pool->th_count_lock);
	}
	pthread_mutex_lock(&pool->th_count_lock);
	pool->alive_threads = pool->alive_threads - 1;
	pthread_mutex_unlock(&pool->th_count_lock);
	return (NULL);
}

void					thread_destroy(t_thread *thread)
{
	free(thread);
}
