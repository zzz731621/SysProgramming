#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void myfun( int sig ) {
    if ( sig == SIGINT ) {
        printf( "get signal\n" );
    } // if
} // void

int main( int argc, char *argv[] ) {
    // signal函數有兩個參數，可以決定某個信號的處理方式
    // 第一個是信號種類
    // 第二個是函數指標代表處理方式，分別有
    // SIG_IGN代表忽略
    // SIG_DFL代表默認，大部分是終止process
    // 也可以自定義處理方式

    // signal( SIGINT, SIG_IGN );
    // signal( SIGINT, SIG_DFL );
    signal( SIGINT, myfun );


    // process若要接收訊號，就要讓它持續執行
    // 可以使用無窮迴圈、sleep或是pause
    while ( 1 ) {
        sleep( 1 );
        printf( "wait signal\n" );
    } // while

    return 0;
} // int