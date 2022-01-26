THREADS

-what is a thread?

A thread in computer science is short for a thread of execution. Threads are a way for a program to divide (termed "split") itself into two or more simultaneously (or pseudo-simultaneously) running tasks. 

threads and processes help us in multitasking but there is a diffrence between them

--> using multiple processes gives us two benefits 
			. concurrency
			. isolation : the memory is separeted and if one crushes the others just keep runing

but threads offer us only concurrency plus every threas h as its own call stack.

#include <phtreads.h>

int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *),  void *arg);

	thread: pointer to an unsigned integer value that returns the thread id of the thread created.
	
	attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.

	THREAD ATTRIBUTE STRUCTURE:

	typedef struct {
    int                 __flags;
    size_t              __stacksize;
    void                *__stackaddr;
    void                (*__exitfunc)(void *status);
    int                 __policy;
    struct sched_param  __param;
    unsigned            __guardsize;
		} pthread_attr_t;
   
	 start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.
  
	arg: pointer to void that contains the arguments to the function defined in the earlier argument

this last argumaent can help us to pass args to the function but we can also get results from the function using the second param of pthread_join

--pthread_join: used to wait for the termination of a thread.

int pthread_join(pthread_t th, void **thread_return);

-pthread_detach: used to detach a thread. A detached thread does not require a thread to join on terminating. The resources of the thread are automatically released after terminating if the thread is detached.

int pthread_detach(pthread_t thread);

MUTEX (mutual exclusion)
 
this mutex lock allow the thread to lock a code section (it says hey i have the floor) and exclude all the other threads
