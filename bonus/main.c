#include "philo_bonus.h"

int main(int ac, char **av)
{
    t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	memset(arg, 0, sizeof(t_arg));
	// if (ac != 5 && ac != 6)
	// 	print_error("Incorrect number of arguments.\n");
	init_arg(arg, ac, av);
	core(arg);
	 return (0);
}