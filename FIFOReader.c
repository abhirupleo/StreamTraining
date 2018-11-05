//this program reads from a FIFO file till it encounters "end" string
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

#define FIFO_FILE "FIFO"

int main(){
	int fd;
	char readbuf[80];
	char end[10];
	int to_end;
	int read_bytes;
	//Create the FIFO if it doe not exist
	mknod(FIFO_FILE,S_IFIFO|0640, 0);
	strcpy(end,"end");//copy "end" to the variable end
	while(1){//this will read till it encounters an "end" string
		fd = open(FIFO_FILE, O_RDONLY);//open the FIFO file in readonly mode
		read_bytes = read(fd,readbuf,sizeof(readbuf));//read returns the number of characters it read
		readbuf[read_bytes] = '\0';//so adding the null byte at the end of the readbuf array
		printf("Received string: \"%s\" and length is %d\n",readbuf,(int)strlen(readbuf));
		to_end = strcmp(readbuf,end);//compare the string with "end"
		if(to_end==0){//if the return from strcmp is 0 then close it and get out of the while loop
			close(fd);
			break;
		}
	}
	return 0;
}
