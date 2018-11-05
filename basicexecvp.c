#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	/* The argument list to pass to the "ls" command. */
	char* arg_list[]={
		"file3", /*argv[0], the name of the program. */
		"-l",
		"/",
		NULL /* The argument list must end with a NULL. */
		};
	printf("%d \n",getpid());
	//exec the ls command
	int return_value = execvp("file3",arg_list);
	printf("%d",return_value);

	getc(stdin);
	printf("done with the main program\n");
	return 0;
}
