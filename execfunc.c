#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int spawn(char* program, char** arg_list)
{
	pid_t child_pid;
	printf("spawn %d \n",getpid());
	child_pid = fork();
	if(child_pid!=0)
		 printf("parent %d \n",getpid());
	else{
		printf("child %d \n",getpid());
		execvp(program,arg_list);
		fprintf(stderr,"an error occurred in execvp\n");
		abort();
	}
}

int main()
{
	pid_t cpid=-1;
	char* arg_list[]={
		"ls",
		"-l",
		"/",
		NULL
		};
	printf("main() %d \n",getpid());
	spawn("ls",arg_list);
	cpid = wait(NULL);
	printf("done with main program %d\n",cpid);
	return 0;
}
