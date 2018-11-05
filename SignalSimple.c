#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int a = 7;
volatile int b = 0;

void handle_sigfpe(int sig)
{
	printf("Caught symbol %d\n",sig);
	exit(0);
}

int main()
{
	signal(SIGKILL,handle_sigfpe);
	printf("This pid = %d\n",getpid());
	printf("The parent process id is %d\n",getppid());
	getc(stdin);
	putc(99/0,stdout);
	printf("Hello World");
	return 0;
}
