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


    ret = read( fd, buf, 32 );

    printf( "ret is %d\n", ret );
    printf( "buf is %s\n", buf );

    // 第二個參數為相對位置，第三個參數有三種macro
    // SEEK_SET代表文件開頭
    // SEEK_CUR代表文件當前位置
    // SEEK_END代表文件最末位
    // 所以下面這行代表相對於文件開頭移動0，也就是移動到文件開頭
    // 若要向前用負數即可
    // 回傳值為文件目前位移多少，可以用lseek( fd, 0, SEEK_END )來判斷文件有多少bytes
    lseek( fd, 0, SEEK_SET );


    ret = read( fd, buf, 32 );

    printf( "ret is %d\n", ret );
    printf( "buf is %s\n", buf );


    close( fd );
    return 0;
} // int