#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main( int argc, char *argv[] ) {
    int ret;
    DIR *dp;

    if ( argc != 2 ) {
        printf( "Usage:%s <name file> \n", argv[0] );
        return -1;
    } // if


    dp = opendir( argv[1] );
    if ( dp !=  NULL )
        printf( "opendir sucess!\n" );

    
    closedir( dp );

    return 0;
} // int