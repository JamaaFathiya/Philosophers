/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:19:33 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/02 16:44:42 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_arg *arg;
    
    arg = malloc(sizeof(t_arg));
    memset(arg, 0, sizeof(t_arg));
    if(ac != 5 && ac != 6)
        print_error("Incorrect number of arguments.\n");
    else if (!init_arg(arg, ac, av))
        print_error("Allocation failed.\n");
    if(!init_thread(arg))
        print_error("Something went wrong during the threads creation.\n");
    init_mutex(arg);
    sleep(1);
    join_thread(arg);
    return (0);
}

