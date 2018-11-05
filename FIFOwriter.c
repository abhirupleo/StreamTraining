//this program writes into the FIFO file till it encounters "end" string
//TODO: read up about mknod and FIFO file types
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "FIFO"

int main(){
	int fd;
	char writebuf[80];
	char end[10];
	int to_end;
	int read_bytes;
	//No need to create the FIFO node as it is being created by the other process(application)
	//creating the end variable
	strcpy(end,"end");
	while(1){
		fd = open(FIFO_FILE, O_WRONLY);//open the FIFO file in writeonly mode
		printf("Enter the string you want to send till end string is encountered\n");
		scanf("%s",writebuf);
		write(fd,writebuf,strlen(writebuf));
		//printf("Received string: \"%s\" and length is %d\n",writebuf,(int)strlen(writebuf));
		to_end = strcmp(writebuf,end);//compare the string with "end"
		if(to_end==0){//if the return from strcmp is 0 then close it and get out of the while loop
			close(fd);
			break;
		}
	}
	return 0;
}
