#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main( int argc, char *argv[] ) {
    pid_t pid;
    int i = 0;



    pid = fork();

    // 若創建失敗則回傳-1
    if ( pid < 0 ) {
        printf( "fork error" );
    } // if


    // 在parent process中
    // 會回傳children process的pid
    if ( pid > 0 ) {
        // 讓parent process一直運行，使他無法去釋放children process的資源
        // 這樣他的children process就會變成zombie process
        // 可以使用之前的ps aux去查看狀態為Z+的process
        printf( "This is parent, parent pid is : %d\n", getpid() );
        while ( 1 );
    } // if
    

    // 在children process中
    // 會回傳0
    if ( pid == 0 ) {
        // 讓children process先結束
        printf( "This is children, children pid is : %d\n", getpid() );
        exit( 0 );
    } // if



    return 0;
} // int