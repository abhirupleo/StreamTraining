#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//gcc thread.c -o thread -l pthread

void *print_message_function( void *ptr ) //printing the message passed in the function
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

int main()
{
     pthread_t thread1, thread2;	//creating two POSIX thread
     const char *message1 = "Thread 1";	//creating two messages for each thread
     const char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     if(iret1) //this is the error checking code
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
     if(iret2) //this is the error checking code
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

