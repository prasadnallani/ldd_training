/*
 * program to use setitimer()
 */

#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>

main(int argc, char *argv[])
{
int status;
long isec, usec;
struct itimerval nval,oval;
extern int errno;
float	ftime;
void timer(int);

signal(SIGALRM,timer);

printf("\n\n**************************************\n");
printf("***  Program to demonstrate Timer  ***\n");
printf("**************************************\n\n\n");

if(argc < 2){
	printf("\n\nUsage:	timer sec.usec\n\n\n");
	exit(0);
}
 
sscanf(argv[1],"%f", &ftime);
printf("%f\n", ftime);

isec = (long) ftime;
usec = (long) ((ftime - isec) * 1000000);

nval.it_interval.tv_sec = isec;
nval.it_interval.tv_usec = usec;	// 100 Milliseconds

nval.it_value.tv_sec = isec;
nval.it_value.tv_usec = usec;		// 100 Milliseconds

status = setitimer(ITIMER_REAL, &nval, &oval);

if(status == -1){
	perror("Timer Creation ERROR ***");
	strerror(errno);
	}

while(1) {
	signal(SIGALRM,timer);		// Set Signal Handler for SIGALRM signal
	pause();
	}
}

void timer(int dmy)
{
	struct timeval gtime;
	time_t t;
	char cus[15],its[50]; 
	char *ct;

	gettimeofday(&gtime,NULL);		// Get Time
	t=gtime.tv_sec;				// Seconds
	ct =(char *)  ctime(&t);		// Convert Seconds to ASCII
	sprintf(cus,".%06d",gtime.tv_usec);	// Convert Microseconds to ASCII
	strncpy(its,ct,10);			
	strncpy(&its[10],ct+19,5);
	strncpy(&its[15],ct+10,9);
	strcpy(&its[24],cus);
	printf("SIGALRM Received %s\n",its);
}

