#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *ft_print(void *arg)
{
	int *i;
	int sig;

	i = (int *) arg;
	sig = pthread_mutex_lock(&mutex);
	if (sig != 0)
	{
		printf("error\n");
		return (NULL);
	}
	while (*i < 10)
	{
		printf("thread %d\n", *i);
		(*i)++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	int i;
	int j;
	pthread_t th[10];

	i = 0;
	j = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 10)
	{
		pthread_create(&th[i], NULL, &ft_print, (void *) &j);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}