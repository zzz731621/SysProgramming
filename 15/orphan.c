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
        printf( "This is parent, parent pid is : %d\n", getpid() );
    } // if
    

    // 在children process中
    // 會回傳0
    if ( pid == 0 ) {
        // children process等2秒，等parent process結束後
        // 再印出children process的parent process的PID
        // 則此children process就會變成所謂的orphan process
        // 他會被init process接管，ppid有可能為1或其他
        sleep( 2 );
        printf( "parent pid is : %d\n", getppid() );
    } // if



    return 0;
} // int