#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    
    int fdR, fdW;
    ssize_t ret;
    char buf[32] = {0};
    // 打開a.c
    fdR = open( "a.c", O_RDWR, 0666 );
    if ( fdR == -1 ) {
        perror( "open file error!\n" );
    } // if
    printf( "fdR is : %d\n", fdR );

    // 打開b.c
    fdW = open( "b.c", O_CREAT | O_RDWR, 0666 );
    if ( fdW == -1 ) {
        perror( "open file error!\n" );
    } // if
    printf( "fdW is : %d\n", fdW );



    // 從a.c讀資料，直到ret為0，表示讀到文件尾了
    do {
        ret = read( fdR, buf, 32 );
        write( fdW, buf, ret );
    } while ( ret != 0 );


    
    
    close( fdR );
    close( fdW );
    return 0;
} // int