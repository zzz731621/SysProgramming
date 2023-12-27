#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main( int argc, char *argv[] ) {
    
    // 三秒後發送2的信號，若不捕捉則會終止該process
    alarm( 3 );

    // 每過一秒印出一次
    // 但因為有alarm，所以三秒process就終止了
    while ( 1 ) {
        sleep( 1 );
        printf( "Hello!\n" );
    } // while
    return 0;
} // int