#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

int main( int argc, char *argv[] ) {
    pid_t pid;
    int a;
    // 無名管道只能使用在有親緣關係的process
    // 因為fork出來的process採用Copy-on-write所以他們共用同一個記憶體空間
    // 這樣才能確保他們使用的是同一個fd
    int fd[2];
    pipe( fd );

    char buf[32] = {0};


    pid = fork();

    // 若創建失敗則回傳-1
    if ( pid < 0 ) {
        printf( "fork error" );
    } // if


    // 在parent process中會回傳children process的pid
    if ( pid > 0 ) {
        int status;
        printf( "fd[0] is %d\n", fd[0] );
        printf( "fd[1] is %d\n", fd[1] );


        
        // 對無名管道寫入數據不會觸發Copy-on-write，數據會被傳送到kernel中的buffer，而不是對副本進行操作
        write( fd[1], "Hello", 5 );

        wait( &status );


        close( fd[1] );
        exit( 0 );
    } // if
    

    // 在children process中會回傳0
    if ( pid == 0 ) {
        // 若無名管道中沒有數據，就會變成blocked的狀態
        // 若有數據，則讀完就會刪除
        read( fd[0], buf, 1 );
        printf( "buf is %s\n", buf );

        close( fd[0] );
        exit( 0 );
    } // if

    return 0;
} // int