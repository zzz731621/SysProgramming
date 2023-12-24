#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    
    int fd;

    // 往stdout寫數據，會印出hello
    write( 1, "hello\n", 6 );



    // 往a.c文件寫數據
    // 必須要注意權限，若沒有可寫權限，將無法寫入數據
    fd = open( "a.c", O_CREAT | O_RDWR, 0666 );
    if ( fd == -1 ) {
        perror( "open file error!\n" );
    } // if
    printf( "fd is : %d\n", fd );
    // 跟read一樣，成功會回傳實際寫入多少bytes，失敗則回傳-1
    write( fd, "hello\n", 6 );


    close( fd );
    return 0;
} // int