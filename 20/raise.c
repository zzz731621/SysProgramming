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
    
    printf( "raise before!\n" );

    // 這個函數代表向自己發信號，等於kill( getpid(), 9 )
    raise( 9 );

    // 因為9號信號代表終止process，所以不會印出這行
    printf( "raise after!\n" );
    return 0;
} // int