#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pipefds1[2];
	int pipefds2[2];
	int returnstatus1,returnstatus2;
	int pid;
	char pipe1writemessage[20] = "msg1 -> Hi";
	char pipe2writemessage[20] = "msg2 -> Hello";
	char readmessage1[20];
	char readmessage[20];

	//Create 1st Pipe
	returnstatus1 = pipe(pipefds1);
	returnstatus2 = pipe(pipefds2);
	if(returnstatus1 == -1 || returnstatus2 == -1){
		printf("Unable to create pipe 1\n");
		return 1;
	}
	//create a process

	pid = fork();

	if(pid!=0){//parent process
		close(pipefds2[0]);//writing into the pipe2
		write(pipefds2[1],pipe2writemessage,sizeof(pipe2writemessage));
		printf("In Parent: Writing to pipe 2 and the string is %s\n",pipe2writemessage);
		printf("---------\n");
		wait(NULL);
		close(pipefds1[1]);//reading from pipe2
		read(pipefds1[0],readmessage1,sizeof(readmessage1));
		printf("In Parent: Reading from pipe 1 - Message is %s\n",readmessage1);
		printf("---------\n");
	}else{//child process
		close(pipefds2[1]);//reading from pipe2
		read(pipefds2[0],readmessage1,sizeof(readmessage1));
		printf("In Child: Reading from pipe 2 - Message is %s\n",readmessage1);
		printf("---------\n");
		close(pipefds1[0]);//writing into pipe1
		write(pipefds1[1],pipe1writemessage,sizeof(pipe1writemessage));
		printf("In Child: Writing to pipe 1 and the string is %s\n",pipe1writemessage);
		printf("---------\n");
	}
	return 0;
}
