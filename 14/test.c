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
    // fork出的children process會從這以下執行，跟parent process擁有不一樣的記憶體空間

    // 若創建失敗則回傳-1
    if ( pid < 0 ) {
        printf( "fork error" );
    } // if


    // 在parent process中
    // 會回傳children process的pid
    if ( pid > 0 ) {
        printf( "This is parent, parent pid is : %d\n", getpid() );
        printf( "%d\n", pid );
    } // if
    

    // 在children process中
    // 會回傳0
    if ( pid == 0 ) {
        // 使用ps aux命令可以查看所有process的狀態
        // 配合| grep xxx，可以查看指定process


        // 讓children process持續print
        // 之後在命令行輸入kill -9 PID號
        // 可以強制終止該process
        while ( 1 )
            printf( "This is children, children pid is : %d, parent pid is : %d\n", getpid(), getppid() );

    } // if



    return 0;
} // int