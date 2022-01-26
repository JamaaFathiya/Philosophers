#include "philo.h"

void    *philo5(void *arg)
{
    (void ) arg;
    int *ptr;

    ptr = malloc(sizeof(int));
    *ptr = 2;
        printf("philo5!\n");

        sleep(1);

    return (ptr);
}

int    main(void)
{
    pthread_t    newthread[5];
    int *res;

    printf("waiting for the thread...\n");
    pthread_create(&newthread[4], NULL, philo5, NULL);
    pthread_join(newthread[4], (void *)&res);
    printf("res: %d\n", *res);
    printf("Done\n");
    return (0);
}
