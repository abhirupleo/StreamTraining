#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void sigintHandler(int sig)
{
	signal(SIGINT,sigintHandler);
	printf("\n Cannot be terminated using Ctrl+C\n");
	fflush(stdout);
}

int main()
{
	signal(SIGINT,sigintHandler);
	while(1)
	{
		int cmd,nititems;
		printf("\n Enter 0 to end \n anything else to continue\n");
		nititems = scanf("%d",&cmd);
		if(nititems == EOF)
		{
			cmd=0; 	
		}
		if(cmd == 0)
			exit(0);
	}
	return 0;
}
