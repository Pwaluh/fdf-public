/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:26:03 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:46:22 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				init_semaphore(t_sem *semaphore, int value)
{
	if (value < 0 || value > 1)
	{
		ft_putendl("init_semaphoe(): Semaphore can take values 1 or 0");
		exit(1);
	}
	pthread_mutex_init(&(semaphore->mutex), NULL);
	pthread_cond_init(&(semaphore->cond), NULL);
	semaphore->v = value;
}

void				reset_semaphore(t_sem *semaphore)
{
	init_semaphore(semaphore, 0);
}

void				post_semaphore(t_sem *semaphore)
{
	pthread_mutex_lock(&semaphore->mutex);
	semaphore->v = 1;
	pthread_cond_signal(&semaphore->cond);
	pthread_mutex_unlock(&semaphore->mutex);
}

void				post_all_semaphore(t_sem *semaphore)
{
	pthread_mutex_lock(&semaphore->mutex);
	semaphore->v = 1;
	pthread_cond_broadcast(&semaphore->cond);
	pthread_mutex_unlock(&semaphore->mutex);
}

void				wait_semaphore(t_sem *semaphore)
{
	pthread_mutex_lock(&semaphore->mutex);
	while (semaphore->v != 1)
		pthread_cond_wait(&semaphore->cond, &semaphore->mutex);
	semaphore->v = 0;
	pthread_mutex_unlock(&semaphore->mutex);
}
