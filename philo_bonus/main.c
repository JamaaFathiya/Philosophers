#include "philo_bonus.h"

int main(int ac, char **av)
{
    t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	memset(arg, 0, sizeof(t_arg));
	if (ac != 5 && ac != 6)
		print_error("Incorrect number of arguments.\n");
	if (!init_arg(arg, ac, av) || !init_sem(arg))
	{
		print_error("Allocation or semaphore creation failed.\n");
		exit (1);
	}
	core(arg);
	free_all(arg);
	 return (0);
}