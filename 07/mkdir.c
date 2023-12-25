#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    int ret;

    if ( argc != 2 ) {
        printf( "Usage%s <name file> \n", argv[0] );
        return -1;
    } // if

    // 第一個參數是路徑，要包括要創建的資料夾名稱
    // 第二個是權限
    ret = mkdir( argv[1], 0666 );
    if ( ret < 0 ) {
        printf( "mkdir error\n" );
    } // if

    printf( "mkdir sucess!\n" );    
    return 0;
} // int