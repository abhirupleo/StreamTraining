#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE     128

void die(char *s)	//function called when an error occurs
{
  perror(s);
  exit(1);
}

typedef struct msgbuf	//this is the structure for the message buffer
{
    long    mtype;
    char    mtext[MAXSIZE];
} ;


main()
{
    int msqid;
    key_t key;
    struct msgbuf rcvbuffer;

    key = 1234;

    if ((msqid = msgget(key, 0666)) < 0)	//msqid returns -1 is error occurs else returns the message indentifier
      die("msgget()");


     //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)//trying to receive the messages based on the message id and the message is stored at the address of rcvbuffer
      die("msgrcv");

    printf("%s\n", rcvbuffer.mtext);
    exit(0);
}

