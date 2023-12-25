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

    // 回傳一個DIR類型的指標
    // 若開啟失敗會為NULL
    dp = opendir( argv[1] );
    if ( dp !=  NULL )
        printf( "opendir sucess!\n" );

    
    closedir( dp );

    return 0;
} // int