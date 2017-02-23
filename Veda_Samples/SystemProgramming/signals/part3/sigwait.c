#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>


void catcher( int sig ) {
    printf( "Signal catcher called for signal %d\n", sig );
}

void timestamp( char *str ) {
    time_t t;
    time(&t);
    printf( "The time %s is %s\n", str, ctime(&t) );
}

int main( int argc, char *argv[] ) {

    int result = 0;

    struct sigaction sigact;
    sigset_t waitset;
    siginfo_t info;

    sigemptyset( &sigact.sa_mask );
    sigact.sa_flags = 0;
    sigact.sa_handler = catcher;
    sigaction( SIGALRM, &sigact, NULL );

    sigemptyset( &waitset );
    sigaddset( &waitset, SIGALRM );

    sigprocmask( SIG_BLOCK, &waitset, NULL );

    alarm(5);

    timestamp( "before sigwaitinfo()" );

    result = sigwaitinfo( &waitset, &info );
    if( result <  0 )
	printf("sigwaitinfo failed : \n");
       

    printf( "sigwaitinfo() returned for signal %d\n",info.si_signo );

    timestamp( "after sigwaitinfo()" );

    return( result );
}
