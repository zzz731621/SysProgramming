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
    int i = 0;



    pid = fork();

    // 若創建失敗則回傳-1
    if ( pid < 0 ) {
        printf( "fork error" );
    } // if


    // 在parent process中
    // 會回傳children process的pid
    if ( pid > 0 ) {
        int status;
        wait( &status );

        // 若children process是正常退出，WIFEXITED就會回傳true
        if ( WIFEXITED( status ) == 1 ) {

            // WEXITSTATUS回傳的值則是children process調用的exit()內的數字，若沒有調用exit，系統默認執行exit(0)
            printf( "return value is %d\n", WEXITSTATUS( status ) );
        } // if
            
    } // if
    

    // 在children process中
    // 會回傳0
    if ( pid == 0 ) {
        sleep( 2 );
        printf( "This is children\n" );
        exit( 5 );
    } // if



    return 0;
} // int