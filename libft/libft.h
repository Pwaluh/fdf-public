/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:29:12 by judrion           #+#    #+#             */
/*   Updated: 2019/08/21 15:44:11 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# define MAX_ULLONG		9223372036854775807
# define MIN_INT		-2147483648

typedef struct				s_sem
{
	pthread_mutex_t			mutex;
	pthread_cond_t			cond;
	int						v;
}							t_sem;

typedef struct				s_job
{
	struct s_job			*prev;
	void					(*function)(void *arg);
	void					*arg;
}							t_job;

typedef struct				s_jobqueue
{
	pthread_mutex_t			rw_mutex;
	t_job					*front;
	t_job					*rear;
	t_sem					*has_jobs;
	int						len;
}							t_jobqueue;

typedef struct				s_thread
{
	int						id;
	pthread_t				pthread;
	struct s_thread_pool	*pool;
}							t_thread;

typedef struct				s_thread_pool
{
	struct s_thread			**threads;
	volatile int			alive_threads;
	volatile int			working_threads;
	pthread_mutex_t			th_count_lock;
	pthread_cond_t			th_all_idle;
	struct s_jobqueue		jobqueue;
	int						threads_keepalive;
}							t_thread_pool;


typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

void						ft_bzero(void *s, size_t n);
void						*ft_memset(void *b, int c, size_t len);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						*ft_memccpy(void *dst, const void *src, int c, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t len);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strncpy(char *dst, const char *src, size_t len);
char						*ft_strchr(const char *s, int c);
char						*ft_strcat(char	*s1, char *s2);
char						*ft_strncat(char *s1, char *s2, size_t n);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *haystack, const char *needle);
char						*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2, size_t n);
int							ft_iswhitespace(int c);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_islower(int c);
int							ft_isupper(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(unsigned int, char*));
char						*ft_strmap(const char *s, char (*f)(char));
char						*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int							ft_strequ(const char *s1, const char *s2);
int							ft_strnequ(const char *s1, const char *s2, size_t n);
char						*ft_strsub(const char *s, unsigned int start, size_t len);
char						*ft_strjoin(const char *s1, const char *s2);
char						*ft_strtrim(const char *s);
char						*ft_strrev(char *s);
char						*ft_itoa_base(int n, char base);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putnbr(int n);
void						ft_putstr(const char *s);
void						ft_putendl(const char *s);
void						ft_putchar_fd(char c, int fd);
void						ft_putnbr_fd(int n, int fd);
void						ft_putstr_fd(const char *s, int fd);
void						ft_putendl_fd(const char *s, int fd);
char						**ft_strsplit(const char *s, char c);
void						ft_print_byte(void *c, size_t nb_octet);
char						*ft_utf8_encode(unsigned int c);
unsigned int				ft_utf8_decode(char *utf8);
t_list						*ft_lstnew(const void *content, size_t content_size);
void						ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void						ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_thread_pool				*init_pool(int n);
int							add_work(t_thread_pool *pool, \
									void (*func)(void*), void *argument);
void						destroy_pool(t_thread_pool *pool);
void						init_semaphore(t_sem *semaphore, int value);
void						reset_semaphore(t_sem *semaphore);
void						post_semaphore(t_sem *semaphore);
void						post_all_semaphore(t_sem *semaphore);
void						wait_semaphore(t_sem *semaphore);
int							init_thread(t_thread_pool *pool, \
										t_thread **threads, int id);
void						*thread_do(t_thread *thread);
void						thread_hold(int sig_id);
void						thread_destroy(t_thread *thread);
void						timeout(t_thread_pool *pool);
int							init_jobqueue(t_jobqueue *jobqueue);
void						push_jobqueue(t_jobqueue *jobqueue, t_job *newjob);
t_job						*pull_jobqueue(t_jobqueue *jobqueue);
void						clear_jobqueue(t_jobqueue *jobqueue);
void						destroy_jobqueue(t_jobqueue *jobqueue);

#endif
