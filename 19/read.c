#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>

int main( int argc, char *argv[] ) {
    int fd;
    int ret;
    char buf[32] = {0};

    if ( argc < 2 ) {
        printf( "Usage:%s <fifo name>\n", argv[0] );
        return -1;
    } // if

    // 先判斷是否已經有fifo文件
    if ( access( argv[1], F_OK ) == -1 ) {
        // 創建一個fifo文件，權限是666，不過也需要跟umask做邏輯運算
        ret = mkfifo( argv[1], 0666 );
        if ( ret == -1 ) {
            printf( "mkfifo error!\n" );
            return -2;
        } // if

        printf( "mkfifo sucess!\n" );
    } // if


    // 開啟該fifo文件
    fd = open( argv[1], O_RDONLY );

    // 每過一秒往fifo讀32bytes的數據
    while ( 1 ) {
        sleep( 1 );
        read( fd, buf, 32 );
        printf( "buf is %s\n", buf );

        // 清空buf
        memset( buf, 0, sizeof( buf ) );
    } // while


    close( fd );
    return 0;
} // int