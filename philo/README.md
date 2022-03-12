THREADS

-what is a thread?

A thread in computer science is short for a thread of execution. Threads are a way for a program to divide (termed "split") itself into two or more simultaneously (or pseudo-simultaneously) running tasks. 

threads and processes help us in multitasking but there is a diffrence between them

--> using multiple processes gives us two benefits 
			. concurrency
			. isolation : the memory is separeted and if one crushes the others just keep runing

-But threads offer us only concurrency plus every threas h as its own call stack.

#include <phtreads.h>

=> int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *),  void *arg);

-thread: pointer to an unsigned integer value that returns the thread id of the thread created.
	
-attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.

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
   
-start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.
  
-arg: pointer to void that contains the arguments to the function defined in the earlier argument

The last argumaent can help us to pass args to the function but we can also get results from the function using the second param of pthread_join

=>pthread_join: used to wait for the termination of a thread.

int pthread_join(pthread_t th, void **thread_return);

-pthread_detach: used to detach a thread. A detached thread does not require a thread to join on terminating (it s no longer joinable). The resources of the thread are automatically released after terminating if the thread is detached.
In other words, if a thread is detached, it does not need to join back into its parent to release its resources (and neither can you join it). This is useful when you want to have a thread that just does its thing without joining back with its creator.

side note: - the thread by default is created joinable but we can make it detached since creation using the thread attributes.
					 - as we said the detched thread can no longer be joinable so the program might exit before its termination to solve this 						we can use pthread_exit(); 

int pthread_detach(pthread_t thread);

---> MUTEX (mutual exclusion)
 
The mutex lock allow the thread to lock a code section (it says hey i have the floor) and exclude all the other threads

->MUTEX INIT:

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

after declaring a pthread_mutex_t mutex , we initialise it using the function above

->MUTEX LOCK:

then we can lock a code section using :int pthread_mutex_lock (pthread_mutex_t * mutex); 

NOTE: if the mutex is locked by a thread only that thread can unlock it.

->MUTEX UNLOCK:

after finishing we unlock the mutex using :int pthread_mutex_unlock (pthread_mutex_t * mutex);

->MUTEX DESTROY:
	
int pthread_mutex_destroy(pthread_mutex_t *mutex);

this function set the mutex to an invalid value so it can be reintialised but the destroyed mutex can no longer be used.

It is safe to destroy an initialised mutex that is unlocked. Attempting to destroy a locked mutex results in undefined behaviour.

Every mutex must eventually be destroyed with pthread_mutex_destroy(). The machine eventually detects the error if a mutex is not destroyed, but the storage is deallocated or corrupted. 
