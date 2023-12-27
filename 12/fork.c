#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main( int argc, char *argv[] ) {
    pid_t pid;
    int a = 0;
    pid = fork();
    // fork出的children process會從這以下執行
    // children process和parent process是採用Copy-on-write的策略
    // 意思是如果有一方要對變數a修改時，會複製一個副本來保存修改後的值
    // 之後要使用變數a的話，實際上都是使用變數a的那個副本

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
        printf( "This is children, children pid is : %d, parent pid is : %d\n", getpid(), getppid() );
    } // if


    return 0;
} // int