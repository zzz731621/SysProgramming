#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    
    int fd;
    char buf[32] = {0};
    int ret;


    // 從a.c文件讀數據
    fd = open( "a.c", O_CREAT | O_RDONLY, 0666 );
    if ( fd == -1 ) {
        perror( "open file error!\n" );
    } // if
    printf( "fd is : %d\n", fd );

    // 第二個參數為緩衝，第三個為要讀入多少bytes
    // 成功的話會回傳實際讀到多少個bytes，失敗則-1
    // 若讀完則回傳0
    ret = read( fd, buf, 32 );

    printf( "ret is %d\n", ret );
    printf( "buf is %s\n", buf );

    close( fd );
    return 0;
} // int