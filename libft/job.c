/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:02:37 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:45:44 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					init_jobqueue(t_jobqueue *jobqueue)
{
	jobqueue->len = 0;
	jobqueue->front = NULL;
	jobqueue->rear = NULL;
	jobqueue->has_jobs = (t_sem*)ft_memalloc(sizeof(t_sem));
	if (jobqueue->has_jobs == NULL)
		return (-1);
	pthread_mutex_init(&(jobqueue->rw_mutex), NULL);
	init_semaphore(jobqueue->has_jobs, 0);
	return (0);
}

void				clear_jobqueue(t_jobqueue *jobqueue)
{
	while (jobqueue->len)
		free(pull_jobqueue(jobqueue));
	jobqueue->front = NULL;
	jobqueue->rear = NULL;
	reset_semaphore(jobqueue->has_jobs);
	jobqueue->len = 0;
}

void				push_jobqueue(t_jobqueue *jobqueue, t_job *newjob)
{
	pthread_mutex_lock(&jobqueue->rw_mutex);
	newjob->prev = NULL;
	if (jobqueue->len == 0)
	{
		jobqueue->front = newjob;
		jobqueue->rear = newjob;
	}
	else
	{
		jobqueue->rear->prev = newjob;
		jobqueue->rear = newjob;
	}
	jobqueue->len = jobqueue->len + 1;
	post_semaphore(jobqueue->has_jobs);
	pthread_mutex_unlock(&jobqueue->rw_mutex);
}

t_job				*pull_jobqueue(t_jobqueue *jobqueue)
{
	t_job		*job;

	pthread_mutex_lock(&jobqueue->rw_mutex);
	job = jobqueue->front;
	if (jobqueue->len == 1)
	{
		jobqueue->front = NULL;
		jobqueue->rear = NULL;
		jobqueue->len = 0;
	}
	else if (jobqueue->len > 1)
	{
		jobqueue->front = job->prev;
		jobqueue->len = jobqueue->len - 1;
		post_semaphore(jobqueue->has_jobs);
	}
	pthread_mutex_unlock(&jobqueue->rw_mutex);
	return (job);
}

void				destroy_jobqueue(t_jobqueue *jobqueue)
{
	clear_jobqueue(jobqueue);
	free(jobqueue->has_jobs);
}
