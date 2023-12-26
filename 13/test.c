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
        printf( "This is children, children pid is : %d, parent pid is : %d\n", getpid(), getppid() );
        // 使用該函數可以調用可執行程式，調用失敗就會執行下一行的exit來退出
        // 若調用成功則執行該可執行程式，這樣就不會執行下一行的exit
        // 第一個參數是程式所在路徑，第二個參數是程式名稱，第三個是要傳入的參數
        // 通過這個函數也可以執行命令行的指令，因為命令行的指令實際上也是一個可執行文件，在/bin底下的
        // execl( "/home/eric/work/linux/13/hello", "hello", NULL );
        execl( "/bin/ls", "ls", NULL );
        exit(1);
    } // if



    return 0;
} // int