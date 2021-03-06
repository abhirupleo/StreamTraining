#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int counter =0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZED; //this is a mutually exclusive lock being initialised
int increaseCounter()
{
	pthread_mutex_lock(&mutex1);	//locking
	counter++;
	pthread_mutex_unlock(&mutex1);	//unlocking
	
	return counter;
}

void *print_counter_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     while(1)
     {
     	printf("%s counterVal = %d\n", message,increaseCounter());//increase the counter and display 
	sleep(2); //sleep for 2 seconds
     }
}

int main()
{
     pthread_t thread1, thread2;
     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_counter_function, (void*) message1);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, print_counter_function, (void*) message2);
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}

