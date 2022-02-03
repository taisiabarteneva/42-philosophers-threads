# include "philo.h"

void free_all(t_data *data)
{
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->forks)
			free(data->forks);
		free(data);
	}
}

void exit_program(t_data *data)
{
	size_t i;
	size_t num;
	
	i = 0;
	num = data->constants.num_philo;
	while (i < num)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		pthread_mutex_destroy(&data->philos[i].eating_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->stdout_mutex);
	free_all(data);
}
